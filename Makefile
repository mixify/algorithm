a.out :liner.cpp 
	g++ -g liner.cpp
run : liner.cpp a.out
	./a.out < input
gdb : liner.cpp a.out
	gdb a.out
algo : liner.cpp
	algo liner