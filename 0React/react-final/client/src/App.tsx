import React from "react";
import {Route, Routes} from 'react-router-dom'
import MainPage from "./pages/MainPage";
import RegisterPage from "./pages/RegisterPage";
import LoginPage from "./pages/LoginPage";
import PostListPage from "./pages/PostListPage";
import PostPage from "./pages/PostPage";
import WritePage from "./pages/WritePage";
import TestPage from "./pages/TestPage";

function App() {
  return (
    <Routes>

      <Route path="/" element={<MainPage/>}/>
      <Route path="/register" element={<RegisterPage/>}/>
      <Route path="/login" element={<LoginPage/>}/>
      <Route path="/write" element={<WritePage/>}/>
      
      <Route path="/post" element={<PostListPage/>}>
        <Route path=":postId" element={<PostPage/>}/>
      </Route>

      <Route path="/test" element={<TestPage/>}/>

    </Routes>
  );
}

export default App;