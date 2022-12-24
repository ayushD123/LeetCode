# Write your MySQL query statement below
select user_id, concat(UPPER(substr(name,1,1)),LOWER(substr(name,2))) as name from Users
ORDER BY
user_id;