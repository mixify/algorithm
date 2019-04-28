a.out :roberthood.cpp 
	g++ -g roberthood.cpp
run : roberthood.cpp a.out
	./a.out < input
gdb : roberthood.cpp a.out
	gdb a.out
algo : roberthood.cpp
	algo roberthood