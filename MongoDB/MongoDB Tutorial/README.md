# Mangool
MongoDB Fundamentals in depth.

## What kindda db is this?
* This is a **NoSQL** database
* More specifically, it is a **document-based** database
* Data and records are stored as **documents** and have **JSON** like syntax
* No pre-defined structring like what we do in **Relational Databases**

## What is the advantage?
* **Scaling**: They are easier to scale compared to relational databases
* **Faster**: They are much faster in most types of operations

## How to install
Simply download the MongoDB from [This](https://www.mongodb.com/download-center) website and create the following folders in the install directory:
* log
* data -> db
Then, just open the **CMD** and head to the **bin** folder of install path and run the following command:
```
mongod --directoryperdb --dbpath c:\mongodb\data\db --logpath c:\mongodb\log\mongo.log --logappend --rest --install
```
and then, start the MongoDB by writing:
```
net start MongoDB
```

## Essential Commands
* Showing the list of databases: 
```
show dbs
```
* Creating a database:
```
use myDatabase
```
* What database i'm in:
```
db
```
## Document Syntax
This will support almost every data type on the earth:
```
{
    first_name: "John",
    last_name: "Doe",
    memberships: ["mem1", "mem2"]
    address:{
        street:"4 main st",
        city:"Boston"
    }
}
```
To create a new user:
```
db.createUser({
    username:"ALi",
    pwd:"mynameismethoz",
    roles: [ "readWrite, "dbAdmin" ]
});
```
For in-depth syntax please head to (MongoDB Docs)[https://docs.mongodb.com/manual/].

## Collections
* They are similar to the **Tables** in a relational database
* They hold documents or records inside themselves
* To create a new collection follow the below code:
```
db.createCollection('aligholameeCollection');
```
* To see all collections in the database:
```
show collections
```
* To insert a document into a collection simply type:
```
db.aligholameeCollection.insert({first_name:"John", last_name:"Doe"});
```
* To see documents inside a collection:
```
db.aligholameeCollection.find();
```
* To make the find result a bit more pretty:
```
db.aligholameeCollection.find().pretty();
```
* To update a filed in the database:
```
db.aligholameeCollection.update({first_name:"John"}, {first_name:"John", last_name:"Doe", gender:"male"});
```
The **important** thing here is that if there was not any first_name and last_name parameter in the second object we passed in, the gender would replace the whole object. To avoid this problem we use **$set** operator:
```
db.aligholameeCollection.update({first_name:"John"}, {$set: {gender: "male"}});
```
* To remove a field of the database:
```
db.aligholameeCollection.update({first_name:"Steven"}, {$unset: {age:1}});
```
* To insert if the result hasn't found on the update we use **upsert**:
```
db.aligholameeCollection.update({first_name:"Steven"}, {$upsert:true});
```
* To rename a field:
```
db.aligholameeCollection.update({first_name:"John"}, {$rename:{"gender":"sex"}});
```
* Direct remove:
```
db.aligholameeCollection.remove({first_name:"Steven"})
```
