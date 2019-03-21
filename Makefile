a.out :research_center.cpp 
	g++ -g research_center.cpp
run : a.out
	./a.out < input
gdb : research_center.cpp
	gdb a.out
algo : research_center.cpp
	algo research_center