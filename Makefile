a.out :panel.cpp 
	g++ -g panel.cpp
run : a.out
	./a.out < input
gdb : panel.cpp
	gdb a.out
algo : panel.cpp
	algo panel