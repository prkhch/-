import { SGlobal, SPageLayout } from "components/common/style";
import NavBar from "components/common/NavBar";

const PostPage = () => {
  return (
    <div>
      <SPageLayout>
        <NavBar />
        <SGlobal>게시물 페이지</SGlobal>
      </SPageLayout>
    </div>
  );
};

export default PostPage;
