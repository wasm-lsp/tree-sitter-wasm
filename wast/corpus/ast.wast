(module $m
  (type $t (func (result i32)))
  (import "console" "log" (func $log (param i32)))
  (func $f (loop (result i32)))
  (export "f" (func $f)))

(module $m
  (type $t (func (result i32)))
  (import "console" "log" (func $log (param i32)))
  (func $f (loop (result i32)))
  (export "f" (func $f)))
