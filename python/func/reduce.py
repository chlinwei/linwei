#coding:utf-8
#和map的参数一样
from functools import reduce
def f(x,y):
    return x*10 + y

print(reduce(f,[1,3,5,7,9])) #13579


#原理:每次从数组读取前两个元素,通过函数,将先生成的
#元素代理原先的两个元素,这个新的数组重复以往的操作,最终
#得到一个元素

