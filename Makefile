a.out :wormhole.cpp 
	g++ -g wormhole.cpp
run : wormhole.cpp a.out
	./a.out < input
gdb : wormhole.cpp a.out
	gdb a.out
algo : wormhole.cpp
	algo wormhole