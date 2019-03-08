a.out :tree_hw.cpp 
	g++ -g tree_hw.cpp
run : a.out
	./a.out < input
gdb : tree_hw.cpp
	gdb a.out
algo : tree_hw.cpp
	algo tree_hw