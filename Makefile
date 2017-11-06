RM = rm -rf

CC=g++

LIB_DIR=./lib
INC_DIR=./include
SRC_DIR=./src
OBJ_DIR=./build
BIN_DIR=./bin
DOC_DIR=./doc
TEST_DIR=./test


CFLAGS = -Wall -pedantic -ansi -std=c++11 -I. -I$(INC_DIR)

.PHONY: all init clean doxy debug doc 

all: init questao1 questao2 questao3

debug: CFLAGS += -g -O0
debug: all

init:
	@mkdir -p $(OBJ_DIR)/questao1
	@mkdir -p $(OBJ_DIR)/questao2
	@mkdir -p $(OBJ_DIR)/questao3
	@mkdir -p $(BIN_DIR)/

questao1: CFLAGS+= -I$(INC_DIR)/questao1
questao1: $(OBJ_DIR)/questao1/main.o
	@echo "-----------------"
	@echo "Alvo $@"
	@echo "------------------"
	$(CC) $(CFLAGS) -o $(BIN_DIR)/questao1 $^
	@echo "------------------"
	@echo "+++ [Executavel 'questao1' criado em $(BIN_DIR)] +++"
	@echo "------------------" 
	
$(OBJ_DIR)/questao1/main.o: $(SRC_DIR)/questao1/main.cpp $(INC_DIR)/questao1/intervalo.h
	$(CC) -c $(CFLAGS) -o $@ $<

questao2: CFLAGS+= -I$(INC_DIR)/questao2
questao2: $(OBJ_DIR)/questao2/main.o
	@echo "-----------------"
	@echo "Alvo $@"
	@echo "------------------"
	$(CC) $(CFLAGS) -o $(BIN_DIR)/questao2 $^
	@echo "------------------"
	@echo "+++ [Executavel 'questao2' criado em $(BIN_DIR)] +++"
	@echo "------------------" 

$(OBJ_DIR)/questao2/main.o: $(SRC_DIR)/questao2/main.cpp $(INC_DIR)/questao2/imprime.h
	$(CC) -c $(CFLAGS) -o $@ $<	

questao3: CFLAGS+= -I$(INC_DIR)/questao3
questao3: $(OBJ_DIR)/questao3/main.o
	@echo "-----------------"
	@echo "Alvo $@"
	@echo "------------------"
	$(CC) $(CFLAGS) -o $(BIN_DIR)/questao3 $^
	@echo "------------------"
	@echo "+++ [Executavel 'questao3' criado em $(BIN_DIR)] +++"
	@echo "------------------" 

$(OBJ_DIR)/questao3/main.o: $(SRC_DIR)/questao3/main.cpp $(INC_DIR)/questao3/primos.h
	$(CC) -c $(CFLAGS) -o $@ $<	
	
doxy:
	doxygen -g

doc:
	$(RM) $(DOC_DIR)/*
	doxygen

clean:
	$(RM) $(BIN_DIR)/*
	$(RM) $(OBJ_DIR)/*