<template>
  <div>
    <nav class="navbar fixed-top navbar-expand-lg bg-primary border">
      <video class="navbar-video" src="@/assets/Network.mp4" autoplay loop muted></video>
      <div class="container-fluid">
        <router-link class="navbar-brand text-light" to="/">
        SSAFY
        </router-link>
        <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarNavAltMarkup" aria-controls="navbarNavAltMarkup" aria-expanded="false" aria-label="Toggle navigation">
          <span class="navbar-toggler-icon"></span>
        </button>
        <div class="collapse navbar-collapse" id="navbarNavAltMarkup">
          <div class="navbar-nav">
            <router-link class="nav-link" to="/movie">Movie</router-link>
            <router-link class="nav-link" to="/random">Random</router-link>
            <router-link class="nav-link" to="/watchlist">WatchList</router-link>
          </div>
        </div>
      </div>
    </nav>
  </div>
</template>

<script>
export default {
  
}
</script>

<style>
.navbar {
  position: relative;
  background-color: transparent;
  /* Navbar의 스타일 설정 */
}
.navbar-video {
  position: absolute;
  top: 0;
  left: 0;
  width: 100%;
  height: 100%;
  object-fit: cover;
  z-index: -1;
  /* 영상 요소의 스타일 설정 */
}

.nav-link{
  color : white;
}
.nav-link:hover,
.nav-link:focus{
  color : gray;
}
</style>