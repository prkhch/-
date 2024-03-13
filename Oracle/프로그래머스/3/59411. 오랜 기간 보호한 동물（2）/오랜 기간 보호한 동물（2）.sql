SELECT ANIMAL_ID, NAME
FROM (SELECT AO.ANIMAL_ID, AO.NAME, (AO.DATETIME-AI.DATETIME) AS TIME
    FROM ANIMAL_INS AI
    INNER JOIN ANIMAL_OUTS AO ON AI.ANIMAL_ID = AO.ANIMAL_ID
    ORDER BY TIME DESC)
WHERE ROWNUM <= 2
