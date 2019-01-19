#include <stdio.h>

#include <iostream>

#include <cstring>

#include <vector>



using namespace std;



char input[5][5] = { 0 , };

char vaca[11];

int cache[7][7][11];

int dx[8] = { 0,1,1,1,0,-1,-1,-1 };

int dy[8] = { -1,-1,0,1,1,1,0,-1 };

int find(string abc, int y, int x, int len, int find_len)

{

	//기저사례

	if (y < 0 || x < 0 || y >= 5 || x >= 5)

		return 0;



	if (len == find_len)

	{



		return 1;

	}



	int& result = cache[y][x][find_len];



	//이미 구했을때.



	if (result != -1)

		return result;



	//

	if (input[y][x] == abc.at(find_len)) {

		//printf("%c \n", abc.at(find_len));

		find_len++;

		//printf("%d\n", find_len);

		return result = (find(abc, y + dy[0], x + dx[0], len, find_len) ||

			find(abc, y + dy[1], x + dx[1], len, find_len) ||

			find(abc, y + dy[2], x + dx[2], len, find_len) ||

			find(abc, y + dy[3], x + dx[3], len, find_len) ||

			find(abc, y + dy[4], x + dx[4], len, find_len) ||

			find(abc, y + dy[5], x + dx[5], len, find_len) ||

			find(abc, y + dy[6], x + dx[6], len, find_len) ||

			find(abc, y + dy[7], x + dx[7], len, find_len));

	}

	else {

		cache[y][x][find_len] = 0;

		find_len = 0;

		if (x + 1 > 4) {

			x = 0;

			return find(abc, y + 1, x, len, find_len);

		}

		else {



			return find(abc, y, x + 1, len, find_len);



		}

	}

}





int main(void)

{

	int test;

	int i, j, k;

	int vaca_cnt;

	int check_vaca = 0;



	scanf("%d", &test);

	for (i = 0; i < test; i++) {

		memset(input, 0, sizeof(input));

	//	memset(vaca, 0, sizeof(vaca));

		for (j = 0; j < 5; j++)

			for (k = 0; k < 5; k++) {

				scanf(" %1c", &input[j][k]);

			}

		scanf("%d", &vaca_cnt);



		for (j = 0; j < vaca_cnt; j++) {

			scanf("%s", &vaca);

			memset(cache, -1, sizeof(cache));

			check_vaca = find(vaca, 0, 0, strlen(vaca), 0);

			if (check_vaca == 1)

				printf("%s YES\n", vaca);

			else

				printf("%s NO\n", vaca);

		}

	}

	return 0;

}


