<template>
  <div>
    <button type="button" class="btn btn-link" @click="logout">로그아웃</button>
  </div>
</template>

<script>
export default {
  methods: {
    logout() { // 로그아웃
      this.$store.dispatch("logout") // store's actions "logout" 호출
        .then((flag) => { // logout액션에 리턴 값에 따라
          if(flag) { // true면, 액션에서 키 제거됌. => 홈으로 이동
            this.$router.push({name:"home"}); 
          } else { // false는 => 에러 + 알림창
            alert("로그아웃 실패");
          }
        });
    }
  }
}
</script>