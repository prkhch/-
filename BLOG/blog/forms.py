from django import forms
from blog.models import Comment

class PostSearchForm(forms.Form) :
    search_word = forms.CharField(label='검색어 ')

class CommentForm(forms.ModelForm):
    
    name = forms.CharField(
        max_length=10,
        label= '',
        widget=forms.TextInput(
            attrs={
                'placeholder' : ' 작성자',
                'style' : 'border-radius: 5px; margin-bottom:5px; width:120px;',
            }
        )
    )

    password = forms.CharField(
        max_length=20,
        label= '',
        widget=forms.PasswordInput(
            attrs={
                'placeholder' : ' 비밀번호',
                'style' : 'border-radius: 5px; margin-bottom:5px;',
            }
        )
    )

    content = forms.CharField(
        max_length=500,
        label = '',
        widget=forms.Textarea(
            attrs={
            'placeholder' : ' 댓글을 입력하세요.',
            'rows' : 5,
            'cols' : 64,
            'style' : 'border-radius: 5px;'
            }
        )
    )

    class Meta:
        model = Comment
        exclude = ('post',)

