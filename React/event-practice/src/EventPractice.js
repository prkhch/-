import { Component } from "react";

class EventPractice extends Component {
  state = {
    message: "",
  };

  constructor(props) {
    // 함수 바인딩 작업
    super(props);
    this.handleChange = this.handleChange.bind(this);
    this.handleClick = this.handleClick.bind(this);
  }

  handleChange(e) {
    this.setState({
      message: e.target.value, // 2. state의 message값 변경
    });
  }

  handleClick() {
    alert(this.state.message);
    this.setState({
      message: "",
    });
  }

  render() {
    return (
      <div>
        <h1>이벤트 연습</h1>
        <input
          type="text"
          name="message"
          placeholder="플레이스 홀더"
          value={this.state.message} // 3. 그 message값을 value로
          onChange={this.handleChange} // 1.this.handleChange
        />
        <button onClick={this.handleClick}>확인</button>
      </div>
    );
  }
}

export default EventPractice;
