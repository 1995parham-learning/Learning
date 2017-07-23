# S2NOS
Some guidlines on mapping the relational databases to non-relational ones(MongoDB).

## Overview 
* Table = Collection 
* Row = Document
* Column = Field

## Mapping Examples
Let's assume we have the following table in a **RDBMS**:

| id  | name | github | age | city |
| --- | --- | --- | --- | --- |
| 1 | Parham Alvani | 1995parham | 23 | Tehran |
| 2 | Pooya Parsa | pi0 | 23 | Tehran |

after converting the above table to a **NoSQL** format, we'll have **1 JSON Collection** consisting of **2 Documents** with the following **fields**:
```
{
    "id": ObjectId("oifm39tj9jt093j4ig0n4094t09j4094t"),
    "name": "Parham Alvani,
    "github": "1995parham",
    "age": 23,
    "city": "Tehran"
}

{
    "id": ObjectId("oifm39tj9jt093j4ig0n4094t09j4094t"),
    "name": "Pooya Parsa,
    "github": "pi0",
    "age": 23,
    "city": "Tehran"
}
```

## Dynamic Schema
Something amazing about **MongoDB** and other document-based databases is their **Dynamic Schema** which lets us have documents with **different** fields. We can have the following document in MongoDB:
```
{
    "id": ObjectId("oifm39tj9jt093j4ig0n4094t09j4094t"),
    "name": "Parham Alvani,
    "github": "1995parham",
    "age": 23,
    "city": "Tehran"
    "personality": "Easy-Going"
}

{
    "id": ObjectId("oifm39tj9jt093j4ig0n4094t09j4094t"),
    "name": "Pooya Parsa,
    "github": "pi0",
    "age": 23,
    "city": "Tehran"
    "Nationality": "Persian"
}
```
## Joins and Relationships
Assume we have a table called **Hero Information**:

| id  | name | github | age | city |
| --- | --- | --- | --- | --- |
| 1 | Parham Alvani | 1995parham | 23 | Tehran |
| 2 | Pooya Parsa | pi0 | 23 | Tehran |

and we also have another table called **Computer Department Heros**:

| id  | hero_id | field | Entrance |
| --- | --- | --- | --- |
| 101 | 1 | Software | 92 |
| 202 | 2 | Software | 92 |

and we want to design the above tables in a document-based format. There are two main approaches:
* **Linking Documents**
* **Mapping Documents**

## Linking Documents
In order to implement the **foreign key** logic in this method, we will have to provide the hero_id as a foreign key in the **Computer Department Heros** Table, So we'll have the following documents in our collection:

* **Hero Information**:
```
{
    "id": ObjectId("1995parham1995parham"),
    "name": "Parham Alvani,
    "github": "1995parham",
    "age": 23,
    "city": "Tehran"
}

{
    "id": ObjectId("pi0pi0"),
    "name": "Pooya Parsa,
    "github": "pi0",
    "age": 23,
    "city": "Tehran"
}
```
* **Computer Department Heros**:
```
{
    "id": ObjectId("oifm39tj9jt093j4ig0n4094t09j4094t"),
    "hero_id": new MongoId("1995parham1995parham")
    "field": "Software",
    "entrance": 92,
}

{
    "id": ObjectId("oifm39tj9jt093j4ig0n4094t09j4094t"),
    "hero_id": new MongoId("pi0pi0")
    "field": "Software",
    "entrance": 92,
}
```
as you can see, the hero_id is linking to the other id field in the **Hero Information** table. This is the **Linking Document** technique.

## Embedding Documents
The second approach is to embed the document in each other:
```
{
    "id": ObjectId("1995parham1995parham"),
    "name": "Parham Alvani,
    "github": "1995parham",
    "age": 23,
    "city": "Tehran"
    CEIT_INFO {
    "field": "Software",
    "entrance": 92,
    }
}

{
    "id": ObjectId("pi0pi0"),
    "name": "Pooya Parsa,
    "github": "pi0",
    "age": 23,
    "city": "Tehran"
    CEIT_INFO {
    "field": "Software",
    "entrance": 92,
    }
}
```