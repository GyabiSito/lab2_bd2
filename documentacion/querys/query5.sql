SELECT 
    pa.nombre AS parque,
    u.fecha_usa,
    COUNT(*) AS cantidad_entretenimientos_usados
FROM 
    usan u
JOIN 
    atracciones a ON u.id_atraccion = a.id_atraccion
JOIN 
    parques pa ON a.id_parque = pa.id_parque
WHERE 
    u.fecha_usa BETWEEN DATE '2025-01-01' AND DATE '2025-12-31'
GROUP BY 
    pa.nombre, u.fecha_usa
ORDER BY 
    pa.nombre;
