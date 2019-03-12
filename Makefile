a.out :ocr.cpp 
	g++ -g ocr.cpp
run : a.out
	./a.out < input
gdb : ocr.cpp
	gdb a.out
algo : ocr.cpp
	algo ocr