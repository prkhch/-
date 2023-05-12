<template>
  <div>
    
    <div class="cardgroup row row-cols-1 row-cols-md-3 g-4">

      <div class="col" v-for="movie in movies" :key="movie.id">
        <div class="card">
          <img :src="getImageUrl(movie.poster_path)" class="card-img-top" alt="...">
          <div class="card-body">
            <h5 class="card-title text-center">{{ movie.title }}</h5>
            <hr>
            <p :class="[isLargeScreen ? 'large-text' : '']">{{ getLimitedOverview(movie.overview)}}</p>
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
      const url = `https://api.themoviedb.org/3/movie/top_rated?api_key=${apiKey}&language=ko-KR&page=1`
      axios.get(url)
        .then((response) => {
          this.movies = response.data.results;
        })
        .catch((error) => {
          console.log(error);
        })
    },
    getLimitedOverview(overview) {
      const maxLength = 100;
      if(overview.length > maxLength) {
        return overview.substring(0, maxLength) + '...';
      }
      else {
        return overview;
      }
    }
  },
  computed: {
    isLargeScreen() {
      return window.innerWidth >= 1440; // 큰 화면인지 여부를 체크
    }
  }
}
</script>

<style scoped>
p {
  line-height:2em;
}

.card-img-top {
  height: auto;
}

.large-text {
  font-size: 16px; /* 작은 화면에서의 폰트 크기 */
  text-align: center;
}

@media (min-width: 768px) {
  .card-img-top {
    height: 400px;
  }
  .card-body {
  height: 300px;
  }
}
@media (min-width: 1280px) {
  .card-img-top {
    height: 500px;
  }
  .card-body {
  height: 450px;
  }
  .large-text {
    font-size: 25px; /* 작은 화면에서의 폰트 크기 */
  }
}

.cardgroup {
  width: 100%;
}



</style>