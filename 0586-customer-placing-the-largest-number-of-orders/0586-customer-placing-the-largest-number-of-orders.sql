select customer_number from orders group by customer_number having count(*)=
(
select max(count) from (select count(order_number) as count from orders group by customer_number) tmp ) ;