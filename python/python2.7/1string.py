#_*_ coding:utf-8 _*_


#一.字符串和编码
#字符串连接
print "hello" + "world" #helloworld
#两个相邻的字符串自动连接在一起
print "hello" "world" #helloworld
#字符串内包含单引号或者双引号要转义,不然报错 
print "hello \"world" #hello "world
#不同类型的值或变量连接
#print 1 + "abc",error

#说明不同类型的值或变量不允许连接,想要连接可以下面这么做
print "%s%d" %('abc',1) #abc1

#格式化输出
# %s       字符串(str())
# %r       字符串(repr())
# %d       整数(int())
# %f       浮点数(float())

#字符串格式输出三种方法
x = "string"
print "%s" %x #string
print "%r" %x #'string'
print `x` #'string' ,注意反引号,将字符串转化为Python表达式



#字符串处理函数
x = "hello,world"
print "字符串长度:%s"  %(len(x)) #11
print "首字母大写:%s" %(x.capitalize()) #Hello,world
print "字符l出现次数:%d" %(x.count('l')) #3
print "字符串d是否结尾:%d" %(x.endswith('d')) #1
print "he字符串是否是开头:%d" %(x.startswith('he')) #1
print "格式化字符串: Hello{0} world!".format(',') #格式化字符串: Hello, world!
print "是否都是小写:%d" %(x.islower()) #1
print "是否都是大写:%d" %(x.isupper()) #0
print "所有字母转为小写:%s" %(x.lower()) #hello,world
print "所有字母转为大写:%s" %(x.upper()) #HELLO,WORLD
print "大小写互换:%s" %(x.swapcase()) #HELLO,WORLD
print "只要hello字符串:%s" %x[0:5]
print "去掉倒数第一个字符:%s" %(x[0:-1]) #hello,worl

#find方法(只有字符串才能调用):返回字串所在的位置的最左端的索引
#S.find(sub [,start [,end]]) -> int
a='123456 hello' 
print(a.find('6',4,6)) #5
print(a.find('6',4,5))
#这里抛异常,是从下标为4开始到下标为5结束(不包括下标为5)

#split函数和join函数相反,将字符串通过指定符号分割,返回分割后的字符串,
#原字符串不变
a = '1+2+3'
print a.split('+')  #=>['1','2','3','4']


#strip函数:返回去除两侧指定的字符串
#lstrip:去掉左边的指定字符串
#rstrip:去掉右边的指定的字符串
a = '    hello,world    '
print a.strip() #hello,world
a = ' !!! hello,world ###   '
print a.strip(' !#') #可以指定多个要删除的字符

#S.replace(old,new[,count])->string:替换指定个数的字符串
a='hello,world,hello,world,hello'
print(a.replace('hello','haha',1)) #第一个hello被替换
print(a.replace('hello','haha',2))#前两个hello被替换
print(a.replace('hello','haha')) #所有hello被替换


#字符串输出颜色
#字体颜色        字体背景颜色  #显示方式
# 30:黑          40:黑          0:终端默认设置
# 31:红          41:深红        1:高亮显示
# 32:绿          42:绿          4:下划线
# 33:黄          43:黄          7:闪烁
# 34:蓝          44:蓝          8:隐藏
# 35:紫          45:紫
# 36:深绿        46:深绿
# 37:白色        47:白色
#
print "\033[5;35;43mhello,world!\033[0m"
#5是显示方式,35是字体颜色,43m是字体背景色 \033[0m恢复终端默认颜色


#常见的字符编码类型
#ASCII:美国信息交换标准码,每个ASCII码以1个字节存储
#Unicode:为解决世界上上百种语言带来的混合,冲突,它把所有的语言的字符
#都统一到一套Unicode编码中,并定义每个语言字符的标准,所以
#Unicode又称统一码,万国码
#GB2312:中国国家标准总局发布处理汉子的标准编码
#GBK:GB2312的扩展,向下兼容GB2312
#UTF-8:针对Unicode的可变长度字符编码,又称万国码,支持简体中文及其他语言(如英文,日文,韩文)

#decode()作用:将其他编码(ASCII,Byte,String)的字符串解码为Unicode
#encode()作用:将Unicode编码成终端软件能识别的编码,比如UTF-8,GBK

