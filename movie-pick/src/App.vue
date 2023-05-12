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
};
</script>

<style>
#app {
  font-family: "Noto Sans KR", sans-serif;
}

ul {
padding-left: 0;
list-style: none;
}

.movie-view,
.random-view
 {
  padding : 100px;
}
</style>
