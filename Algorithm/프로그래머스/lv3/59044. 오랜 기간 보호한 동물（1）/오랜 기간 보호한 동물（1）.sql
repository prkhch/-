-- 코드를 입력하세요

SELECT T.NAME, T.DATETIME -- 7 : 이름과 시간 출력
FROM (SELECT INS.NAME, INS.DATETIME -- 4 : 해당 동물 이름, 들어온 시간을 선택
      FROM ANIMAL_INS INS -- 1 : 들어온 동물
      LEFT JOIN ANIMAL_OUTS OUTS ON INS.ANIMAL_ID = OUTS.ANIMAL_ID -- 2 : LEFT JOIN, ID기준 
      WHERE OUTS.ANIMAL_ID IS NULL  -- 3 : 나간 적이 없으면
      ORDER BY INS.DATETIME) T -- 5 : 시간순으로 정렬하고 이 전체를 T로 저장
-- 6 : 그 중 상위 3레코드만
WHERE ROWNUM <= 3;