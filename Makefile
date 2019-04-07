a.out :panda.cpp 
	g++ -g panda.cpp
run : panda.cpp a.out
	./a.out < input
gdb : panda.cpp a.out
	gdb a.out
algo : panda.cpp
	algo panda