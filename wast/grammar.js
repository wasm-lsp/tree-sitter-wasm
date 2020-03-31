const wat = require("../wat/grammar");

module.exports = grammar(wat, {
  name: "wast",

  rules: {
    ENTRYPOINT: $ => repeat($.cmd),

    cmd: $ => choice($.module),
  },
});
