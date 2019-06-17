a.out :bfs_dfs.cpp 
	g++ -g bfs_dfs.cpp
run : bfs_dfs.cpp a.out
	./a.out < input
gdb : bfs_dfs.cpp a.out
	gdb a.out
algo : bfs_dfs.cpp
	algo bfs_dfs