a.out :area_divide.cpp 
	g++ -g area_divide.cpp
run : area_divide.cpp a.out
	./a.out < input
gdb : area_divide.cpp a.out
	gdb a.out
algo : area_divide.cpp
	algo area_divide