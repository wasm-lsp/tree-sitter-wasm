(; test ;)
( ;;
  (; ;;
  ;)
  module $m
    (type $t (func))
    (import "console" "log" (func $log (param i32)))
    (func $f (loop (result i32)))
    (export "f" (func $f))
  )

