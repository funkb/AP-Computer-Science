CC=g++
FLAGS=std=c++11

main: main.cpp date.cpp flight.cpp crewmember.cpp plane.cpp planemanager.cpp flightmanager.cpp crewmanager.cpp
	$(CC) -$(FLAGS) -o main main.cpp crewmanager.cpp flight.cpp date.cpp crewmember.cpp plane.cpp planemanager.cpp flightmanager.cpp

.PHONY: clean

clean:
	rm -f main
