<template>
  <div>
    <!--  동적으로 라우트 이름을 지정 -->
    <router-link :to="{name:arrowBackRouteName}"> 
      <span class="arrow-back material-symbols-outlined">arrow_back</span>
    </router-link>
  </div>
</template>

<script>
export default {
  props: {
    arrowBackRouteName: String, // 부모컴포넌트로부터 전달받아 동적으로 경로 설정
  },
};
</script>

<style scoped>
.arrow-back{
  color: black;
}
</style>