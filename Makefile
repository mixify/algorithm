a.out :2048.cpp 
	g++ -g 2048.cpp
run : 2048.cpp a.out
	./a.out < input
gdb : 2048.cpp a.out
	gdb a.out
algo : 2048.cpp
	algo 2048