import { useParams } from "react-router-dom";

const Article = () => {
  const { id } = useParams();

  return (
    <div>
      <h2>Article.js</h2>
      <p>/articles/{id}</p>
    </div>
  );
};

export default Article;
