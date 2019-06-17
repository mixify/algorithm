a.out :network_connect.cpp 
	g++ -g network_connect.cpp
run : network_connect.cpp a.out
	./a.out < input
gdb : network_connect.cpp a.out
	gdb a.out
algo : network_connect.cpp
	algo network_connect