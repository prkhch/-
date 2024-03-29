SELECT A.CATEGORY, S.MAX_PRICE, A.PRODUCT_NAME
FROM FOOD_PRODUCT A
INNER JOIN (SELECT CATEGORY, MAX(PRICE) AS MAX_PRICE
            FROM FOOD_PRODUCT
            WHERE CATEGORY IN ('과자', '국', '김치', '식용유')
            GROUP BY CATEGORY) S ON A.CATEGORY = S.CATEGORY
WHERE A.CATEGORY = S.CATEGORY AND A.PRICE = S.MAX_PRICE
ORDER BY S.MAX_PRICE DESC

