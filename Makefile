a.out :electric_cord.cpp 
	g++ -g electric_cord.cpp
run : a.out
	./a.out < input
gdb : electric_cord.cpp
	gdb a.out
algo : electric_cord.cpp
	algo electric_cord