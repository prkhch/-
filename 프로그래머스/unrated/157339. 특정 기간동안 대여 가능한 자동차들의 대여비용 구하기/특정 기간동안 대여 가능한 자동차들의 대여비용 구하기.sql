SELECT T.CAR_ID, T.CAR_TYPE, T.FEE
  -- C:자동차 정보, HST:대여 기록, DCNT:할인 정보
  FROM (SELECT C.CAR_ID, C.CAR_TYPE, (C.DAILY_FEE * (1 - DCNT.DISCOUNT_RATE / 100))  * 30  AS FEE -- 9. ID, TYPE, FEE(일일 대여 요금 * 할인율 * 30일)를 갖는 T 생성
        FROM CAR_RENTAL_COMPANY_CAR C, CAR_RENTAL_COMPANY_RENTAL_HISTORY HST, CAR_RENTAL_COMPANY_DISCOUNT_PLAN DCNT
        WHERE C.CAR_ID = HST.CAR_ID(+) -- 8.  (+) : OUTER조인
        AND C.CAR_TYPE = DCNT.CAR_TYPE -- 7. DCNT.차량타입과 일치하고
        AND C.CAR_TYPE IN ('세단','SUV') -- 6. 세단 또는 SUV만
        AND DCNT.DURATION_TYPE = '30일 이상' -- 5. 30일 이상
        AND NOT EXISTS (SELECT HST.CAR_ID -- 4. NOT EXISTS 11월 달에 사용하지 않는 차량
                        FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY HST -- 1. HST테이블에서
                        WHERE HST.CAR_ID = C.CAR_ID -- 2. 같은 자동차ID 이면서
                        AND TO_CHAR(START_DATE, 'YYYYMMDD') <= '20221130' AND TO_CHAR(END_DATE, 'YYYYMMDD') >= '20221101')
                        -- 3. 11월 30일 이전에 대여하고, 11월 1일 이후에 반납한 차량 (즉, 11월 달에 사용중인 차량)
																												        /* <----------------------------
																												                 ----------------------|---------->
																												                 |                     |
																												                11.01               11.30 */

        ) T
GROUP BY T.CAR_ID, T.CAR_TYPE, T.FEE -- 10 : 그룹화, 그룹화 안하고 WHERE 사용시 값이 중복되어 나옴
HAVING T.FEE >= 500000 AND T.FEE < 2000000 -- 11 : 50만원이상 200만원 미만 
ORDER BY T.FEE DESC, T.CAR_TYPE ASC, T.CAR_ID DESC -- 12 : 정렬