a.out :apnana.cpp 
	g++ -g apnana.cpp
run : apnana.cpp a.out
	./a.out < input
gdb : apnana.cpp a.out
	gdb a.out
algo : apnana.cpp
	algo apnana