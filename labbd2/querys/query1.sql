SELECT
    a.nombre,
    COUNT(u.id_uso) AS total_usos
FROM
    usan u
    JOIN atracciones a ON u.id_atraccion = a.id_atraccion
WHERE
    u.fecha_usa BETWEEN '2025-01-01' AND '2025-05-28'
GROUP BY
    a.id_atraccion,
    a.nombre
ORDER BY
    total_usos DESC
LIMIT
    3;