a.out :part_number.cpp 
	g++ -g part_number.cpp
run : a.out
	./a.out < input
gdb : part_number.cpp
	gdb a.out
algo : part_number.cpp
	algo part_number