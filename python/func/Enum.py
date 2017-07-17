#coding:utf-8
#枚举

#方法1.
from enum import Enum
x= Enum('Month',('Jan','Feb','Mar'))
print(x.Jan.__class__) #<enum 'Month'> ,注意enum是元类类似type
print(x.Jan.value) #1
#说明:
#Enum的第一个参数是定义一个枚举类型,枚举类型名称为Month,这个类型实例化了Jan,Feb,Mar等
#实例,这几个实例是唯一的,value默认从1开始

#方法2
@unique  #检查是否有重复的值,有责报错
class Month(Enum):
    Jan = 1
    Mon = 2
    Mar = 3
    #Apr = 2
     
print(Month.Jan.__class__) #<enum 'Month'>
print(Month.Jan.value) #1


