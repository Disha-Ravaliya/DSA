# Write your MySQL query statement below
# Write your MySQL query statement below
SELECT 
    Today.id
FROM 
    Weather Today
JOIN 
    Weather Yesterday 
    ON DATEDIFF(Today.recordDate, Yesterday.recordDate) = 1
WHERE 
    Today.temperature > Yesterday.temperature;