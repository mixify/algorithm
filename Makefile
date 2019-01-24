a.out :padoban.cpp 
	g++ -g padoban.cpp
run : a.out
	./a.out < input
gdb : padoban.cpp
	gdb a.out
algo : padoban.cpp
	algo padoban