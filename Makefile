a.out :chicken.cpp 
	g++ -g chicken.cpp
run : chicken.cpp a.out
	./a.out < input
gdb : chicken.cpp a.out
	gdb a.out
algo : chicken.cpp
	algo chicken