open TodoModel;

type state = {
  todo: string,
  todos: list(item),
};

type action =
  | AddTodo(string)
  | ToggleTodo(int)
  | RemoveTodo(int)
  | UpdateValue(string);

let component = ReasonReact.reducerComponent("root");

let make = (_children) => {
  ...component,
  initialState: () => { todo: "", todos: [] },
  reducer: (action, state) =>
    switch (action) {
    | AddTodo(todo) => ReasonReact.Update({
        todo: "",
        todos: [{ id: UniqId.getUniqId(), title: todo, isChecked: false }, ... state.todos],
      })
    | UpdateValue(char) => ReasonReact.Update({ ...state, todo: char })
    | ToggleTodo(id) => {
        let todos = List.map(
          (todo: item) =>
            todo.id === id ? { ...todo, isChecked: !todo.isChecked } : todo,
          state.todos
        );

        ReasonReact.Update({ ...state, todos })
      }
    | RemoveTodo(id) => {
        let todos = List.filter(
          (todo: item) => todo.id !== id,
          state.todos
        );

        ReasonReact.Update({ ...state, todos })
      }
    },
  render: ({ state, send }) => {
    let len = string_of_int(List.length(state.todos));
    let renderTodo = (todo: item) => (
      <TodoItem
        key=(string_of_int(todo.id))
        todo
        onToggle=(id => send(ToggleTodo(id)))
        onRemove=(id => send(RemoveTodo(id)))
      />
    );
    let todosItem = state.todos
      |> List.sort((prev: item, next: item) => {
        !next.isChecked && prev.isChecked ? 1 : 0
      })
      |> List.map(renderTodo)
      |> Array.of_list
      |> ReasonReact.array;

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