<template>
  <div class="home">
    <h1>최신 영화 목록을 확인하세요!</h1>
    <br>
    <h1>랜덤으로 영화를 추천받으세요!</h1>
    <br>
    <h1>선택한 영화를 저장하세요!</h1>
  </div>
</template>

<script>
// @ is an alias to /src
export default {
  name: 'HomeView',
  components: {
  }
}
</script>

<style>
.home {
  display: flex;
  flex-direction: column;
  align-items: center;
  justify-content: center;
}
</style>