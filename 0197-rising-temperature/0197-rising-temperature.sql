# Write your MySQL query statement below
select b.id from weather a,weather b where datediff(b.recorddate,a.recorddate)=1 and b.temperature>a.temperature; 