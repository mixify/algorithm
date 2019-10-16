a.out :cut_mountain.cpp 
	g++ -g cut_mountain.cpp
run : cut_mountain.cpp a.out
	./a.out < input
gdb : cut_mountain.cpp a.out
	gdb a.out
algo : cut_mountain.cpp
	algo cut_mountain