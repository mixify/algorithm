a.out :watch_dog.cpp 
	g++ -g watch_dog.cpp
run : watch_dog.cpp a.out
	./a.out < input
gdb : watch_dog.cpp a.out
	gdb a.out
algo : watch_dog.cpp
	algo watch_dog