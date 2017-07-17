#1)属性暴露在外面不好,而且还没有对属性类型的检查,很坑爹
#所以就有了getScore,和setScore函数,但是每次都得在类中写
#这样两个函数很麻烦,而且没有直接给属性赋值来的简洁,所以
#出现了@property

class Student(object):
    @property
    def score(self):
        return self._score
    @score.setter
    def score(self,value):
        if not isinstance(value,int):
            raise ValueError('score must be an integer')
        if value <0 or value > 100:
            raise ValueError('score must between 0 ~ 10000')
        self._score = value

s = Student()
s.score = 79
print(s.score)
