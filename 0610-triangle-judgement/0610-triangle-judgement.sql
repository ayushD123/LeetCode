# Write your MySQL query statement below
select x,y,z,
case
    when x+y<=z OR x+z<=y OR y+z<=x then "No"
    else "Yes"
    END as triangle
from triangle;