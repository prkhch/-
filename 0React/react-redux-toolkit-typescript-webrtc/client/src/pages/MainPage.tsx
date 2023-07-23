import { SGlobal, SPageLayout } from "components/common/style";
import NavBar from "components/common/NavBar";
import { MicIcon } from "components/common/Icons";
import main from "assets/main/main.png";

const MainPage = () => {
  return (
    <SPageLayout>
      <NavBar />

      <SGlobal>
        메인 페이지
        <MicIcon />
        <img src={main} alt="main" style={{ width: "100%", height: "100%" }} />
      </SGlobal>
    </SPageLayout>
  );
};

export default MainPage;
