import { SGlobal, SPageLayout } from "components/common/style";
import NavBar from "components/common/NavBar";
import RegisterForm from "containers/auth/RegisterForm";

const RegisterPage = () => {
  return (
    <SPageLayout>
      <NavBar />

      <SGlobal>
        <RegisterForm />
      </SGlobal>
    </SPageLayout>
  );
};

export default RegisterPage;
