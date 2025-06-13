CREATE MATERIALIZED VIEW vista_ingresos_2024 AS
SELECT
    pa.id_parque,
    pa.nombre AS nombre_parque,
    COUNT(DISTINCT pp.id_pase) AS cantidad_entradas,
    ROUND(
        SUM(
            pr.precio + 
            CASE 
                WHEN pp.incluye_parking THEN COALESCE(park.costo_adicional, 0)
                ELSE 0
            END
        ) / 40.0, 2
    ) AS ingreso_usd
FROM
    pases_parques pp
JOIN parques pa ON pp.id_parque = pa.id_parque
JOIN precios pr ON pp.id_precio = pr.id_precio
JOIN pases p ON pp.id_pase = p.id_pase
JOIN compras c ON p.id_compra = c.id_compra
LEFT JOIN parkings park ON pa.id_parque = park.id_parque
WHERE
    c.fecha_compra BETWEEN '2025-01-01' AND '2025-12-31'
GROUP BY
    pa.id_parque, pa.nombre
ORDER BY
    pa.id_parque;