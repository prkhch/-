import { SGlobal, SPageLayout } from "components/common/style";
import NavBar from "components/common/NavBar";
import Button from "components/common/Button";

const PostListPage = () => {
  return (
    <div>
      <SPageLayout>
        <NavBar />
        <SGlobal>마이 페이지</SGlobal>
      </SPageLayout>
    </div>
  );
};

export default PostListPage;
