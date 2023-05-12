<template>
  <div>
    
    <div class="cardgroup row row-cols-1 row-cols-md-3 g-4">

      <div class="col" v-for="movie in movies" :key="movie.id">
        <div class="card">
          <img :src="getImageUrl(movie.poster_path)" class="card-img-top border" alt="...">
          <div class="card-body border">
            <h5 class="text-center" style="font-weight:bold">{{ movie.title }}</h5>
            <h6 class="text-center" style="font-style:italic">{{movie.release_date}}</h6>
            <p>{{movie.overview}}</p>
          </div>
        </div>
      </div>

    </div>
 
  </div>
</template>

<script>
import axios from 'axios'

export default {
  data() {
    return {
      movies : []
    };
  },
  mounted() {
    this.fetchMovies();
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
      axios.get(url)
        .then((response) => {
          this.movies = response.data.results;
        })
        .catch((error) => {
          console.log(error);
        })
    },
  },
}
</script>

<style scoped>
/* p {
  line-height:2em;
} */

.card-img-top {
  height: 500px;
}

.card-body {
  height: 200px;
  white-space: normal;
  display: -webkit-box;
  -webkit-line-clamp: 7;
  -webkit-box-orient: vertical;
  overflow: hidden;
}

</style>