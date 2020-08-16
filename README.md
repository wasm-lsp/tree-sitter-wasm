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

| supported | extension | kind |
|:---------:|-----------|------|
| 🗹 | `.wat` | [WebAssembly module definition](https://github.com/WebAssembly/spec/tree/master/interpreter#s-expression-syntax) |
| 🗹 | `.wast` | [WebAssembly script](https://github.com/WebAssembly/spec/tree/master/interpreter#scripts) |
| soon | `.wit` | [WebAssembly module type](https://github.com/WebAssembly/module-types/blob/master/proposals/module-types/Overview.md) |
| soon | `.witx` | [WebAssembly API description](https://github.com/WebAssembly/WASI/blob/57744f48ec7d4e211d1542d1f56746b5cc1cf6a9/meetings/2019/WASI-09-12.md#meeting-notes) |

## Supported WebAssembly Proposals

The included grammars also support parsing WebAssembly modules using the following features:

#### Phase 4 (Standardization)

- 🗹 [bulk-memory-operations](https://github.com/WebAssembly/bulk-memory-operations)
- 🗹 [reference-types](https://github.com/WebAssembly/reference-types)

#### Phase 3 (Implementation)

- 🗹 [annotations](https://github.com/WebAssembly/annotations)
- 🗹 [simd](https://github.com/WebAssembly/simd)

#### Phase 2 (Specification)

- 🗹 [exception-handling](https://github.com/WebAssembly/exception-handling)
- 🗹 [threads](https://github.com/WebAssembly/threads)

#### Phase 1 (Proposal)

Nothing planned.

#### Phase 0 (Pre-Proposal)

Nothing planned.
