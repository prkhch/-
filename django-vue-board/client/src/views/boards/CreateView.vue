<template>
  <div>
    <AppUsername/>
    <AppLogout/>
    <ArrowBack :arrowBackRouteName="arrowBackRouteName"/>
    <h1>새 글 작성</h1>
    <div class="form-floating">
      <input type="text"
      class="form-control"
      id="article-title"
      placeholder="article title"
      v-model="title"/>
      <label for="article-title">글 제목</label>
    </div>
    <div class="form-floating">
      <textarea class-="form-control" placeholder="Leave a comment here" id="article-description" v-model="description"></textarea>
    </div>
    <button type="button" class="btn btn-primary" @click="createArticle">업로드</button>
  </div>
</template>

<script>
import axios from "axios"
import AppUsername from "@/components/common/AppUsername.vue"
import AppLogout from "@/components/common/AppLogout.vue"
import ArrowBack from "@/components/common/ArrowBack.vue"

export default {
  components : { AppUsername, AppLogout, ArrowBack },
  data() {
    return {
      title : "",
      description : "",
      arrowBackRouteName : "board", // 게시판으로 뒤로가기
    }
  },
  created() {
    if(this.$store.state.key==="") { // 로그인 되어 있지 않으면
      alert("로그인 후 이용하세요.")
      this.$router.push({name:"home"})
    }
  },
  methods : {
    createArticle() {
      if(this.title.length && this.description.length) { // v-model의 title, description이 1이상 (=값이 있으면)
        axios
          .post(
            `${this.$store.state.URL}/api/v1/articles/`, // 벡엔드로 보내기 해당 글
            {title: this.title, description:this.description},
            {headers : {Authorization: `Token ${this.$store.state.key}`}}
          )
          .then((response) => {
            if(response.status === 201) {
              alert("글 작성 성공")
              this.$router.push({name:"board"})
            }
          })
          .catch((error) => {
            console.error(error);
          })
      } else {
        alert("입력값이 충분하지 않습니다.")
      }
    }
  }
}
</script>

<style scoped>
#article-description{
  height: 12rem;
}
</style>