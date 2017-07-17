#当进行下表运算的时候,实际上是调用__getitem__函数,下表的数字传入到item中
#实现下表运算
class A:
    def __init__(self,n):
        self.x = range(n)
    def __getitem__(self,item):
        return self.x[item]

a = A(5)

print(a[0])#0  
print(a[1])#1
print(a[2])#2
print(a[3])#3
print(a[4])#4
