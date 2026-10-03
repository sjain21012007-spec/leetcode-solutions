# Write your MySQL query statement below
SELECT a.name,b.bonus
FROM Employee a
LEFT JOIN Bonus b 
ON a.empId = b.empId 
WHERE bonus<1000
or bonus is null
