// const MyComponent = ({ name, children }) => {
//   return (
//     <div>
//       컴포넌트 {name}입니다. <br />
//       {/* 넘어온 인자로 표현, 없으면 defaultProps인 기본 이름을 사용 */}
//       childern 값은 {children}
//       {/* 감싸진 요소가 넘어옴 children */}
//     </div>
//   );
// };

// MyComponent.defaultProps = {
//   name: '기본 이름',
// };

// export default MyComponent;

// propTypes를 통한 props 검증
// import PropTypes from 'prop-types';

// const MyComponent = ({ name, favoriteNumber, children }) => {
//   return (
//     <div>
//       컴포넌트 이름 {name}
//       <br />
//       자식 {children}
//       <br />
//       숫자는 {favoriteNumber}
//     </div>
//   );
// };

// MyComponent.defaultProps = {
//   name: '기본 이름',
// };

// MyComponent.propTypes = {
//   name: PropTypes.string, // (타입을 통한) 검증
//   favoriteNumber: PropTypes.number.isRequired,
// };

// export default MyComponent;

// 클래스형 컴포넌트에서 props
import { Component } from 'react';
import PropTypes from 'prop-types';

class MyComponent extends Component {
  static defaultProps = {
    name: '기본 이름',
  };
  static propTypes = {
    name: PropTypes.string,
    favoriteNumber: PropTypes.number.isRequired,
  };

  render() {
    const { name, favoriteNumber, children } = this.props; // 비구조화  할당
    return (
      <div>
        안녕하세요. 이름 {name}
        <br />
        children은 {children}
        <br />
        숫자는 {favoriteNumber}
      </div>
    );
  }
}

//  클래스형 컴포넌트에서는 class 내부에서 타입 기본값 지정 가능

// MyComponent.defaultProps = {
//   name: '기본 이름',
// };

// MyComponent.propTypes = {
//   name: PropTypes.string,
//   favoriteNumber: PropTypes.number.isRequired,
// };

export default MyComponent;
