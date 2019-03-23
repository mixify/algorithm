a.out :tree_invest.cpp 
	g++ -g tree_invest.cpp
run : a.out
	./a.out < input
gdb : tree_invest.cpp
	gdb a.out
algo : tree_invest.cpp
	algo tree_invest