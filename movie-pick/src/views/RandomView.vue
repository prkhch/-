<template>
  <div class="random-view">

    <button type="button" class="btn btn-dark" v-on:click="pickMovie">PICK</button>
    <div v-if="randomMovie">
      <div class="card">
        <img :src="getImageUrl(randomMovie.poster_path)" :alt="randomMovie.title" class="card-img-top"/>
        <div class="card-body text-center">
          <h2>{{ randomMovie.title }}</h2>
        </div>
      </div>
    </div>

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
  created() {
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
      const url = `https://api.themoviedb.org/3/movie/top_rated?api_key=${apiKey}&language=ko-KR&page=1`
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
        const randomIndex = Math.floor(Math.random() * this.movies.length);
        this.randomMovie = this.movies[randomIndex];
      }
    },
    pickMovie() {
      this.$store.commit('addToWatchList', this.randomMovie);
      const watchList = JSON.parse(localStorage.getItem('watchList')) || [];
      watchList.push(this.randomMovie);
      localStorage.setItem('watchList', JSON.stringify(watchList));
    }
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
  width: 500px;
  border: 1px black solid;
}

.card-body {
  border: 1px black solid;
}


</style>