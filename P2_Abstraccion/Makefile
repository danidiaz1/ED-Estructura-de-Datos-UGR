SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -std=c++11 -Wall -g -I$(INC) -c


all: $(BIN)/prueba

# ************ Generación de documentación ******************
documentacion:
	doxygen Doxyfile

	
# ************ Compilación de módulos ************
$(BIN)/prueba : $(OBJ)/pruebacronologia.o $(OBJ)/fechahistorica.o $(OBJ)/cronologia.o 
	$(CXX) -o $(BIN)/prueba $(OBJ)/pruebacronologia.o $(OBJ)/fechahistorica.o $(OBJ)/cronologia.o

$(OBJ)/pruebacronologia.o : $(INC)/cronologia.h $(INC)/fechahistorica.h $(SRC)/pruebacronologia.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/pruebacronologia.o $(SRC)/pruebacronologia.cpp

$(OBJ)/cronologia.o : $(INC)/cronologia.h $(INC)/fechahistorica.h $(SRC)/cronologia.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/cronologia.o $(SRC)/cronologia.cpp

$(OBJ)/fechahistorica.o : $(INC)/fechahistorica.h $(SRC)/fechahistorica.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/fechahistorica.o $(SRC)/fechahistorica.cpp

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~ $(BIN)/*

mrproper : clean
	-rm $(BIN)/* doc/html/*
