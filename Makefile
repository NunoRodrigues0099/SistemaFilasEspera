
#Compilador
CC = gcc
#Opções de Compilação
CFLAGS = -Wall
#Executável
EXE = proj
#Ficheiros objeto
OBJ = fila.o lista.o simulacao.o proj.o
#Dependências
DEP = fila.h lista.h simulacao.h


.PHONY: all clean run

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(OBJ) -o$(EXE) -lm
	
$(OBJ): $(DEP)

run:
	clear
	./$(EXE)
	
clean:
	-rm $(EXE) $(OBJ)
