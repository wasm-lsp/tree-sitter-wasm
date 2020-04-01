;; module 0
(module $m0
  (type $t (func (result i32)))
  (import "console" "log" (func $log (param i32)))
  (func $f (loop (result i32)))
  (export "f" (func $f)))

;; module 1
(module $m1
  (type $t (func (result i32)))
  (import "console" "log" (func $log (param i32)))
  (func $f (loop (result i32)))
  (export "f" (func $f)))

(register "foo" $m2)

(invoke "eq" (f32.const -0x0p+0) (f32.const -0x0p+0))
