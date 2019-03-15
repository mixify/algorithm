a.out :chained_matrix_multiplication.cpp 
	g++ -g chained_matrix_multiplication.cpp
run : a.out
	./a.out < input
gdb : chained_matrix_multiplication.cpp
	gdb a.out
algo : chained_matrix_multiplication.cpp
	algo chained_matrix_multiplication