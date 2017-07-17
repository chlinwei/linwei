#in 操作时会调用__contains__函数
#not in 操作时也会调用__contains__函数只是会将这个函数的结果取反
class A:
    def __init__(self,num):
        self.num = num
    def __contains__(self,item):
        if item < self.num and item >=0:
            return True
        return False



if 2 in A(9):
    print "True"
else:
    print "False"

if 2 not in A(9):
    print "True"
else:
    print "False"
