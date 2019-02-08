a.out :stone_cut.cpp 
	g++ -g stone_cut.cpp
run : a.out
	./a.out < input
gdb : stone_cut.cpp
	gdb a.out
algo : stone_cut.cpp
	algo stone_cut