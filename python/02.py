class Student(object):
    def __func2(self):
        print 'func2'

    def func1(self):
        __func2()
        print 'func1'




s = Student()

s.func1()
