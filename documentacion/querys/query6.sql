SELECT
    TO_CHAR(a.fecha_accede, 'FMDay') AS dia_semana,
    EXTRACT(ISODOW FROM a.fecha_accede) AS orden_dia,
    COUNT(*) AS total_accesos
FROM acceden a
WHERE a.entrada_salida = 'E'
  AND a.fecha_accede BETWEEN DATE '2025-01-01' AND DATE '2025-12-31'
  AND a.id_parque = 2
GROUP BY TO_CHAR(a.fecha_accede, 'FMDay'), EXTRACT(ISODOW FROM a.fecha_accede)
ORDER BY total_accesos DESC
LIMIT 2;

--Extract extrae una parte especifica de la fecha, ya sea su año, mes, dia. El DOW es el dia de la semana pero en numerico, 0=domingo, 6=sabado
--Como precisamos que sea el DIA, usamos el TO_CHAR que agarra una fecha y la traduce al formato que precisemos, en este caso solo el dia
--El TRIM esta para sacar el espacio que esta al final de TO_CHAR que por alguna razon le mete un padding ahi