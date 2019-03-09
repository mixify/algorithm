a.out :router_install.cpp 
	g++ -g router_install.cpp
run : a.out
	./a.out < input
gdb : router_install.cpp
	gdb a.out
algo : router_install.cpp
	algo router_install