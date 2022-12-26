# Write your MySQL query statement below
select sell_date,count(distinct(product)) as num_sold,
GROUP_CONCAT(DISTINCT product order by product asc separator ',') as products
from Activities GROUP BY sell_date;