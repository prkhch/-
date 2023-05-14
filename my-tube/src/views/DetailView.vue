<template>
  <div class="detail-view">
    <LoadingSpinner v-if="isLoading" />
    <div v-else>
      <ArrowBack />
      <h1>{{title}}</h1>
      <div class="upload-date">업로드 날짜 : {{ publishedAt }}</div>
      <iframe width="560" height="315" :src="videoSrc" title="YouTube video player" frameborder="0"
              allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share"
              autofullscreen>
      </iframe>
      <p class="description">{{description}}</p>
    </div>
  </div>
</template>

<script>
import axios from 'axios';
import dayjs from 'dayjs';
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
  },
  created() {
    this.$store.dispatch("changeLoading", true);
    axios
      .get(`${this.$store.state.URL}/videos`, {
        params : {
          key : this.$store.state.KEY,
          part : "snippet",
          id : this.$route.params.videoId,
        }
      })
      .then((response) => {
        const item = response.data.items[0];
        this.video = {
          videoId : item.id,
          title : item.snippet.title,
          description : item.snippet.description,
          publishedAt : dayjs(item.snippet.publishedAt).format("YYYY-MM-DD"),
        };
        this.$store.dispatch("changeLoading", false);
      })
      .catch((error) => {
        console.log(error);
      })
  }
}
</script>

<style scoped>
.loading-icon-container {
  height: 80vh;
  width: 100vw;
  display: flex;
  justify-content: center;
  align-items: center;
}
h1 {
  margin-top: 20px;
  margin-bottom: 20px;
  font-weight: bold;
}
.upload-date {
  margin-bottom: 20px;
}
.description {
  margin-top: 20px;
}
</style>