# Write your MySQL query statement below
select name as Customers from Customers c where id not in (select customerId from Customers c join Orders o on c.id = o.customerId);