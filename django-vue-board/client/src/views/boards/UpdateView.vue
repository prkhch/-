<template>
  <div>
    <AppLoading v-if="isLoading"/>
    <div v-else>
      <AppUsername/>
      <AppLogout/>
      <ArrowBack :arrowBackRouteName="arrowBackRouteName"/>
      <h1>글 수정</h1>
      <div class="form-floating">
        <input type="text"
        class="form-control"
        id="article-title"
        placeholder="article title"
        v-model="title"/>
        <label for="article-title">글 제목</label>
      </div>
      <div class="form-floating">
        <textarea class-="form-control" 
        placeholder="Leave a comment here" 
        id="article-description" 
        v-model="description"></textarea>
      </div>
      <button type="button" class="btn btn-warning" @click="updateArticle">수정</button>
    </div>
  </div>
</template>

<script>
import axios from "axios"
import AppLoading from "@/components/common/AppLoading.vue"
import AppUsername from "@/components/common/AppUsername.vue"
import AppLogout from "@/components/common/AppLogout.vue"
import ArrowBack from "@/components/common/ArrowBack.vue"

export default {
  components : { AppLoading, AppUsername, AppLogout, ArrowBack },
  data() {
    return {
      isLoading : true,
      title : "",
      description : "",
      arrowBackRouteName : "board",
    }
  },
  created() {
    if(this.$store.state.key == "") {
      alert("로그인 후 이용하세요.")
      this.$router.push({name:"home"})
    }
    axios
      .get(
        `${this.$store.state.URL}/api/v1/articles/${this.$route.params.id}/`,
        {headers:{Authorization:`Token ${this.$store.state.key}`}}
      )
      .then((response) => {
        if(response.status === 200) {
          this.title = response.data.title;
          this.description = response.data.description;
          this.isLoading = false;
        }
      })
      .catch((error) => console.error(error))
  },
  methods: {
    updateArticle() {
      if(this.title.length && this.description.length) {
        axios
          .put(
            `${this.$store.state.URL}/api/v1/articles/${this.$route.params.id}/`,
            {title : this.title, description: this.description},
            {headers: {Authorization : `Token ${this.$store.state.key}` }}
          )
          .then((response) => {
            if(response.status === 200) {
              alert("글 수정 성공")
              this.$router.push({
                name: "detail",
                params: {id:this.$route.params.id},
              })
            }
          })
          .catch((error) => { console.error(error)})
      }
      else {
        alert("입력 값이 충분하지 않습니다.")
      }
    }
  }
}
</script>

<style scoped>
#article-description {
  height: 12rem;
}
</style>