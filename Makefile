a.out :marathon.cpp 
	g++ -g marathon.cpp
run : marathon.cpp a.out
	./a.out < input
gdb : marathon.cpp a.out
	gdb a.out
algo : marathon.cpp
	algo marathon