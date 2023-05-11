-- 나간 동물 정보에는 있는데 들어온 동물 정보에는 없다.
-- 나간 동물 정보 ⊃ 들어온 동물 정보

SELECT OUTS.ANIMAL_ID, OUTS.NAME -- 3 : 그 동물의 ID와 NAME 출력
FROM ANIMAL_INS INS, ANIMAL_OUTS OUTS -- 1 : 들어온 동물 정보, 나간 동물 정보
WHERE INS.ANIMAL_ID(+) =  OUTS.ANIMAL_ID AND INS.ANIMAL_ID IS NULL
-- 2: OUTER조인하여 들어온 동물ID와 나간 동물ID가 같으면서 AND 들어온 동물ID가 NULL 값이면

ORDER BY ANIMAL_ID;