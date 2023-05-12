<template>
  <div class="random-view">
    <div v-if="randomMovie">
      <button type="button" class="btn btn-dark" v-on:click="pickMovie(); getRandomMovie();">PICK</button>
      <div class="card">
        <img :src="getImageUrl(randomMovie.poster_path)" :alt="randomMovie.title" class="card-img-top border"/>
        <div class="card-body text-center border">
          <h2>{{ randomMovie.title }}</h2>
        </div>
      </div>
    </div>
    <div v-else><h1>추천 영화가 없습니다.</h1></div>

    <button type="button" class="btn btn-dark" v-on:click="getRandomMovie"><i class="fa-sharp fa-solid fa-rotate-right" style="color: #ffffff;"></i></button>

  </div>
</template>


<script>
import axios from 'axios'

export default {
  data() {
    return {
      movies : [],
      randomMovie: null
    };
  },
  mounted() {
    this.fetchMovies()
      .then(()=> {
        this.getRandomMovie();
      })
  },
  methods: {
    getImageUrl(posterPath) {
      const baseUrl = 'https://image.tmdb.org/t/p/';
      const size = 'w500';
      return `${baseUrl}${size}${posterPath}`;
    },
    fetchMovies() {
      const apiKey = '8b1a427d0c951e52a5869304bde7a649';
      const url = `https://api.themoviedb.org/3/movie/upcoming?api_key=${apiKey}&language=ko-KR&page=1`
      return axios.get(url)
        .then((response) => {
          this.movies = response.data.results;
        })
        .catch((error) => {
          console.log(error);
        });
    },
    getRandomMovie() {
      if(this.movies.length > 0) {
        // 모든 영화 리스트
        const allMovies = this.movies; 

        // 로컬 스토리지의 watchList 가져오기
        const watchList = JSON.parse(localStorage.getItem('watchList')) || []; 

         // watch리스트에 없는 영화 저장
        const nonWatchedMovies = allMovies.filter(movie => !watchList.some(watchedMovie => watchedMovie.id === movie.id));

        // nonWathedMovies(본 적없는영화. 즉, 중복제거)의 영화중 랜덤으로 뽑기
        const randomMovie = nonWatchedMovies[Math.floor(Math.random() * nonWatchedMovies.length)];
        console.log(allMovies);
        console.log(watchList);
        console.log(nonWatchedMovies)
        console.log(randomMovie)
        this.randomMovie = randomMovie;
      }
    },
    pickMovie() {
      this.$store.commit('addToWatchList', this.randomMovie);
      const watchList = JSON.parse(localStorage.getItem('watchList')) || [];
      watchList.push(this.randomMovie);
      localStorage.setItem('watchList', JSON.stringify(watchList));
    },
  }
}
</script>

<style scoped>
.random-view {
  display: flex;
  flex-direction: column;
  align-items: center;
  justify-content: center;
}

.btn {
  width: 500px;
  font-size : 40px;
  margin: 10px;
}

.card-img-top {
  height: 700px;
  width: 520px;
}

.card {
  width: 520px;
}


</style>