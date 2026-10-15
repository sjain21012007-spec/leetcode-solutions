# Write your MySQL query statement below
SELECT customer_id 
FROM Customer a,product b
GROUP BY a.customer_id
HAVING COUNT(distinct a.product_key) = COUNT(distinct b.product_key);