<template>
  <div>
    <h1>Welcome, {{username}}</h1>
  </div>
</template>

<script>
export default {
  computed: { // this.$store.state.username 값이 변경될 때마다 자동으로 다시 계산
    username() {
      return this.$store.state.username;
    },
  },
};
</script>