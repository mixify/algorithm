a.out :wireless_charge.cpp 
	g++ -g wireless_charge.cpp
run : wireless_charge.cpp a.out
	./a.out < input
gdb : wireless_charge.cpp a.out
	gdb a.out
algo : wireless_charge.cpp
	algo wireless_charge