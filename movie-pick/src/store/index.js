import Vue from 'vue'
import Vuex from 'vuex'

Vue.use(Vuex)


export default new Vuex.Store({
  state: {
    watchList: []
  },
  getters: {
    getWatchList(state) {
      return state.watchList;
    }
  },
  mutations: {
    addToWatchList(state, movie) {
      state.watchList.push(movie);
    },
    delMovie(state, movie) {
      state.watchList = state.watchList.filter(m => m !== movie);
    },
    setWatchList(state, watchList) {
      state.watchList = watchList;
      localStorage.setItem('watchList', JSON.stringify(watchList));
    },
    resetWatchList(state) {
      state.watchList = [];
    }
  },
  actions: {
  },
  methods: {
  },
  modules: {
  }
})
