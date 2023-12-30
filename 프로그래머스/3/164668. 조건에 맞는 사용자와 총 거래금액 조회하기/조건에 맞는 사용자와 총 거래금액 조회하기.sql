SELECT GU.USER_ID, GU.NICKNAME, UB.TOTAL_SALES
FROM USED_GOODS_USER GU INNER JOIN (SELECT WRITER_ID, SUM(PRICE) AS TOTAL_SALES
                                    FROM USED_GOODS_BOARD
                                    GROUP BY WRITER_ID, STATUS
                                    HAVING STATUS LIKE 'DONE' AND SUM(PRICE) >= 700000) UB 
                                    ON GU.USER_ID = UB.WRITER_ID
ORDER BY UB.TOTAL_SALES ASC