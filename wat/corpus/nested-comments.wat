;;; foo
(module
  (;;;fkk ;(;;)(; ;)x;(;x;) ry ;)
  ;; bbb
  (;;))

(;
(ROOT [0, 0] - [5, 0]
  (comment_line [0, 0] - [0, 7])
  (module [1, 0] - [4, 5]
    (comment_block [2, 2] - [2, 33]
      (comment_block_inner [2, 4] - [2, 30]
        (comment_block [2, 11] - [2, 15])
        (comment_block [2, 15] - [2, 20])
        (comment_block [2, 22] - [2, 27]
          (comment_block_inner [2, 24] - [2, 25]))))
    (comment_line [3, 2] - [3, 8])
    (comment_block [4, 0] - [4, 4])))
;)
