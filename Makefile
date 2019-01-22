a.out :a.cpp 
	g++ -g a.cpp
run : a.out
	./a.out < input
gdb : a.out
	gdb a.out