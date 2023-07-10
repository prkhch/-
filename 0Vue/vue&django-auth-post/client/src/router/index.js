import Vue from 'vue'
import VueRouter from 'vue-router'
import HomeView from '../views/accounts/HomeView.vue'
import SignupView from '../views/accounts/SignupView.vue'
import BoardView from '../views/boards/BoardView.vue'
import DetailView from '../views/boards/DetailView.vue'
import CreateView from '../views/boards/CreateView.vue'
import UpdateView from '../views/boards/UpdateView.vue'

Vue.use(VueRouter)

const routes = [
  {
    path: '/',
    name: 'home',
    component: HomeView
  },
  {
    path: '/signup',
    name: 'signup',
    component: SignupView
  },
  {
    path: '/board',
    name: 'board',
    component: BoardView
  },
  {
    path: '/board/:id',
    name: 'detail',
    component: DetailView
  },
  {
    path: '/create',
    name: 'create',
    component: CreateView
  },
  {
    path: '/update/:id',
    name: 'update',
    component: UpdateView
  },
]

const router = new VueRouter({
  mode: 'history',
  base: process.env.BASE_URL,
  routes
})

export default router
