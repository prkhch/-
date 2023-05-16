<template>
  <div>
    <!-- data()에 content와 연결(v-model) -->
    <input type="text" class="form-control" v-model="content"/>
    <button type="button" class="btn btn-primary" @click="createComment">댓글 추가</button>
  </div>
</template>

<script>
export default {
  data() {
    return {
      content : "",
    }
  },
  methods : {
    createComment() {
      // content에 값이 있으면
      if(this.content.length) {
        this.$emit("createComment", this.content) // 부모 DetailView의 createComment호출(content와 함께)
        this.content = "";
      } else {
        alert("작성할 댓글 내용을 입력하세요.")
      }
    },
  },
}
</script>