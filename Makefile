a.out :snake.cpp 
	g++ -g snake.cpp
run : snake.cpp a.out
	./a.out < input
gdb : snake.cpp a.out
	gdb a.out
algo : snake.cpp
	algo snake