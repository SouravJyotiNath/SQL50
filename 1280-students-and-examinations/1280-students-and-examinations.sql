# Write your MySQL query statement below
SELECT s1.student_id , s1.student_name , s2.subject_name , 
COUNT(e.subject_name) AS attended_exams
FROM Students s1
CROSS JOIN Subjects s2
LEFT JOIN Examinations e
ON s1.student_id=e.student_id
AND e.subject_name=s2.subject_name
GROUP BY s1.student_id , s1.student_name , s2.subject_name
ORDER BY s1.student_id , s1.student_name