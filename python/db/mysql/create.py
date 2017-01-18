#_*_ coding:utf-8 _*_

import MySQLdb
db = MySQLdb.connect('localhost','lw','linwei','test')

cursor = db.cursor()

cursor.execute("DROP TABLE IF EXISTS EMPLOYEE")
sql = """CREATE TABLE EMPLOYEE (
         FIRST_NAME  CHAR(20) NOT NULL,
         LAST_NAME  CHAR(20),
         AGE INT,
         SEX CHAR(1),
         INCOME FLOAT )"""

cursor.execute(sql)
db.close()
