# Write your MySQL query statement below
select name as 'Customers'
from Customers
where Customers.id not in (
    select Customers.id as 'id'
    from Customers
    right join Orders
    on Orders.customerId = Customers.id
);


