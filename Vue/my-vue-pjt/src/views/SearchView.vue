<template>
  <div>
    <ArrowBack/>
    <h1>비디오 검색</h1>
    <SearchInput/>
    <div v-if="isLoading">
      <LoadingSpinner/>
    </div>
    <SearchVideoList v-else />
  </div>
</template>

<script>
import SearchInput from "@/components/search/SearchInput.vue"
import SearchVideoList from "@/components/search/SearchVideoList.vue"
import ArrowBack from "@/components/common/ArrowBack.vue"
import LoadingSpinner from "@/components/common/LoadingSpinner.vue"

export default {
  components : {
    SearchInput,
    SearchVideoList,
    ArrowBack,
    LoadingSpinner
  },
  computed : {
    isLoading() {
      return this.$store.state.loading;
    },
  },
};
</script>