a.out :circular_queue.cpp 
	g++ -g circular_queue.cpp
run : a.out
	./a.out < input
gdb : circular_queue.cpp
	gdb a.out
algo : circular_queue.cpp
	algo circular_queue