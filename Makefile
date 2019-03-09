a.out :num_bead.cpp 
	g++ -g num_bead.cpp
run : a.out
	./a.out < input
gdb : num_bead.cpp
	gdb a.out
algo : num_bead.cpp
	algo num_bead