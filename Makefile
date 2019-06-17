a.out :time_machine.cpp 
	g++ -g time_machine.cpp
run : time_machine.cpp a.out
	./a.out < input
gdb : time_machine.cpp a.out
	gdb a.out
algo : time_machine.cpp
	algo time_machine