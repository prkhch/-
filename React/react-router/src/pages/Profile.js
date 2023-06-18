import { useParams } from "react-router-dom";

const data = {
  // url params (obj1, obj2)
  obj1: {
    name: "홍길동", // params 의 키 값들
    description: "홍길동이다.",
  },
  obj2: {
    name: "아무개",
    description: "아무개씨",
  },
};

const Profile = () => {
  const params = useParams();
  const profile = data[params.username];

  return (
    <div>
      <h1>사용자 프로필</h1>
      {profile ? (
        <div>
          <h2>{profile.name}</h2>
          <p>{profile.description}</p>
        </div>
      ) : (
        <div>
          <p>존재하지 않는 프로필</p>
        </div>
      )}
    </div>
  );
};

export default Profile;
