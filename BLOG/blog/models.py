from django.db import models
from django.urls import reverse
from taggit.managers import TaggableManager
from django.contrib.auth.models import User
from django.utils.text import slugify

from ckeditor_uploader.fields import RichTextUploadingField
from django.core.validators import MaxLengthValidator

# Create your models here.
class Post(models.Model) :
    title = models.CharField(verbose_name='제목', max_length=50)

    slug = models.SlugField('주소', unique=True, allow_unicode=True, help_text='')
    # description = models.CharField('내용', max_length=100, blank=True, help_text='simple description text.')
    content = models.TextField('내용')
    create_dt = models.DateTimeField('작성 시간', auto_now_add=True)
    modify_dt = models.DateTimeField('수정 시간', auto_now=True)
    tags = TaggableManager('태그', blank=True, help_text='')
    owner = models.ForeignKey(User, on_delete=models.CASCADE, verbose_name='OWNER', blank=True, null=True)
    description = RichTextUploadingField('', blank=True,null=True)
    
    class Meta :
        verbose_name = 'post'
        verbose_name_plural = 'posts'
        db_table = 'blog_posts'
        ordering = ('-create_dt',)

    def __str__(self) :
        return self.title
    
    def get_absolute_url(self) :
        return reverse('blog:post_detail', args=(self.slug,))
    
    def get_previous(self) :
        return self.get_previous_by_create_dt()
    
    def get_next(self) :
        return self.get_next_by_create_dt()
    
    def save(self, *args, **kwargs) :
        self.slug = slugify(self.title, allow_unicode=True)
        super().save(*args, **kwargs)

class Comment(models.Model) :
    
    post = models.ForeignKey(Post, on_delete=models.CASCADE, related_name='comments')
    name =  models.CharField(max_length=20)
    password = models.CharField('비밀번호', max_length=20)
    content = models.TextField('')
    create_dt = models.DateTimeField('작성 시간', auto_now_add=True)




