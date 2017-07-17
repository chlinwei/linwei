#coding:utf-8

#写自己的迭代器有2步
#1)实现__iter__方法,返回要迭代的对象
#2)实现__next__方法,返回的值将会是每次迭代的值，__next__方法里自己写
#结束条件StopIteration,这个for in会自动处理的
class A:
    def __init__(self,start,stop):
        self.start = start
        self.stop = stop
        self.value = start -1
    def __iter__(self):
        return self
    def __next__(self):
        if self.value == self.stop:
            raise StopIteration
        self.value += 1
        #return self.value
        return 1

#使用迭代器方法
#1)
a = A(1,5)
a1 = A(1,5)
aIter = iter(a)
print(next(aIter))
print(next(aIter))


print('#'*4)
#2)
for i in a1:
    print(i)

