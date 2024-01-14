SELECT MEMBER_ID, MEMBER_NAME, GENDER, DATE_FORMAT(DATE_OF_BIRTH, '%Y-%m-%d')
FROM MEMBER_PROFILE
WHERE TLNO IS NOT NULL  AND DATE_FORMAT(DATE_OF_BIRTH, '%m') = '03' AND GENDER = 'W' 
ORDER BY MEMBER_ID