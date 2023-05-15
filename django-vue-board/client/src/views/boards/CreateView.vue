<template>
  <div>
    <AppUsername/>
    <AppLogout/>
    <ArrowBack :arrowBackRouteName="arrowBackRouteName"/>
    <h1>새 글 작성</h1>
    <div class="form-floating">
      <input type="text"
      class="form-control"
      id="article-title"
      placeholder="article title"
      v-model="title"/>
    </div>
  </div>
</template>