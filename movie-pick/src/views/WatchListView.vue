<template>
  <div class='watchlist-view'>
    <div class="cardgroup row row-cols-6 g-4">

      <div class="col" v-for="movie in watchList" :key="movie.id">
          <div class="card">
            <img :src="getImageUrl(movie.poster_path)" alt="Movie Poster" height="200px">
            <div class="title text-center border">
              {{ movie.title }}
            </div>
            <button type="button" class="btn btn-dark" v-on:click="delMovie(movie)">DELETE</button>
          </div>
      </div>
    </div>

    <button type="button" class="reset btn btn-dark text-danger" v-on:click="resetStore">RESET</button>

  </div>

  
</template>

<script>
export default {
  computed: {
    watchList() {
      return this.$store.getters.getWatchList;
    }
  },
  mounted() {
    const savedWatchList = JSON.parse(localStorage.getItem('watchList'));
    if (savedWatchList) {
      this.$store.commit('setWatchList', savedWatchList);
    }
  },
  methods : {
    getImageUrl(posterPath) {
      const baseUrl = 'https://image.tmdb.org/t/p/';
      const size = 'w500';
      return `${baseUrl}${size}${posterPath}`;
    },

    // state에서 지우고, 지운 정보를 다시 가져와서, 셋
    delMovie(movie) {
      this.$store.commit('delMovie', movie); // Vuex store에서 제거(화면 제거)
      const watchList = JSON.parse(localStorage.getItem('watchList')) || []; // 로컬 스토리지에 반영
      const updatedWatchList = watchList.filter((m) => m.id !== movie.id);
      localStorage.setItem('watchList', JSON.stringify(updatedWatchList));
    },
    resetStore() {
      this.$store.commit('resetWatchList'); // Vuex store에서 리셋 (화면 리셋)
      localStorage.removeItem('watchList'); // 로컬저장소 리셋
    }
  }
};
</script>

<style scoped>
.reset {
  float : right;
}

.title {
  height: 50px;
  display: flex;
  justify-content: center;
  align-items: center;
}
</style>