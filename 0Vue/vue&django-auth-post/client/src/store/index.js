import Vue from 'vue'
import Vuex from 'vuex'
import axios from 'axios';

Vue.use(Vuex)

export default new Vuex.Store({
  state: {
    URL: "http://localhost:8000", // 백엔드
    key: "",
    username : "",
  },
  getters: {
  },
  mutations: {
    CHANGE_KEY(state, newKey) { // 키변경 (isToken???)
      state.key = newKey;
    },
    CHANGE_USERNAME(state, newUsername) { // 이름변경
      state.username = newUsername;
    }
  },
  actions: {
    login(context, userInput) { //로그인
      return axios
        .post(`${context.state.URL}/accounts/login/`, userInput) // post 메서드 요청(+ 입력)
        .then((response) => {
          if(response.status===200) { // 성공
            context.commit("CHANGE_KEY", response.data.key); // mutations을 호출하여 상태변경
            context.commit("CHANGE_USERNAME", userInput.username);
            return true;
          }
        })
        .catch((error) => { // 에러 발생
          console.error(error);
          return false;
        })
    },
    logout(context) { // 로그아웃
      return axios
        .post( // post 메서드 요청(+ 토큰)
          `${context.state.URL}/accounts/logout/`,
          `Token ${context.state.key}`
        )
        .then((response) => {
          if(response.status===200) { // 성공
            context.commit("CHANGE_KEY",""); // mutations을 호출하여 키 제거
            return true;
          }
        })
        .catch((error) => {
          console.error(error);
          return false;
        })
    },
  },
  modules: {
  }
})
