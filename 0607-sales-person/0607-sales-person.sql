# Write your MySQL query statement below
select name from salesperson where sales_id not in (select  sales_id from Orders natural join company where name='RED');