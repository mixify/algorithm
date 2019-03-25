a.out :palindrome.cpp 
	g++ -g palindrome.cpp
run : a.out
	./a.out < input
gdb : palindrome.cpp
	gdb a.out
algo : palindrome.cpp
	algo palindrome