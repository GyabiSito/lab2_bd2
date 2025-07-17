SELECT 
    SUM(p.precio_total) AS total_ingresos  

FROM 
    pases p  

JOIN 
    compras c ON p.id_compra = c.id_compra  

WHERE 
    c.fecha_compra BETWEEN '2025-01-01' AND '2025-12-31'; 