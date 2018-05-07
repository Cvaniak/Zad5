#
#  To sa opcje dla kompilacji
#
CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11

TRGDIR=/tmp/robot_scena

__start__: ./robot_scena
	./robot_scena

./robot_scena: obj obj/main.o obj/ObiektGraficzny.o obj/lacze_do_gnuplota.o obj/Robot.o obj/Scena.o obj/Scieszka.o obj/Przeszkoda.o
	g++ -Wall -pedantic -std=c++11 -o ./robot_scena obj/main.o\
                        obj/lacze_do_gnuplota.o obj/ObiektGraficzny.o obj/Robot.o obj/Scena.o obj/Scieszka.o obj/Przeszkoda.o -lncurses

obj:
	mkdir -p obj

obj/lacze_do_gnuplota.o: inc/lacze_do_gnuplota.hh src/lacze_do_gnuplota.cpp
	g++ -c ${CXXFLAGS} -o obj/lacze_do_gnuplota.o src/lacze_do_gnuplota.cpp

obj/main.o: src/main.cpp inc/ObiektGraficzny.hh inc/Robot.hh inc/Przeszkoda.hh inc/Scena.hh
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/ObiektGraficzny.o: src/ObiektGraficzny.cpp inc/ObiektGraficzny.hh\
                       inc/Wektor2D.hh  inc/SWektor.hh
	g++ -c ${CXXFLAGS} -o obj/ObiektGraficzny.o src/ObiektGraficzny.cpp

obj/Robot.o: src/Robot.cpp inc/Robot.hh inc/Wektor2D.hh  inc/SWektor.hh inc/Scieszka.hh inc/lacze_do_gnuplota.hh
	g++ -c ${CXXFLAGS} -o obj/Robot.o src/Robot.cpp

obj/Przeszkoda.o: src/Przeszkoda.cpp inc/Przeszkoda.hh inc/Wektor2D.hh  inc/SWektor.hh inc/Scieszka.hh inc/lacze_do_gnuplota.hh
	g++ -c ${CXXFLAGS} -o obj/Przeszkoda.o src/Przeszkoda.cpp

obj/Scieszka.o: src/Scieszka.cpp inc/Scieszka.hh inc/Wektor2D.hh inc/ObiektGraficzny.hh
	g++ -c ${CXXFLAGS} -o obj/Scieszka.o src/Scieszka.cpp

obj/Scena.o: src/Scena.cpp inc/Scena.hh inc/lacze_do_gnuplota.hh inc/Wektor2D.hh inc/SWektor.hh inc/Przeszkoda.hh inc/Robot.hh inc/Scieszka.hh
	g++ -c ${CXXFLAGS} -o obj/Scena.o src/Scena.cpp

clean:
	rm -f -r obj/*.o ./robot_scena obj figury/*.dat
