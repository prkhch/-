<template>
  <div>
    <ul v-if="articles.length">
      <li v-for="article in articles" :key="article.id">
        <div>글번호 : {{article.id}} </div>
        <div>
          제목 :
          <router-link :to="{ name: 'detail', params: ({id:article.id}) }">
            {{article.title}}
          </router-link>
        </div>
        <div>작성자 : {{article.user.username}}</div>
        <hr/>
      </li>
    </ul>
    <div v-else>게시글이 없습니다.</div>
  </div>
</template>

<script>
export default {
  props : {
    articles : Array,
  },
}
</script>