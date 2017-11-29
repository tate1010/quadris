CXX = g++
CXXFLAGS = -std=c++11 -Wall -MMD -Werror=vla
EXEC = a4q5
OBJECTS = main.o cell.o grid.o TextDisplay.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
