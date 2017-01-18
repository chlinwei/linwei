#_*_ coding:utf-8 _*_
import MySQLdb

db = MySQLdb.connect('localhost','lw','linwei','test')
#使用cursor()方法获取操作游标
cursor = db.cursor()
#使用execute方法执行SQL语句
cursor.execute('select version()')
#使用fetchone()方法获取一条数据
data = cursor.fetchone()
print data
db.close()






