a.out :candy.cpp 
	g++ -g candy.cpp
run : a.out
	./a.out < input
gdb : candy.cpp
	gdb a.out
algo : candy.cpp
	algo candy