a.out :glasses.cpp 
	g++ -g glasses.cpp
run : a.out
	./a.out < input
gdb : glasses.cpp
	gdb a.out
algo : glasses.cpp
	algo glasses