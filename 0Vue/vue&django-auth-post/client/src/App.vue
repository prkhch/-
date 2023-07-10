<template>
  <div id="app">

    <main>
      <router-view/>
    </main>

    <footer>
      <AppFooter/>
    </footer>

  </div>
</template>

<script>
import AppFooter from "@/components/common/AppFooter.vue"
export default {
  components : {AppFooter},
}
</script>

<style>
* {
  font-family : "Noto Sans KR", sans-serif;
  list-style : none;
}
ul {
  padding-left : 0px;
}
#app {
  display : flex;
  /* 자식 요소를 수직으로 정렬 */
  flex-direction: column;
  height: 100vh;
}
main{
  /* 내용이 컨테이너의 세로 공간을 넘어갈 경우, 수직 스크롤바를 표시 */
  overflow-y : auto;
  /* 나머지 공간을 전부 차지 */
  flex-grow : 1;
}
</style>
