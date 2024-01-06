SELECT TO_NUMBER(TO_CHAR(C.START_DATE, 'MM')) AS MONTH, C.CAR_ID, COUNT(*) AS RECORDS
FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY C
INNER JOIN (SELECT CAR_ID, COUNT(*)
            FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY 
            WHERE TO_CHAR(START_DATE, 'YYYYMM') >= '202208' AND TO_CHAR(START_DATE, 'YYYYMM') <= '202210'
            GROUP BY CAR_ID HAVING COUNT(*) >= 5) G ON C.CAR_ID = G.CAR_ID
WHERE TO_CHAR(START_DATE, 'YYYYMM') >= '202208' AND TO_CHAR(START_DATE, 'YYYYMM') <= '202210'
GROUP BY TO_CHAR(C.START_DATE, 'MM'), C.CAR_ID
ORDER BY MONTH ASC, CAR_ID DESC