// Generated by BUCKLESCRIPT VERSION 4.0.3, PLEASE EDIT WITH CARE
'use strict';

var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var ReasonReact = require("reason-react/src/ReasonReact.js");

var component = ReasonReact.statelessComponent("root");

function make(todo, onToggle, onRemove, _) {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */component[/* didMount */4],
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function () {
              var match = todo[/* isChecked */1];
              return React.createElement("li", {
                          key: String(todo[/* id */0]),
                          className: match ? "list-group-item disabled" : "list-group-item",
                          onClick: (function () {
                              return Curry._1(onToggle, todo[/* id */0]);
                            })
                        }, todo[/* title */2], React.createElement("p", undefined, React.createElement("input", {
                                  checked: todo[/* isChecked */1],
                                  type: "checkbox"
                                }), React.createElement("a", {
                                  href: "#",
                                  onClick: (function () {
                                      return Curry._1(onRemove, todo[/* id */0]);
                                    })
                                }, "remove")));
            }),
          /* initialState */component[/* initialState */10],
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */component[/* reducer */12],
          /* subscriptions */component[/* subscriptions */13],
          /* jsElementWrapped */component[/* jsElementWrapped */14]
        ];
}

exports.component = component;
exports.make = make;
/* component Not a pure module */
