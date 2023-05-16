<template>
  <div>
    <div v-if="comments.length">
      <div>댓글 목록</div>
      <ul>
        <li v-for="(comment, index) in comments" :key="comment.id">
          {{ comment.content }} - {{ comment.user.username }}
          <!-- 현재 유저 === 코멘트 작성자라면 -->
          <span v-if="isCommentUser(index)">
            -
            <!-- 삭제 버튼 -->
            <button type="button" class="btn btn-danger" @click="deleteComment(comment.id)">
              댓글삭제
            </button>
          </span>
        </li>
      </ul>
    </div>
    <div v-else>댓글이 없습니다.</div>
  </div>
</template>

<script>
export default {
  props: {
    comments : Array,
  },
  methods : {
    isCommentUser(index) { // 신분 확인
      if(this.comments[index].user.username === this.$store.state.username) {
        return true;
      }
      return false;
    },
    deleteComment(id) {
      this.$emit("deleteComment", id);  // 부모 DetailView의 deleteComment호출
    },
  },
}
</script>