#!/bin/bash

echo "🛠️ Instalando dependencias necesarias..."

apt-get update && apt-get install -y \
    libecpg-dev \
    postgresql-client \
    vim \
    net-tools \
    iputils-ping

echo "✅ Instalación completa."

# Ejecutar el script de compilación
if [ -f /app/compilar.sh ]; then
  /app/compilar.sh
else
  echo "❌ compilar.sh no encontrado en /app"
fi