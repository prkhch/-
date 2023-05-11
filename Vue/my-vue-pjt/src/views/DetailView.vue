<template>
  <div class="detail-view">
    <LoadingSpinner v-if="isLoading" />
    <div v-else>
      <ArrowBack />
      <h1>{{title}}</h1>
      <div class="upload-date">업로드 날짜 : {{ publishedAt }}</div>
    </div>
  </div>
</template>

<script>
import ArrowBack from "@/components/common/ArrowBack.vue";
import LoadingSpinner from "@/components/common/LoadingSpinner.vue";

export default {
  components : {
    ArrowBack,
    LoadingSpinner,
  },
  data() {
    return {
      video : {},
    }
  },
  computed : {
   isLoading() {
    return this.$store.state.loading;
   },
   title() {
    return this.video.title;
   },
   videoSrc() {
    return `https://www.youtube.com/embed/${this.video.videoId}?autoplay=1`;
   },
   description() {
    return this.video.description;
   },
   publishedAt() {
    return this.video.publishedAt;
   }
  }
}
</script>