def odd(): 
    yield
    print 'step1'
    yield
    print 'step2'
    yield
    print 'step3'
    yield
    print 'step4'
x=0
for i in odd():
    print x

print x
