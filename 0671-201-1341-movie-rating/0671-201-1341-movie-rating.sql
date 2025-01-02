# Write your MySQL query statement below
(SELECT u.name AS results
FROM Users u
LEFT JOIN MovieRating mr
ON u.user_id = mr.user_id
GROUP BY u.user_id
ORDER BY COUNT(u.user_id) DESC , u.name limit 1)
UNION ALL
(SELECT m.title AS results
FROM Movies m
LEFT JOIN MovieRating mr
ON m.movie_id = mr.movie_id
WHERE EXTRACT(YEAR_MONTH FROM mr.created_at) = 202002
GROUP BY m.movie_id
ORDER BY AVG(mr.rating) DESC , m.title limit 1)