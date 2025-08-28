SELECT
    CASE
        WHEN
            id = (SELECT MAX(id) FROM seat) AND MOD(id , 2) = 1#when last one and odd then that id only
            THEN id
        WHEN 
            MOD(id , 2) = 1#for each odd ones it will be the next one
            THEN id + 1
        ELSE 
            id - 1#for even ones will be previous
    END AS id, student
FROM Seat
ORDER BY id;