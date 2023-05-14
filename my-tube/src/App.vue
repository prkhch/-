<template>
  <div id="app">
    <AppNav/>
    <div class="page">
      <router-view/>
    </div>
  </div>
</template>

<script>
import AppNav from "@/components/common/AppNav.vue";
export default {
  components : {
    AppNav,
  },
}
</script>

<style>
#app {
  font-family: "Noto Sans KR", sans-serif;
}
ul {
  padding-left : 0;
  list-style : none;
}
.page {
  padding-top:3rem;
}
.search-view,
.later-view,
.detail-view {
  padding-left : 100px;
  padding-right : 100px;
}
.video-list-ul {
  display: flex;
  flex-direction: row;
  flex-wrap: wrap;
  justify-content: flex-start;
}
.video-list-li {
  margin-bottom: 30px;
  margin-left: 10px;
  margin-right: 10px;
}
.search-view,
.later-view,
.detail-view,
.loading-icon-container,
.video-list-ul {
  margin-top: 10px;
}
</style>
