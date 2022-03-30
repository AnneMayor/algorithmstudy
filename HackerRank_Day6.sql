SELECT h.hacker_id, h.name, SUM(scores) AS total_score
from Hackers AS h INNER JOIN 
(SELECT s.hacker_id, MAX(s.score) AS scores FROM Submissions AS s GROUP BY s.challenge_id, s.hacker_id) AS S
ON h.hacker_id = S.hacker_id
GROUP BY h.hacker_id, h.name
HAVING total_score > 0
ORDER BY total_score DESC, h.hacker_id;

---

SELECT CASE WHEN A + B > C AND B + C > A AND A + C > B THEN
            CASE
                WHEN A = B AND B = C THEN 'Equilateral'
                WHEN A = B OR B = C OR A = C THEN 'Isosceles'
                ELSE 'Scalene'
                END
            ELSE 'Not A Triangle'
            END
FROM TRIANGLES;

---

SELECT CONCAT(name, '(',SUBSTR(occupation, 1, 1), ')')
FROM OCCUPATIONS
ORDER BY name;

SELECT CONCAT('There are a total of ', COUNT(*), ' ', LCASE(occupation), 's.')
FROM OCCUPATIONS
GROUP BY occupation
ORDER BY COUNT(*), occupation;

--- 인덱스 설정 및 탐색 ---

SET @r1 := 0, @r2 := 0, @r3 := 0, @r4 := 0;

SELECT MIN(Doctor), MIN(Professor), MIN(Singer), MIN(Actor)
FROM (SELECT CASE WHEN occupation = 'Doctor' THEN (@r1 := @r1 + 1)
            WHEN occupation = 'Professor' THEN (@r2 := @r2 + 1)
            WHEN occupation = 'Singer' THEN (@r3 := @r3 + 1)
            WHEN occupation = 'Actor' THEN (@r4 := @r4 + 1) END AS RowNumbers,
       CASE WHEN occupation = 'Doctor' THEN name END AS Doctor,
       CASE WHEN occupation = 'Professor' THEN name END AS Professor,
       CASE WHEN occupation = 'Singer' THEN name END AS Singer,
       CASE WHEN occupation = 'Actor' THEN name END AS Actor
      FROM OCCUPATIONS
      ORDER BY name) AS temp
GROUP BY RowNumbers;