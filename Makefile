a.out :castle_wall.cpp 
	g++ -g castle_wall.cpp
run : castle_wall.cpp a.out
	./a.out < input
gdb : castle_wall.cpp a.out
	gdb a.out
algo : castle_wall.cpp
	algo castle_wall