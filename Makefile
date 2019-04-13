a.out :direct.cpp 
	g++ -g direct.cpp
run : direct.cpp a.out
	./a.out < input
gdb : direct.cpp a.out
	gdb a.out
algo : direct.cpp
	algo direct