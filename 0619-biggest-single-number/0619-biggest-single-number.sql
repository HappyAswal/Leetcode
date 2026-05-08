# Write your MySQL query statement below

WITH CTE as(
SELECT num from MyNumbers
GROUP BY num
HAVING COUNT(*)=1
)
SELECT MAX(num) as num from cte;
