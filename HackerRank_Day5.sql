SELECT country.CONTINENT, FLOOR(AVG(city.POPULATION))
FROM CITY AS city INNER JOIN COUNTRY AS country ON city.COUNTRYCODE = country.CODE
GROUP BY country.CONTINENT;

SELECT IF(GRADE < 8, 'NULL', NAME), GRADE, MARKS
FROM Students INNER JOIN Grades
WHERE MARKS BETWEEN MIN_MARK AND MAX_MARK
ORDER BY GRADE DESC, NAME;

--- 다중 group by 지원, 다중 inner join 문제: Top Competitors from HackerRank ---
SELECT H.hacker_id, H.name
FROM Submissions AS S
            INNER JOIN Challenges AS C ON C.challenge_id = S.challenge_id
            INNER JOIN Difficulty AS D ON C.difficulty_level = D.difficulty_level
            INNER JOIN Hackers AS H ON H.hacker_id = S.hacker_id
WHERE S.score = D.score AND C.difficulty_level = D.difficulty_level AND C.challenge_id = S.challenge_id
GROUP BY H.hacker_id, H.name
    HAVING COUNT(S.challenge_id) > 1
ORDER BY COUNT(S.challenge_id) DESC, S.hacker_id ASC;

--- 서브쿼리 연습 ---
SELECT W.id, P.age, W.coins_needed, W.power
FROM Wands AS W INNER JOIN Wands_Property AS P ON W.code = P.code
WHERE P.is_evil = 0 AND W.coins_needed = (SELECT MIN(coins_needed) FROM Wands AS W1 INNER JOIN Wands_Property 
AS P1 ON W1.code = P1.code WHERE P1.is_evil = 0 AND P1.age = P.age AND W1.power = W.power)
ORDER BY W.power DESC, P.age DESC;

--- 복잡한 서브쿼리 연습: Challenges from HackerRank ---
SELECT C.hacker_id, H.name, COUNT(C.hacker_id) as c_count
FROM Hackers H INNER JOIN Challenges C ON H.hacker_id = C.hacker_id
GROUP BY C.hacker_id, H.name
HAVING c_count = (
    SELECT MAX(C1.challenge_created) FROM (
        SELECT COUNT(hacker_id) AS challenge_created 
        FROM Challenges 
        GROUP BY hacker_id) C1)
    OR c_count IN (
        SELECT C1.challenge_created FROM (
            SELECT COUNT(hacker_id) AS challenge_created 
            FROM Challenges 
            GROUP BY hacker_id) C1 
        GROUP BY C1.challenge_created 
        HAVING COUNT(C1.challenge_created) = 1)
ORDER BY c_count DESC, C.hacker_id;