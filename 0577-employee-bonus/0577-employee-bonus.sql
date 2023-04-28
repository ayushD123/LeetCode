# Write your MySQL query statement below
select e.name,b.bonus from employee e natural left join bonus b where b.bonus is null or b.bonus<1000;