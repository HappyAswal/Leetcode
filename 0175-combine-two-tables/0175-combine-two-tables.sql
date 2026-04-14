# Write your MySQL query statement below
Select a.firstName, a.lastName, b.city, b.state from Person a
LEFT JOIN Address b ON  a.personID=b.personID