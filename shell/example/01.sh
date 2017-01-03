#将~/.bashrc里的除了空白行和注释行去掉
方法1.基本正则表达式
cat ~/.bashrc | grep -v '^$' | grep -v '^#'
方法2.扩展正则表达式
cat ~/.bashrc | egrep -v '^$|^#'
