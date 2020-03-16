const wit = require("../wit/grammar");

module.exports = grammar(wit, {
  name: "witx",
  rules: {
    TYPENAME: $ => "typename",
  },
});
