SELECT SUM(population)
FROM city
WHERE countrycode = 'JPN';

SELECT MAX(population) - MIN(population)
FROM CITY;

SELECT CEIL(AVG(salary) - AVG(REPLACE(salary, '0', '')))
FROM employees;

--- 요거 좀 신기한 Aggregation 문제 ---
SELECT salary*months as earnings, SPACE(2), COUNT(*)
FROM employee
GROUP BY earnings
ORDER BY earnings DESC
LIMIT 1;

SELECT ROUND(SUM(LAT_N), 2), ROUND(SUM(LONG_W), 2)
FROM STATION;