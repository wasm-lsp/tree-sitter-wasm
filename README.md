<div align="center">
  <h1>tree-sitter-wasm</h1>
  <p style="margin-bottom: 0.5ex;">
    <a href="https://github.com/wasm-lsp/tree-sitter-wasm/actions"><img
        src="https://github.com/wasm-lsp/tree-sitter-wasm/workflows/main/badge.svg" /></a>
    <img src="https://img.shields.io/badge/eslint-checked-informational?logo=eslint" />
    <img src="https://img.shields.io/badge/prettier-formatted-informational?logo=prettier" />
  </p>
  <strong>WebAssembly grammars for tree-sitter</strong>
</div>

## Supported Document Types

| extension | supported | kind                                                                                                             |
| :-------: | --------- | ---------------------------------------------------------------------------------------------------------------- |
|  `.wat`   | 🗹         | [WebAssembly module definition](https://github.com/WebAssembly/spec/tree/master/interpreter#s-expression-syntax) |
|  `.wast`  | 🗹         | [WebAssembly script](https://github.com/WebAssembly/spec/tree/master/interpreter#scripts)                        |

## Supported WebAssembly Proposals

The included grammars also support parsing WebAssembly modules using the following features:

#### Phase 4 (Standardization)

- 🗹 [bulk-memory-operations](https://github.com/WebAssembly/bulk-memory-operations)
- 🗹 [reference-types](https://github.com/WebAssembly/reference-types)

#### Phase 3 (Implementation)

- 🗹 [annotations](https://github.com/WebAssembly/annotations)
- 🗹 [multi-memory](https://github.com/WebAssembly/multi-memory)
- 🗹 [simd](https://github.com/WebAssembly/simd)

#### Phase 2 (Specification)

- 🗹 [exception-handling](https://github.com/WebAssembly/exception-handling)
- 🗹 [function-references](https://github.com/WebAssembly/function-references)
- 🗹 [threads](https://github.com/WebAssembly/threads)

#### Phase 1 (Proposal)

Nothing planned.

#### Phase 0 (Pre-Proposal)

Nothing planned.
