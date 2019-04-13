a.out :start_link.cpp 
	g++ -g start_link.cpp
run : start_link.cpp a.out
	./a.out < input
gdb : start_link.cpp a.out
	gdb a.out
algo : start_link.cpp
	algo start_link