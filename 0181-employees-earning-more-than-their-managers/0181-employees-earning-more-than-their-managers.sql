# Write your MySQL query statement below
select e.name as Employee from Employee e  
Join Employee f ON e.managerId=f.id
WHERE f.salary < e.salary