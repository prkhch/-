<template>
  <div>
    <AppLoading v-if="isLoading"/>
    <div v-else>
      <AppUsername/>
      <AppLogout/>
      <h1>게시판</h1>
      <!-- BoardView에서 BoardList로 articles 전달 -->
      <BoardList :articles="articles" />
      <router-link :to="{name:'create'}">
        <button type="button" class="btn btn-primary">글쓰기</button>
      </router-link>
    </div>
  </div>
</template>

<script>
import axios from "axios";
import AppUsername from "@/components/common/AppUsername.vue"
import AppLoading from "@/components/common/AppLoading.vue"
import AppLogout from "@/components/common/AppLogout.vue"
import BoardList from "@/components/boards/board/BoardList.vue"

export default {
  components : {
    AppUsername, AppLoading, AppLogout, BoardList
  },
  data() {
    return {
      isLoading : true,
      articles:[],
    }
  },
  created() {
    axios
      .get(`${this.$store.state.URL}/api/v1/articles`, {
        headers : {
          Authorization : `Token ${this.$store.state.key}`, // 토큰 인증 필요
        },
      })
      .then((response) => { // 성공적인 응답
        if(response.status === 200) { // 그 상태가 200일때만 (201,204 등 다양한 코드가 존재)
          this.articles = response.data; // articles의 data를 articles에 넣기
          this.isLoading = false; // 로딩 상태 해제
        }
      })
      .catch((error) => {
        if(error.response.status === 401) { // 401 인증실패(ex.로그인 안했을 때)
          alert("로그인 후 이용하세요.")
          this.$router.push({name:"home"})
        }
        if(error.response.status === 404) { // 404 낫 파운드(ex. 게시글이 없을 때)
          this.isLoading = false;
        }
      }) 
  }
}
</script>