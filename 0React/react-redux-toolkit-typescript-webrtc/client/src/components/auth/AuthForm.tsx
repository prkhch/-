import { SBox, SError } from "./style";
import { SInput } from "components/common/style";
import Button from "components/common/Button";

interface AuthFormProps {
  type: "login" | "register";
  form: {
    username: string;
    password: string;
    passwordConfirm?: string;
  };
  onChange: (e: React.ChangeEvent<HTMLInputElement>) => void;
  onSubmit: (e: React.ChangeEvent<HTMLFormElement>) => void;
  error: string | null;
}

const textMap = {
  login: "로그인",
  register: "회원가입",
};

const AuthForm: React.FC<AuthFormProps> = ({
  type,
  form,
  onChange,
  onSubmit,
  error,
}) => {
  const text = textMap[type];
  return (
    <SBox>
      <h3>{text}</h3>
      <form onSubmit={onSubmit}>
        <SInput
          autoComplete="username"
          name="username"
          placeholder="아이디"
          onChange={onChange}
          value={form.username}
        />
        <SInput
          autoComplete="new-password"
          name="password"
          placeholder="비밀번호"
          type="password"
          onChange={onChange}
          value={form.password}
        />
        {type === "register" && (
          <SInput
            autoComplete="new-password"
            name="passwordConfirm"
            placeholder="비밀번호 확인"
            type="password"
            onChange={onChange}
            value={form.passwordConfirm}
          />
        )}
        <SError>{error && <div>{error}</div>}</SError>
        <Button>{text}</Button>
      </form>
    </SBox>
  );
};

export default AuthForm;
