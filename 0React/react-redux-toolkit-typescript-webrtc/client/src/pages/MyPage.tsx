import { SGlobal, SPageLayout } from "components/common/style";
import NavBar from "components/common/NavBar";
import { useParams } from "react-router-dom";

const MyPage = () => {
  const { username } = useParams();

  return (
    <div>
      <SPageLayout>
        <NavBar />
        <SGlobal>{username}의 마이 페이지</SGlobal>
      </SPageLayout>
    </div>
  );
};

export default MyPage;
