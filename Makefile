a.out :lcs4.cpp 
	g++ -g lcs4.cpp
run : a.out
	./a.out < input
gdb : lcs4.cpp
	gdb a.out
algo : lcs4.cpp
	algo lcs4