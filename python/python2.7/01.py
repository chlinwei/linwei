#_*_coding:utf-8 _*_

from ConfigParser import ConfigParser
conf = ConfigParser()
conf.read("config.ini")
fp = open("config.ini", "w")
conf.remove_section('host4')  # 删除[host4]
conf.remove_option('host3', 'pass')  # 删除[host3]的pass选项
conf.write(fp)

print "hello,world"
