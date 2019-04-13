a.out :wheel.cpp 
	g++ -g wheel.cpp
run : wheel.cpp a.out
	./a.out < input
gdb : wheel.cpp a.out
	gdb a.out
algo : wheel.cpp
	algo wheel