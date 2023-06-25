import { Route, Routes } from 'react-router-dom';
import ColorPage from './pages/ColorPage';
import LoginPage from './pages/LoginPage';
import RegisterPage from './pages/RegisterPage';
import MyPage from './pages/MyPage';

const App = () => {
  return (
    <Routes>
      <Route path="/" element={<ColorPage />}></Route>
      <Route path="/:id" element={<MyPage />}></Route>
      <Route path="/login" element={<LoginPage />}></Route>
      <Route path="/register" element={<RegisterPage />}></Route>
    </Routes>
  );
};

export default App;
