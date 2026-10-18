# Write your MySQL query statement below
SELECT num AS ConsecutiveNums
FROM (
    SELECT num,
    LAG(num) OVER (ORDER BY ID) AS pn,
    LEAD(num) OVER (ORDER BY ID) AS fn
    FROM Logs
) AS vt
WHERE num = pn AND num =fn
GROUP BY num;