import { Component } from "react";

class EventPractice extends Component {
  state = {
    username: "",
    message: "",
  };

  handleChange = (e) => {
    this.setState({
      [e.target.name]: e.target.value, // 2. state의 message값 변경
    });
  };

  handleClick = () => {
    alert(this.state.username + " : " + this.state.message);
    this.setState({
      username: "",
      message: "",
    });
  };

  handleKeyPress = (e) => {
    if (e.key === "Enter") {
      this.handleClick();
    }
  };

  render() {
    return (
      <div>
        <h1>이벤트 연습</h1>
        <input
          type="text"
          name="username"
          placeholder="이름"
          value={this.state.username} // 3. 그 message값을 value로
          onChange={this.handleChange} // 1.this.handleChange
        />
        <input
          type="text"
          name="message"
          placeholder="메시지"
          value={this.state.message} // 3. 그 message값을 value로
          onChange={this.handleChange} // 1.this.handleChange
          onKeyPress={this.handleKeyPress}
        />
        <button onClick={this.handleClick}>확인</button>
      </div>
    );
  }
}

export default EventPractice;
