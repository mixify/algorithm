a.out :lunch_time.cpp 
	g++ -g lunch_time.cpp
run : lunch_time.cpp a.out
	./a.out < input
gdb : lunch_time.cpp a.out
	gdb a.out
algo : lunch_time.cpp
	algo lunch_time