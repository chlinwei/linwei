#coding:utf-8
#在进行if判断,或者转化为bool值时,会调用__nonzero__函数
class A:
    def __nonzero__(self):
        return False

a = A()

if a:  #如果没有__nonzero__函数,此处应该是True
    print("fdfdsa")


print bool(a) #False
