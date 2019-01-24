a.out :sequence_sum.cpp 
	g++ -g sequence_sum.cpp
run : a.out
	./a.out < input
gdb : a.out
	gdb a.out
algo : sequence_sum.cpp
	algo sequence_sum