a.out :pin_ball.cpp 
	g++ -g pin_ball.cpp
run : pin_ball.cpp a.out
	./a.out < input
gdb : pin_ball.cpp a.out
	gdb a.out
algo : pin_ball.cpp
	algo pin_ball