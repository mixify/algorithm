a.out :scc.cpp 
	g++ -g scc.cpp
run : scc.cpp a.out
	./a.out < input
gdb : scc.cpp a.out
	gdb a.out
algo : scc.cpp
	algo scc