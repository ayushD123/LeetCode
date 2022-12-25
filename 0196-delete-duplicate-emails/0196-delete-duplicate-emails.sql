# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below
#delete from Person p1,person p2 where p1.Email=p2.Email AND p1.Id>p2.Id;

delete p1 from Person p1,person p2 where p1.Email=p2.Email AND p1.Id>p2.Id;