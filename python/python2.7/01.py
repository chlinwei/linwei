def func():
    x = 2
    def func2():
        x=5
    func2()
    return x

print func()


