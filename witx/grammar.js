const wit = require("../wit/grammar");

module.exports = grammar(wit, {
  name: "webassembly_api_description",
  rules: {
    TYPENAME: $ => "typename",
  },
});
