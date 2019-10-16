a.out :dessert_cafe.cpp 
	g++ -g dessert_cafe.cpp
run : dessert_cafe.cpp a.out
	./a.out < input
gdb : dessert_cafe.cpp a.out
	gdb a.out
algo : dessert_cafe.cpp
	algo dessert_cafe