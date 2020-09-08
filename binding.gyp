{
  "targets": [
    {
      "target_name": "tree_sitter_wast",
      "include_dirs": [
        "<!(node -e \"require('nan')\")",
        "wast/src"
      ],
      "sources": [
        "wast/src/parser.c",
        "wast/src/binding.cc"
      ],
      "cflags_c": [
        "-std=c99",
      ]
    },
    {
      "target_name": "tree_sitter_wat",
      "include_dirs": [
        "<!(node -e \"require('nan')\")",
        "wat/src"
      ],
      "sources": [
        "wat/src/parser.c",
        "wat/src/binding.cc"
      ],
      "cflags_c": [
        "-std=c99",
      ]
    },
  ]
}
