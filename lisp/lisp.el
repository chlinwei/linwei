;;作用选择当前光标下的单词或者选择块下的区域,得到的字符串和网址拼接,形成url
(require 'browse-url)
(defun my-lookup-wiki ()
  (interactive)
  (let (word)
    (setq word
	  (if (use-region-p) ;;判断光标是否在选择块模式下,类似vim中的v
		;;返回选择的块
	      (buffer-substring-no-properties (region-beginning) (region-end))
		  ;;返回当前光标所在的单词
	    (current-word))) 
    (setq word (replace-regexp-in-string " " "_" word))
    (browse-url (concat "http://en.wikipedia.org/wiki/" word))
    ))




;;选择""中内容
(defun my-select-inside-quotes ()
  "Select text between double straight quotes
on each side of cursor."
  (interactive)
  (let (p1 p2)
    (skip-chars-backward "^\"") ;;引号右边一个字符的位置
    (setq p1 (point)) 
    (skip-chars-forward "^\"") ;;引号左边一个字符的位置
    (setq p2 (point))

    (goto-char p1)
    (push-mark p2) ;;选择块的位置
    (setq mark-active t)))

;;这个函数有2个参数,M-x能调用这个函数,但是怎么传递参数呢？
;;如果 interactive "r"
;;就表示当调用这个参数时,将当前选择块的开始位置和结束位置分别传递给my-region这个函数
;;如果当前没有选择块,就将当前位置到这个buffer的结尾位置传递给my-region

(defun my-region (p1 p2)
    "Prints region starting and ending positions."
	  (interactive "r")
	    (message "Region starts: %d, end at: %d" p1 p2)
		)


