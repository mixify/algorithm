a.out :safe_place.cpp 
	g++ -g safe_place.cpp
run : safe_place.cpp a.out
	./a.out < input
gdb : safe_place.cpp a.out
	gdb a.out
algo : safe_place.cpp
	algo safe_place