a.out :line_group.cpp 
	g++ -g line_group.cpp
run : line_group.cpp a.out
	./a.out < input
gdb : line_group.cpp a.out
	gdb a.out
algo : line_group.cpp
	algo line_group