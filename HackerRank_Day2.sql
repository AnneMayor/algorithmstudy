SELECT DISTINCT CITY
FROM STATION
WHERE CITY REGEXP '[a,e,i,o,u]$'

-- 시작과 끝이 모두 모음인 경우 쿼리문 --
SELECT DISTINCT CITY
FROM STATION
WHERE CITY REGEXP '^[AEIOUaeiou]($|.*[AEIOUaeiou]$)';

-- 시작 문자로 모음이 오지 않는 경우 쿼리문 --
SELECT DISTINCT CITY
FROM STATION
WHERE CITY REGEXP '^[^AEIOUaeiou]';

SELECT DISTINCT CITY
FROM STATION
WHERE CITY REGEXP '[^AEOIUaeoiu]$';

SELECT DISTINCT CITY
FROM STATION
WHERE CITY REGEXP '[^AEOIUaeoiu]$';

SELECT DISTINCT CITY
FROM STATION
WHERE CITY REGEXP '(^[^AEOIUaeoiu]|[^AEOIUaeoiu]$)';

SELECT DISTINCT CITY
FROM STATION
WHERE CITY REGEXP '(^[^AEOIUaeoiu])($|.*[^AEOIUaeoiu]$)';

SELECT Name
FROM STUDENTS
WHERE Marks > 75
ORDER BY right(Name, 3), ID;

SELECT name
FROM Employee
ORDER BY name;

SELECT name
FROM Employee
WHERE salary > 2000 AND months < 10
ORDER BY employee_id;

-- Advanced Quary: Hierarchy SQL --
SELECT C.company_code, C.founder, count(DISTINCT lead_manager_code), count(DISTINCT senior_manager_code), count(DISTINCT managers_code), count(DISTINCT employee_code)
FROM Company C INNER JOIN Employee E ON C.company_code = E.company_code
GROUP BY C.company_code, C.founder
ORDER BY C.company_code;