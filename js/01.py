jack = ['jack',['age',20]]
tom=jack[:]
anny=list(jack)

print id(jack),id(tom),id(anny)

tom[0] = 'tom'
anny[0] = 'anny'

print jack,tom,anny

anny[1][1]=18
print jack,tom,anny 


print [id(x) for x in jack]
print [id(x) for x in tom]
print [id(x) for x in anny]
