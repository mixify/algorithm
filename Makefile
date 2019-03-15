a.out :delivery.cpp 
	g++ -g delivery.cpp
run : a.out
	./a.out < input
gdb : delivery.cpp
	gdb a.out
algo : delivery.cpp
	algo delivery