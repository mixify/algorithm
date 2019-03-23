a.out :millionaire.cpp 
	g++ -g millionaire.cpp
run : a.out
	./a.out < input
gdb : millionaire.cpp
	gdb a.out
algo : millionaire.cpp
	algo millionaire