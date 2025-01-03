# Write your MySQL query statement below
SELECT Department , Employee , Salary
FROM
(SELECT d.name AS department , e.name as employee , e.salary AS salary ,
DENSE_RANK() OVER(PARTITION BY d.name ORDER BY e.salary DESC) AS ranks
FROM Employee e
LEFT JOIN Department d
ON e.departmentId = d.id) AS new_Table
WHERE ranks <= 3