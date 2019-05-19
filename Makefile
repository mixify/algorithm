a.out :trip_plan.cpp 
	g++ -g trip_plan.cpp
run : trip_plan.cpp a.out
	./a.out < input
gdb : trip_plan.cpp a.out
	gdb a.out
algo : trip_plan.cpp
	algo trip_plan