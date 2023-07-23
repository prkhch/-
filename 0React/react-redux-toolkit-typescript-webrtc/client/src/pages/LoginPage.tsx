import { SGlobal, SPageLayout } from "components/common/style";
import NavBar from "components/common/NavBar";
import LoginForm from "containers/auth/LoginForm";

const LoginPage = () => {
  return (
    <div>
      <SPageLayout>
        <NavBar />

        <SGlobal>
          <LoginForm />
        </SGlobal>
      </SPageLayout>
    </div>
  );
};

export default LoginPage;
