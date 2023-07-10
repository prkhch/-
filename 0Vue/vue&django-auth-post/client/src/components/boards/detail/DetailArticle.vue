<template>
  <div>
    <!-- article은 DetailView에서 created()될 때 생김 -->
    <div>글번호 : {{article.id}}</div>
    <div>제목 : {{article.title}}</div>
    <div>작성자 : {{article.user.name}}</div>
    <div>작성시간 : {{parseDate(article.created_at)}}</div>
    <div>수정시간 : {{parseDate(article.updated_at)}}</div>
    <hr/>
    <p>{{article.description}}</p>
    <!-- 본인이 작성자라면 -->
    <div v-if="isArticleUser"> 
      <!-- 업데이트 버튼 -->
      <!-- update로 이동하는 (게시글 id 인자와 함께) -->
      <router-link :to="{name:'update', params: ({id:article.id}) }">
        <button type="button" class="btn btn-warning">글 수정</button>
      </router-link>
      <!-- 삭제 버튼 -->
      <button type="button" class="btn btn-danger" @click="deleteArticle">글 삭제</button>
    </div>
  </div>
</template>

<script>
import dayjs from "dayjs";

export default {
  props : { // 부모에게서 받아올 속성, 그 속성의 타입 명시(오류 사전 방지)
    isArticleUser : Boolean,
    article : {
      id : Number,
      title : String,
      user : {
        username : String,
      },
      created_at : String,
      updated_at : String,
      description : String,
    }
  },
  methods : {
    parseDate(rawDate) { // 날짜 형식 변환
      return dayjs(rawDate).format("YYYY-MM-DD HH:mm:ss")
    },
    deleteArticle() { 
      this.$emit("deleteArticle") // 부모 DetailView의 deleteArticle호출
    },
  }
}
</script>