# Write your MySQL query statement below
SELECT b.name
FROM Employee a
INNER JOIN Employee b
ON a.managerId  = b.id
GROUP BY b.id , b.name  
HAVING COUNT(a.id) >=5;