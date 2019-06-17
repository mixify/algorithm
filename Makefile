a.out :mst.cpp 
	g++ -g mst.cpp
run : mst.cpp a.out
	./a.out < input
gdb : mst.cpp a.out
	gdb a.out
algo : mst.cpp
	algo mst