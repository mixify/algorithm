a.out :downhill.cpp 
	g++ -g downhill.cpp
run : a.out
	./a.out < input
gdb : a.out
	gdb a.out