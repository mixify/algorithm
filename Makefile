a.out :protect_seal.cpp 
	g++ -g protect_seal.cpp
run : protect_seal.cpp a.out
	./a.out < input
gdb : protect_seal.cpp a.out
	gdb a.out
algo : protect_seal.cpp
	algo protect_seal