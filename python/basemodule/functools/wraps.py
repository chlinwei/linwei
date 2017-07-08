import functools

def log(func):
    @functools.wraps(func)
    def wrapper(*args, **kw):
        print('call %s():' % func.__name__)
        return func(*args, **kw)
    return wrapper
#now = log(now),now重新指向了一个log(now)返回的函数,此时now
#的指向变了,now.__name__由now变成了wrapper,为了让now.__name__不变
#在wrapper上面应该那么写
@log 
def now(): 
    print("2017-07-07")


print(now.__name__)
