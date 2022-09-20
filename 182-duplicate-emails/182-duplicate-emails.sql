SELECT
    email AS 'Email'
FROM Person AS p
GROUP BY email
HAVING COUNT(*) > 1
;