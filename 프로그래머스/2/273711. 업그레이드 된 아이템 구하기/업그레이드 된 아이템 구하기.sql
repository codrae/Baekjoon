-- 코드를 작성해주세요
SELECT A.ITEM_ID, ITEM_NAME, RARITY
FROM ITEM_INFO A
WHERE A.ITEM_ID IN (
    SELECT ITEM_ID
    FROM ITEM_TREE
    WHERE PARENT_ITEM_ID IN (
        SELECT ITEM_ID  
        FROM ITEM_INFO
        WHERE RARITY = 'RARE'
    )
)
ORDER BY A.ITEM_ID DESC