# Write your MySQL query statement below
SELECT id , count(id) AS num FROM(
(SELECT requester_id as id FROM RequestAccepted)
UNION ALL
(SELECT accepter_id as id FROM RequestAccepted)) as A
GROUP BY id
ORDER BY num DESC LIMIT 1;

