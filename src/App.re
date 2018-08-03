type item = {
  id: int,
  isChecked: bool,
  title: string,
};

type state = {
  todo: string,
  todos: list(item),
};

type action =
  | AddTodo(string)
  | ToggleTodo(int)
  | UpdateValue(string);

let component = ReasonReact.reducerComponent("root");

let id = ref(0);

let uniqId = () => {
  id := id^ + 1;

  id^
};

let make = (_children) => {
  ...component,
  initialState: () => { todo: "", todos: [] },
  reducer: (action, state) =>
    switch (action) {
    | AddTodo(todo) => ReasonReact.Update({
        todo: "",
        todos: [{ id: uniqId(), title: todo, isChecked: false }, ... state.todos],
      })
    | UpdateValue(char) => ReasonReact.Update({ ...state, todo: char })
    | ToggleTodo(id) => {
        let todos = List.map(
          (todo) =>
            todo.id === id ? { ...todo, isChecked: !todo.isChecked } : todo,
          state.todos
        );

        ReasonReact.Update({ ...state, todos })
      }
    },
  render: ({ state, send }) => {
    let len = string_of_int(List.length(state.todos));
    let renderTodo = (todo) => (
      <li
        key={string_of_int(todo.id)}
        className=(
          todo.isChecked
            ? "list-group-item disabled"
            : "list-group-item"
        )
        onClick=((_event) => send(ToggleTodo(todo.id)))
      >
        {ReasonReact.string(todo.title)}
        <input
          _type="checkbox"
          checked=(todo.isChecked)
        />
      </li>
    );
    let todosItem = state.todos
      |> List.map(renderTodo)
      |> Array.of_list
      |> ReasonReact.arrayToElement;

    let addNewTodo = (event) => {
      ReactEventRe.Synthetic.preventDefault(event);
      send(AddTodo(state.todo));
    };

    let updateChar = (event) => {
      let value = (
        event
        |> ReactEventRe.Form.target
        |> ReactDOMRe.domElementToObj
      )##value;
 
      send(UpdateValue(value));
    };
 
    <div>
      <nav className="navbar navbar-dark bg-dark">
        <a className="navbar-brand" href="#">
          {ReasonReact.string("Simple Todo App")}
        </a>
        <span className="navbar-text">
          {ReasonReact.string(len ++ " items")}
        </span>
      </nav>
      <section className="container">
        <form
          onSubmit=addNewTodo
        >
          <h2>
            {ReasonReact.string("Todo title")}
          </h2>
          <input
            _type="text"
            className="form-control"
            placeholder="your todo"
            value={state.todo}
            onChange=updateChar
          />
          <ul className="list-group">
            {todosItem}
          </ul>
        </form>
      </section>
    </div>
  },
};