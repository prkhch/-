<template>
  <div>
    <ul class="video-list-ul">
      <li class="video-list-li" v-for="video in videoList" v-bind:key="video.videoId">
        <!-- v-bind 를 이용하여 동적인 prop을 전달 -->
        <EachVideo v-bind:video="video" /> 
      </li>  
    </ul>    
  </div>
</template>

<script>
import EachVideo from "@/components/common/EachVideo.vue"

export default {
  components: {
    EachVideo,
  },
  computed: {
    videoList() {
      return this.$store.state.videoList;
    }
  }
}
</script>