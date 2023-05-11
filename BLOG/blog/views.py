from django.shortcuts import redirect, render
from django.views.generic import ListView, DetailView, TemplateView
from django.views.generic.dates import ArchiveIndexView, YearArchiveView, MonthArchiveView
from django.views.generic.dates import DayArchiveView, TodayArchiveView
from django.views.generic import FormView

from django.conf import settings
from django.db.models import Q

from blog.models import Post, Comment
from blog.forms import CommentForm, PostSearchForm

from django.views.generic import CreateView, UpdateView, DeleteView
from django.contrib.auth.mixins import LoginRequiredMixin
from django.urls import reverse_lazy
from IDHP.views import OwnerOnlyMixin

from django.contrib import messages

# Create your views here.

# ListView
class PostLV(ListView) :
    model = Post
    template_name = 'blog/post_all.html'
    context_object_name = 'posts'
    paginate_by = 5

# DetailView
class PostDV(DetailView) :
    model = Post

    def get_context_data(self, **kwargs) :
        context = super(PostDV, self).get_context_data(**kwargs)
        context['comments'] = Comment.objects.filter(post=self.object)
        context['comment_form'] = CommentForm()

        return context
    
# ArchiveView
class PostAV(ArchiveIndexView) :
    model = Post
    date_field = 'create_dt'

class PostYAV(YearArchiveView) :
    model = Post
    date_field = 'create_dt'
    make_object_list = True
    #month_format = '%b'

class PostMAV(MonthArchiveView) :
    model = Post
    date_field = 'create_dt'

class PostDAV(DayArchiveView) :
    model = Post
    date_field = 'create_dt'

class PostTAV(TodayArchiveView) :
    model = Post
    date_field = 'create_dt'

class TagCloudTV(TemplateView) :
    template_name = 'taggit/taggit_cloud.html'

class TaggedObjectLV(ListView) :
    template_name = 'taggit/taggit_post_list.html'
    model = Post

    def get_queryset(self) :
        return Post.objects.filter(tags__name=self.kwargs.get('tag'))
    
    def get_context_data(self, **kwargs) :
        context = super().get_context_data(**kwargs)
        context['tagname'] = self.kwargs['tag']
        return context

# CRUD
class PostCreateView(LoginRequiredMixin, CreateView) :
    model = Post
    fields = ['title','slug', 'description', 'tags']
    success_url = reverse_lazy('blog:index')
    
    def form_valid(self, form) :
        form.instance.owner = self.request.user
        return super().form_valid(form)

class PostUpdateView(OwnerOnlyMixin,UpdateView):
    model = Post
    fields = ['title', 'slug', 'description', 'tags']
    success_url = reverse_lazy('blog:index')

class PostDeleteView(OwnerOnlyMixin, DeleteView) :
    model = Post
    success_url = reverse_lazy('blog:index')

class SearchFormView(FormView) :
    form_class = PostSearchForm
    template_name = 'blog/post_search.html'

    def form_valid(self, form) :
        searchWord = form.cleaned_data['search_word']
        post_list = Post.objects.filter(Q(title__icontains=searchWord) | Q(description__icontains=searchWord) | Q(content__icontains=searchWord)).distinct()

        context = {}
        context['form'] = form
        context['search_term'] = searchWord
        context['object_list'] = post_list

        return render(self.request, self.template_name, context)

def comments_create(request, pk) :
    post = Post.objects.get(pk=pk)
    comment_form = CommentForm(request.POST)
    if comment_form.is_valid() :
        comment = comment_form.save(commit=False)
        comment.post = post
        comment.save()

    return redirect('blog:post_detail', post.slug) 

def comments_delete(request, post_pk, comment_pk) :
    post = Post.objects.get(pk=post_pk)
    comment = Comment.objects.get(pk=comment_pk)
    if comment.password==request.POST['input_pwd'] : # 입력 비밀번호와 같을 때만 삭제
        comment.delete()
        message = messages.add_message(request, messages.INFO, '댓글을 삭제했습니다.')
    else :
        message = messages.add_message(request, messages.INFO, '※ 비밀번호를 확인해주세요!')
    return redirect('blog:post_detail', post.slug)