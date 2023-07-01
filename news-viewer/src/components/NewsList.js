import './NewsList.scss';
import NewsItem from './NewsItem';
import axios from 'axios';
import usePromise from '../lib/usePromise';

const NewsList = ({ category }) => {
  console.log(category);
  const [loading, response, error] = usePromise(() => {
    const query = category === 'all' ? '' : `&category=${category}`;
    return axios.get(
      `https://newsapi.org/v2/top-headlines?country=kr${query}&apiKey=6b24c743c51a4e7a91cb660aeca5d345`,
    );
  }, [category]);

  if (loading) {
    return <div className="NewsListBlock">불러오는 중</div>;
  }

  if (!response) {
    return null;
  }

  if (error) {
    return <div className="NewsListBlock">에러 발생!</div>;
  }

  const { articles } = response.data;
  return (
    <div className="NewsListBlock">
      {articles.map((article) => (
        <NewsItem key={article.url} article={article} />
      ))}
    </div>
  );
};

export default NewsList;
