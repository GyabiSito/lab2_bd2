SELECT 
    cl.ci AS documento_cliente,
    pp.fecha_acceso,
    pa.nombre AS parque
FROM 
    clientes cl
JOIN 
    compras c ON cl.id_cliente = c.id_cliente
JOIN 
    pases p ON c.id_compra = p.id_compra
JOIN 
    pases_parques pp ON p.id_pase = pp.id_pase
JOIN 
    parques pa ON pp.id_parque = pa.id_parque
WHERE 
    cl.ci = '92799897'
ORDER BY 
    pp.fecha_acceso, pa.nombre; 