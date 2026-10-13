# Write your MySQL query statement below
SELECT ROUND(COUNT(DISTINCT b.player_id)/COUNT(DISTINCT a.player_id),2)  AS fraction   FROM (
SELECT player_id, MIN(event_date) AS event_date from Activity 
Group by player_id) a
LEFT JOIN Activity b 
ON a.player_id = b.player_id AND date_add(a.event_date, interval 1 day)=b.event_date;
