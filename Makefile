a.out :danji.cpp 
	g++ -g danji.cpp
run : danji.cpp a.out
	./a.out < input
gdb : danji.cpp a.out
	gdb a.out
algo : danji.cpp
	algo danji