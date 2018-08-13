type page =
  | Login
  | Todo;

let toPage = (url: ReasonReact.Router.url) =>
  switch (url.hash) {
  | "todo" => Todo
  | _ => Login
  };

let toUrl = page =>
  switch (page) {
  | Todo => "todo"
  | _ => "dashboard"
  };
