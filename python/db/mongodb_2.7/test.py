import pymongo
from pymongo import MongoClient
uri =  'mongodb://lw:linwei232529@118.89.54.105:27017'
client = MongoClient(uri,27017)
db = client.mldn
for item in db.news.find():
    print(item)
