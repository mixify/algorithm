a.out :gangho.cpp 
	g++ -g gangho.cpp
run : gangho.cpp a.out
	./a.out < input
gdb : gangho.cpp a.out
	gdb a.out
algo : gangho.cpp
	algo gangho