# Write your MySQL query statement below
select max(salary) as SecondHighestSalary from Employee
Where salary<(Select max(salary) from Employee)