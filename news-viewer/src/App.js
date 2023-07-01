import { Route, Routes } from 'react-router-dom';
import NewsPage from './pages/NewsPage';

// 6b24c743c51a4e7a91cb660aeca5d345

const App = () => {
  return (
    <>
      <Routes>
        <Route path="/" element={<NewsPage />} />
        <Route path="/:category" element={<NewsPage />} />
      </Routes>
    </>
  );
};

export default App;
