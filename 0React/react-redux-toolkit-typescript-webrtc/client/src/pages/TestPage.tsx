import { SGlobal, SPageLayout } from "components/common/style";
import NavBar from "components/common/NavBar";

const TestPage = () => {
  return (
    <SPageLayout>
      <NavBar />
      <SGlobal>게시판 페이지</SGlobal>
    </SPageLayout>
  );
};

export default TestPage;
