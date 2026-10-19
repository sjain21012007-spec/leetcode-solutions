# Write your MySQL query statement below
SELECT c.category , COALESCE(COUNT(a.account_id),0) AS accounts_count
FROM (
    SELECT 'Low Salary' AS category
    UNION ALL
    SELECT 'Average Salary'
    UNION ALL
    SELECT 'High Salary'
) c
LEFT JOIN 
(SELECT account_id , CASE 
                          WHEN income<20000 THEN "Low Salary"
                          WHEN income>=20000 AND income<=50000 THEN "Average Salary"
                          WHEN income > 50000  THEN "High Salary"
                          ELSE "null"
                          END AS category
FROM Accounts) a on c.category = a.category
GROUP BY c.category;