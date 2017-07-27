#coding:utf-8

#将字符串进行分割,类似split
str = 'a+b+c+d'

print(str.split('+'))#返回列表['a', 'b', 'c','d]
print(str.partition('+'))#返回含有三个元素的元组('a','+','b+c+d')



