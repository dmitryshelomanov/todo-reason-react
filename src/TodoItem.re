let component = ReasonReact.statelessComponent("root");

let make = (~todo: TodoModel.item, ~onToggle, ~onRemove, _children) => {
  ...component,
  render: (_self) => {
    <li
      key={string_of_int(todo.id)}
      className=(
        todo.isChecked
          ? "list-group-item disabled"
          : "list-group-item"
      )
      onClick=((_) => onToggle(todo.id))
    >
      {ReasonReact.string(todo.title)}
      <p>
        <input
          _type="checkbox"
          checked=(todo.isChecked)
        />
        <a
          href="#"
          onClick=((_) => onRemove(todo.id))
        >
          {ReasonReact.string("remove")}
        </a>
      </p>
    </li>
  },
};
