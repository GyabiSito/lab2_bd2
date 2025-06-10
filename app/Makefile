# Makefile para compilar con ecpg y gcc, con objetos en /output

CC = gcc
CFLAGS = -I/usr/include/postgresql
LIBS = -lecpg

PGC_SRCS = main.pgc db_singleton.pgc
C_SRCS = main.c db_singleton.c

# Carpeta donde guardamos los objetos
OBJDIR = output

# Archivos objeto en output/
OBJS = $(patsubst %.c,$(OBJDIR)/%.o,$(C_SRCS))

TARGET = programa

# Crear carpeta output si no existe
$(shell mkdir -p $(OBJDIR))

all: $(TARGET)

# Regla para generar .c desde .pgc con ecpg
%.c: %.pgc
	ecpg $<

# Compilar .c a .o en output/
$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Linkeo final
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $@

clean:
	rm -rf $(OBJDIR)/*.o $(TARGET) *.c

.PHONY: all clean
