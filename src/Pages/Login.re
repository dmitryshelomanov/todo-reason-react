let component = ReasonReact.statelessComponent("Login");

let make = _children => {
  ...component,
  render: _self =>
  <div className="container login_page">
    <div className="login-form">
      <div className="main-div">
        <div className="panel">
          <h2>{ReasonReact.string("Login page")}</h2>
          <p>{ReasonReact.string("Please enter your email and password")}</p>
        </div>
        <form id="Login">
          <div className="form-group">
            <input _type="email" className="form-control" placeholder="Email Address" />
          </div>
          <div className="form-group">
            <input _type="password" className="form-control" placeholder="Password" />
          </div>
          <button _type="submit" className="btn btn-primary">
            {ReasonReact.string("Login")}
          </button>
        </form>
      </div>
    </div>
  </div>
};
