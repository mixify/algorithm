a.out :quantum_collision.cpp 
	g++ -g quantum_collision.cpp
run : quantum_collision.cpp a.out
	./a.out < input
gdb : quantum_collision.cpp a.out
	gdb a.out
algo : quantum_collision.cpp
	algo quantum_collision