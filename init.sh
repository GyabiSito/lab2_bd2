#!/bin/bash

echo "🛠️ Instalando dependencias necesarias..."

apt-get update && apt-get install -y \
  libecpg-dev \
  postgresql-client \
  postgresql-contrib \
  build-essential \
  vim \
  net-tools \
  iputils-ping \
  make

echo "✅ Instalación completa."

# Ejecutar "make run"