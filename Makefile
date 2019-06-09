a.out :maximum_flow.cpp 
	g++ -g maximum_flow.cpp
run : maximum_flow.cpp a.out
	./a.out < input
gdb : maximum_flow.cpp a.out
	gdb a.out
algo : maximum_flow.cpp
	algo maximum_flow