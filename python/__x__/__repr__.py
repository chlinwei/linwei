#__repr__是给程序员看的

class A:
    def __init__(self):

    def __repr__(self):
        print("hahahah")

a = A()
print(repr(a))
