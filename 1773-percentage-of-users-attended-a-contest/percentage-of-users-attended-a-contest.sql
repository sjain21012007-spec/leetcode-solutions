# Write your MySQL query statement below
SELECT contest_id , ROUND((COUNT(User_id)*100.0)/(SELECT COUNT(*)FROM Users),2) AS PERCENTAGE
FROM Register 
GROUP BY contest_id
ORDER BY PERCENTAGE DESC,contest_id ASC;