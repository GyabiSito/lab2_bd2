SELECT
    a.id_atraccion,
    a.nombre AS nombre_atraccion,
    COUNT(*) AS veces_utilizado
FROM (
    SELECT
        p.id_visitante,
        u.id_atraccion
    FROM
        usan u
    JOIN pases p ON u.id_pase = p.id_pase
    WHERE
        u.fecha_usa BETWEEN '2025-01-01' AND '2025-12-31'
    GROUP BY
        p.id_visitante, u.id_atraccion
    HAVING
        COUNT(*) > 1
) sub
JOIN atracciones a ON sub.id_atraccion = a.id_atraccion
GROUP BY
    a.id_atraccion, a.nombre
ORDER BY
    veces_utilizado DESC;


