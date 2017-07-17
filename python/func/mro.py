#coding:utf-8
#mro()方法,查看类的继承顺序
class Base(object):
    def __init__(self):
        print("enter Base")
        print("leave Base")
 
class A(Base):
    def __init__(self):
        print("enter A")
        super(A, self).__init__()
        print("leave A")
 
class B(Base):
    def __init__(self):
        print("enter B")
        super(B, self).__init__()
        print("leave B")
 
class C(A, B):
    def __init__(self):
        print("enter C")
        super(C, self).__init__()
        print("leave C")



c = C() 
#enter C
#enter A
#enter B
#enter Base
#leave Base
#leave B
#leave A
#leave C

print(C.mro()) 
#[<class '__main__.C'>, <class '__main__.A'>, <class '__main__.B'>, <class '__main__.Base'>, <class 'object'>]
