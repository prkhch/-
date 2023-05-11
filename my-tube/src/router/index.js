import Vue from 'vue'
import VueRouter from 'vue-router'
import HomeView from '../views/HomeView.vue'
import SearchView from '../views/SearchView.vue'
import LaterView from '../views/LaterView.vue'
import DetailView from '../views/DetailView.vue'

Vue.use(VueRouter)

const routes = [
  {
    path: '/',
    name: 'home', // name의 용도는?
    component: HomeView
  },
  {
    path : '/search',
    name : 'search',
    component : SearchView,
  },
  {
    path : '/later',
    name : 'later',
    component : LaterView,
  },
  {
    path : '/videos/:videoId', // path는 App.vue의 라우트링크와 관련이 있나?
    name : 'detail',
    component : DetailView,
  },
];

const router = new VueRouter({
  mode: 'history',
  base: process.env.BASE_URL,
  routes,
})

export default router
