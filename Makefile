CXX = g++
CXXFLAGS = -std=c++11 -Wall -MMD -Werror=vla
EXEC = main
OBJECTS = main.o interpreter.o game.o grid.o cell.o TextDisplay.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
