<template>
  <div>
    <ul>
      <li v-for="movie in watchList" :key="movie.id">
        <img :src="getImageUrl(movie.poster_path)" alt="Movie Poster" width="100">
        <span>{{ movie.title }}</span>
      </li>
    </ul>
  </div>
</template>

<script>
export default {
  computed: {
    watchList() {
      return this.$store.state.watchList;
    }
  },
  methods : {
    getImageUrl(posterPath) {
      const baseUrl = 'https://image.tmdb.org/t/p/';
      const size = 'w500';
      return `${baseUrl}${size}${posterPath}`;
    }
  }
};
</script>