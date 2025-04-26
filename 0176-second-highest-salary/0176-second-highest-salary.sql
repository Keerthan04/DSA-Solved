# Write your MySQL query statement below
select Max(salary) as SecondHighestSalary From Employee where salary <> (Select Max(salary) from Employee);