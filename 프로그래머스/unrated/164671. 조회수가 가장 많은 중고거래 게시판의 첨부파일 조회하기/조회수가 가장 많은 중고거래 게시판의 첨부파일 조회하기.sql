-- -- 코드를 입력하세요
SELECT '/home/grep/src/' || F.BOARD_ID || '/' || F.FILE_ID || F.FILE_NAME || F.FILE_EXT AS FILE_PATH
FROM USED_GOODS_FILE F -- 2. 그 게시글의 파일들
INNER JOIN (SELECT BOARD_ID -- 1. T는 가장 큰 조회수 게시글
            FROM USED_GOODS_BOARD
            WHERE VIEWS = (SELECT MAX(VIEWS)
                           FROM USED_GOODS_BOARD)) T ON T.BOARD_ID = F.BOARD_ID
                           
ORDER BY F.FILE_ID DESC