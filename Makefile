a.out :packing.cpp 
	g++ -g packing.cpp
run : a.out
	./a.out < input
gdb : packing.cpp
	gdb a.out
algo : packing.cpp
	algo packing