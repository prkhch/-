<template>
  <div>
    <AppLoading v-if="isLoading"/>
    <div v-else>
      <AppUsername/>
      <AppLogout/>
      <!-- data()에서 뒤로가기 라우트 이름의 값과 연결-->
      <ArrowBack :arrowBackRouteName = "arrowBackRouteName"/>
      <!-- 게시글, 작성자확인 정보 전달, DetailArticle(자식)에서 @deleteArticle실행 시 DetailView(부모)의 deleteArticle실행 -->
      <DetailArticle
        :article="article"
        :isArticleUser="isArticleUser"
        @deleteArticle="deleteArticle"
      />
      <hr/>
      <!-- 댓글 정보 전달, DetailComments에서 @deleteComment실행 시 deleteComment실행 -->
      <DetailComments
        :comments="article.comments"
        @deleteComment="deleteComment"
      />
      <hr/>
      <!-- CommentInput(자식)에서 작성한 코멘트와 함께 부모의 createComment호출 -->
      <CommentInput @createComment="createComment"/>
    </div>
  </div>
</template>

<script>
import axios from "axios"
import AppUsername from "@/components/common/AppUsername.vue" // 이름
import AppLoading from "@/components/common/AppLoading.vue" // 로딩
import AppLogout from "@/components/common/AppLogout.vue" // 로그아웃
import ArrowBack from "@/components/common/ArrowBack.vue" // 뒤로가기
import DetailArticle from "@/components/boards/detail/DetailArticle.vue" // 게시글
import DetailComments from "@/components/boards/detail/DetailComments.vue" // 댓글 목록
import CommentInput from "@/components/boards/detail/CommentInput.vue" // 댓글 입력창

export default {
  components : {
    AppUsername,
    AppLoading,
    AppLogout,
    ArrowBack,
    DetailArticle,
    DetailComments,
    CommentInput,
  },
  data() { // 데이터 초기 상태
    return {
      isLoading : true, // 로딩중
      isArticleUser : false, // 작성자 : 없음
      arrowBackRouteName : "board", // 뒤로가기는 게시판으로 이동
      article : {}, // 게시글은 빈 상태
    }
  },
  created() { // 인스턴스 생성되었을 때
    axios
      .get( // get(백엔드API, 토큰)
        // 라우트 매개변수 id를 사용하여 백엔드 API호출
        `${this.$store.state.URL}/api/v1/articles/${this.$route.params.id}/`,
        {
          headers: {
            Authorization : `Token ${this.$store.state.key}`,
          },
        }
      )
      .then((response) => { // 응답
        if(response.status === 200) { 
          this.article = response.data; // 응답데이터=>게시글
          if(this.article.user.username === this.$store.state.username) { // 게시글 작성자 === 현재 유저
            this.isArticleUser = true; // 작성자 확인 true
          }
          this.isLoading = false;
        }
      })
      .catch((error) => {
        console.error(error);
        if(error.response.status === 401) {
          alert("로그인 후 이용하세요.")
          this.$router.push({name:"home"})
        }
      })
  },
  methods : {
    getAllData() { // 게시글 모든 데이터
      axios
        .get(
          `${this.$store.state.URL}/api/v1/articles/${this.$route.params.id}/`,
          {
            headers : {
              Authorization : `Token ${this.$store.state.key}`,
            }
          }
        )
        .then((response) => {
          if(response.status === 200) {
            this.article = response.data;
          }
        })
        .catch((error) => {
          console.error(error);
        })
    },
    createComment(content) { // 댓글 작성
      axios
        .post(
          `${this.$store.state.URL}/api/v1/articles/${this.$route.params.id}/comments/`,
          {content : content},
          {headers : {Authorization: `Token ${this.$store.state.key}`}}
        )
        .then((response) => {
          this.content="";
          if(response.status===201) {
            this.getAllData();
          }
        })
        .catch((error) => {
          console.error(error);
        })
    },
    deleteArticle() { // 게시글 삭제
      axios
        .delete(
          `${this.$store.state.URL}/api/v1/articles/${this.$route.params.id}/`,
          {headers: {Authorization:`Token ${this.$store.state.key}`}}
        )
        .then((response) => {
          if(response.status === 204) {
            alert("글 삭제 성공")
            this.$router.push({name:"board"}); 
          }
        })
        .catch((error) => {
          console.error(error)
        })
    },
    deleteComment(id) { // 댓글 삭제
      axios
        .delete(
          `${this.$store.state.URL}/api/v1/comments/${id}/`, 
          {headers : {Authorization : `Token ${this.$store.state.key}`}}
          )
        .then((response) => { 
          if(response.status === 204) {
            this.getAllData();
          }
        })
        .catch((error) => console.error(error))
    }
  }
}
</script>