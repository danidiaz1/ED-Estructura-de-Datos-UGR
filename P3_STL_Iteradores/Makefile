SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -std=c++11 -Wall -g -I$(INC) -c


all: $(BIN)/union_cronologia $(BIN)/filtradoPalabraClave $(BIN)/filtradoIntervalo $(BIN)/estadisticaEventos

# ************ Generación de documentación ******************
documentacion:
	doxygen Doxyfile

	
# ************ Compilación de módulos ************

$(BIN)/union_cronologia : $(OBJ)/union_cronologia.o $(OBJ)/fechahistorica.o $(OBJ)/cronologia.o 
	$(CXX) -o $(BIN)/union_cronologia $(OBJ)/union_cronologia.o $(OBJ)/fechahistorica.o $(OBJ)/cronologia.o

$(BIN)/filtradoPalabraClave : $(OBJ)/filtradoPalabraClave.o $(OBJ)/fechahistorica.o $(OBJ)/cronologia.o 
	$(CXX) -o $(BIN)/filtradoPalabraClave $(OBJ)/filtradoPalabraClave.o $(OBJ)/fechahistorica.o $(OBJ)/cronologia.o

$(BIN)/filtradoIntervalo : $(OBJ)/filtradoIntervalo.o $(OBJ)/fechahistorica.o $(OBJ)/cronologia.o 
	$(CXX) -o $(BIN)/filtradoIntervalo $(OBJ)/filtradoIntervalo.o $(OBJ)/fechahistorica.o $(OBJ)/cronologia.o

$(BIN)/estadisticaEventos : $(OBJ)/estadisticaEventos.o $(OBJ)/fechahistorica.o $(OBJ)/cronologia.o 
	$(CXX) -o $(BIN)/estadisticaEventos $(OBJ)/estadisticaEventos.o $(OBJ)/fechahistorica.o $(OBJ)/cronologia.o

$(OBJ)/union_cronologia.o : $(INC)/cronologia.h $(INC)/fechahistorica.h $(SRC)/union_cronologia.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/union_cronologia.o $(SRC)/union_cronologia.cpp

$(OBJ)/filtradoPalabraClave.o : $(INC)/cronologia.h $(INC)/fechahistorica.h $(SRC)/filtradoPalabraClave.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/filtradoPalabraClave.o $(SRC)/filtradoPalabraClave.cpp

$(OBJ)/filtradoIntervalo.o : $(INC)/cronologia.h $(INC)/fechahistorica.h $(SRC)/filtradoIntervalo.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/filtradoIntervalo.o $(SRC)/filtradoIntervalo.cpp

$(OBJ)/estadisticaEventos.o : $(INC)/cronologia.h $(INC)/fechahistorica.h $(SRC)/estadisticaEventos.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/estadisticaEventos.o $(SRC)/estadisticaEventos.cpp

$(OBJ)/cronologia.o : $(INC)/cronologia.h $(INC)/fechahistorica.h $(SRC)/cronologia.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/cronologia.o $(SRC)/cronologia.cpp

$(OBJ)/fechahistorica.o : $(INC)/fechahistorica.h $(SRC)/fechahistorica.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/fechahistorica.o $(SRC)/fechahistorica.cpp

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~ $(BIN)/*

mrproper : clean
	-rm $(BIN)/* doc/html/*
