#coding:utf-8
def is_odd(n): #判断是否为奇数
    return n%2 ==1

print(list(filter(is_odd,[1,2,3,4,5])))
