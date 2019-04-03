a.out :dragon_curve.cpp 
	g++ -g dragon_curve.cpp
run : dragon_curve.cpp a.out
	./a.out < input
gdb : dragon_curve.cpp a.out
	gdb a.out
algo : dragon_curve.cpp
	algo dragon_curve