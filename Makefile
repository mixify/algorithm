a.out :robot_cleaner.cpp 
	g++ -g robot_cleaner.cpp
run : a.out
	./a.out < input
gdb : robot_cleaner.cpp
	gdb a.out
algo : robot_cleaner.cpp
	algo robot_cleaner