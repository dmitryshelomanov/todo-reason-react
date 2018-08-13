open Router;


type state = {route: page};
type action =
  | UpdatePage(page);
let component = ReasonReact.reducerComponent("App");
let make = _children => {
  ...component,
  initialState: () => {
    route: ReasonReact.Router.dangerouslyGetInitialUrl()
      |> toPage
  },
  subscriptions: self => [
    Sub(
      () =>
        ReasonReact.Router.watchUrl(url =>
          self.send(UpdatePage(toPage(url)))
        ),
        ReasonReact.Router.unwatchUrl,
      ),
  ],
  reducer: (action, _state) =>
    switch (action) {
    | UpdatePage(route) => ReasonReact.Update({route: route})
    },
  render: ({state}) =>
    switch (state.route) {
    | Todo => <Todo />
    | Login => <Login />
    }
};
