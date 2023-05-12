import Vue from 'vue'
import Vuex from 'vuex'

Vue.use(Vuex)


export default new Vuex.Store({
  state: {
    watchList: []
  },
  getters: {
  },
  mutations: {
    addToWatchList(state, movie) {
      state.watchList.push(movie);
    }
  },
  actions: {
  },
  methods: {
  },
  modules: {
  }
})
