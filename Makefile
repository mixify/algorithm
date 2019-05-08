a.out :castle.cpp 
	g++ -g castle.cpp
run : castle.cpp a.out
	./a.out < input
gdb : castle.cpp a.out
	gdb a.out
algo : castle.cpp
	algo castle