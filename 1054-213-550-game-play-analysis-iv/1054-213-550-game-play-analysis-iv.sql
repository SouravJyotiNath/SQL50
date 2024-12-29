# Write your MySQL query statement below
SELECT ROUND(SUM(difference)/COUNT(DISTINCT(player_id)),2) AS fraction
FROM
(SELECT player_id ,
DATEDIFF(event_date , MIN(event_date) OVER(PARTITION BY player_id))=1 AS difference
FROM Activity) AS new_table 