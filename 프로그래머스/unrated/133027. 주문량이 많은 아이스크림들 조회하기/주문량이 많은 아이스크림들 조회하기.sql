SELECT T.FLAVOR -- 8. T.맛 출력 
FROM (SELECT FH.FLAVOR, SUM(FH.TOTAL_ORDER) + SUM(J.TOTAL_ORDER) AS TOTAL 
				-- 4. 해당 맛 그룹과 그 맛 그룹의 상반기와 7월 주문량의 합 출력
      FROM FIRST_HALF FH -- 1. FH테이블로부터
      LEFT OUTER JOIN JULY J ON FH.FLAVOR = J.FLAVOR -- 2. 맛이 같은 조건에 J테이블을 조인
      GROUP BY FH.FLAVOR -- 3. 맛을 기준으로 그룹화
      ORDER BY TOTAL DESC -- 5. TOTAL 내림차순 정렬(상위부터)
      ) T -- 6. 이게 T테이블
WHERE ROWNUM <= 3; 