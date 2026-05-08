# Write your MySQL query statement below
SELECT class from COURSES
GROUP BY class
Having count(class)>=5;