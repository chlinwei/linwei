#coding:utf-8
#格式化字符串


#1)使用'{}'作为占位符
print('I\'m {},{}'.format('linwei',"I come from china"))  #I'm linwei,I come from china

#2)使用'{0}','{1}'作为占位符号
print('I\'m {1},{0}'.format('linwei',"I come from china"))#I'm I come from china,linwei

#3)使用 '{name}' '{message}'作为占位符号
print('I\m {name},{message}'.format(name='linwei',message="I come from china"))
#注意点:
#print('I\m {name},{}'.format(name='linwei',"I come from china")),错误的,和默认参数一样的


#3)使用'{0}','{message}'混合
print('I\m {0},{message}'.format('linwei',message="I come from china"))
#上面{0}也可以写成{}


