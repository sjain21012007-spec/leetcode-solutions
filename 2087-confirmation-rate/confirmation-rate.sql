# Write your MySQL query statement below
SELECT a.user_id ,
ROUND(SUM(CASE WHEN b.action = 'confirmed ' THEN 1.0 ELSE 0.0 END)/COUNT(*),2) AS confirmation_rate
FROM Signups a 
LEFT JOIN Confirmations b
ON a.user_id = b.user_id
GROUP BY a.user_id;    