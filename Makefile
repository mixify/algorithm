a.out :baby_shark.cpp 
	g++ -g baby_shark.cpp
run : baby_shark.cpp a.out
	./a.out < input
gdb : baby_shark.cpp a.out
	gdb a.out
algo : baby_shark.cpp
	algo baby_shark