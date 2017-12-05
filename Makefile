CXX = g++
CXXFLAGS = -std=c++11 -Wall -MMD -Werror=vla
EXEC = main
OBJECTS = main.o graphicsdisplay.o window.o block.o piece.o Opiece.o Lpiece.o Tpiece.o Zpiece.o Spiece.o Jpiece.o Ipiece.o interpreter.o game.o grid.o cell.o TextDisplay.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
