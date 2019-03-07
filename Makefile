a.out :bead_escape2.cpp 
	g++ -g bead_escape2.cpp
run : a.out
	./a.out < input
gdb : bead_escape2.cpp
	gdb a.out
algo : bead_escape2.cpp
	algo bead_escape2