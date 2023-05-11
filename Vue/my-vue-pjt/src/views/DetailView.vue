<template>
  <div>
    <h1>Detail</h1>
    <h2>'{{videoId}}' 의 디테일 페이지입니다.</h2>
  </div>
</template>

<script>
export default {
  computed : {
    videoId() {
      return this.$route.params.videoId;
    }
  }
}
</script>