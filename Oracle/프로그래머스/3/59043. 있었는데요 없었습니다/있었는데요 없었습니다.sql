SELECT AO.ANIMAL_ID, AO.NAME
FROM ANIMAL_INS AI
INNER JOIN ANIMAL_OUTS AO ON AI.ANIMAL_ID = AO.ANIMAL_ID
WHERE AO.DATETIME < AI.DATETIME
ORDER BY AI.DATETIME