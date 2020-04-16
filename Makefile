all:
	g++ -std=c++11 -g mazelocation.hpp wall.cpp openspace.cpp mazelevel.cpp mazeperson.hpp intrepidstudent.cpp ta.cpp instructor.cpp maze.cpp Escape.cpp -o escape
clean:
	rm -rf *.o *.gch
mazelevel:
	g++ -std=c++11 -c mazelevel.cpp mazelocation.hpp mazeperson.hpp ta.cpp wall.cpp openspace.cpp intrepidstudent.cpp instructor.cpp
maze:
	g++ -std=c++11 -c maze.cpp mazelevel.cpp mazelocation.hpp mazeperson.hpp ta.cpp wall.cpp openspace.cpp intrepidstudent.cpp instructor.cpp
