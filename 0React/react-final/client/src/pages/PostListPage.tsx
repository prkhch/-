import { SGlobal, SPageLayout } from "components/common/style";
import NavBar from "components/common/NavBar";
import Button from "components/common/Button";

const PostListPage = () => {
  return (
    <div>
      <SPageLayout>
        <NavBar />
        <SGlobal>
          게시판 페이지
          <Button to="/write">글쓰기</Button>
        </SGlobal>
      </SPageLayout>
    </div>
  );
};

export default PostListPage;
