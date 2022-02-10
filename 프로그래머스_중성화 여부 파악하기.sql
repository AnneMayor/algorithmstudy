SELECT A.ANIMAL_ID, A.NAME, CASE WHEN A.SEX_UPON_INTAKE REGEXP("Neutered|Spayed") THEN "O"
                            ELSE "X"
                            END AS "중성화"
FROM ANIMAL_INS A
ORDER BY A.ANIMAL_ID;