SELECT TO_CHAR(SALES_DATE,'YYYY') AS YEAR, 
       TO_NUMBER(TO_CHAR(SALES_DATE,'MM')) AS MONTH, 
       COUNT(DISTINCT OS.USER_ID) AS PUCHASED_USERS,
       ROUND(COUNT(DISTINCT OS.USER_ID)/(SELECT COUNT(DISTINCT USER_ID)
                                         FROM USER_INFO 
                                         WHERE TO_CHAR(JOINED,'YYYY') = '2021'),1) AS PUCHASED_USERS 
                                         -- 5. ROUND(온라인 판매 수 / 2021년 유저 수 , 1) : 소수 두번째 반올림 DISTINCT로 중복 레코드 제거
FROM ONLINE_SALE OS -- 1. 온라인 판매 테이블
INNER JOIN USER_INFO UI ON OS.USER_ID = UI.USER_ID  -- 2. 유저ID로 유저 정보 이너 조인
WHERE TO_CHAR(UI.JOINED,'YYYY') = '2021' -- 3. 유저 가입년도 2021년
GROUP BY TO_CHAR(SALES_DATE,'YYYY'),TO_NUMBER(TO_CHAR(SALES_DATE,'MM')) 
-- 4. 판매 년도, 월을 기준으로 그룹화 / TO_NUMBER(월 '03' => '3')
ORDER BY YEAR, MONTH