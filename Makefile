a.out :network_restore.cpp 
	g++ -g network_restore.cpp
run : network_restore.cpp a.out
	./a.out < input
gdb : network_restore.cpp a.out
	gdb a.out
algo : network_restore.cpp
	algo network_restore