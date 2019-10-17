a.out :julgi_cells.cpp 
	g++ -g julgi_cells.cpp
run : julgi_cells.cpp a.out
	./a.out < input
gdb : julgi_cells.cpp a.out
	gdb a.out
algo : julgi_cells.cpp
	algo julgi_cells