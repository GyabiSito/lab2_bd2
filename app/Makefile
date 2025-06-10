# Compilador y flags
CC = gcc
CFLAGS = -I/usr/include/postgresql
LIBS = -lecpg

# Archivos fuente en .pgc
PGC_SRCS = $(wildcard *.pgc)

# Archivos generados .c
C_SRCS = $(PGC_SRCS:.pgc=.c)

# Directorio de objetos
OBJDIR = output
OBJS = $(patsubst %.c,$(OBJDIR)/%.o,$(C_SRCS))

# Ejecutable
TARGET = programa

# Asegura que exista la carpeta output/
$(shell mkdir -p $(OBJDIR))

all: $(TARGET)

# Regla para convertir .pgc → .c
%.c: %.pgc
	ecpg $<

# Compilar .c → .o dentro de output/
$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Linkeo final
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $@

# Ejecutar
run: $(TARGET)
	./$(TARGET)

# Limpiar todo
clean:
	rm -f *.c $(OBJDIR)/*.o $(TARGET)

.PHONY: all run clean
