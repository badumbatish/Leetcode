# Write your MySQL query statement below
SELECT t1.user_id, IFNULL(confirmation_rate, 0) as confirmation_rate FROM Signups t1
LEFT JOIN (
SELECT user_id, SUM(action = 'confirmed') / COUNT(action) as confirmation_rate FROM Confirmations 
GROUP BY user_id) t2
ON t1.user_id = t2.user_id