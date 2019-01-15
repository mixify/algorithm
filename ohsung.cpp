#include <stdio.h>

#include <cstring>

#include <utility>

using namespace std;



int word_num; bool flag;

char map[5][5], word[10][11];

pair<int, int> next[5][5][8];

int dx[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };

int dy[8] = { 0, 0, 1, -1, 1, -1, 1, -1 };



bool is_range(int x, int y) {

	if (x < 0 || y < 0 || x >= 5 || y >= 5)

		return false;

	return true;

}



void find_word(int x, int y, int cnt) {

	for (int i = 0; i < 8; i++) {

		if (flag)

			return;



		if (next[y][x][i].first == 10 && next[y][x][i].second == 10)

			continue;



		if (word[word_num][cnt + 1] == '\0' && !flag) {

			printf("%s YES\n", word[word_num]);

			flag = true;

			return;

		}



		if (next[y][x][i].first != -1 && next[y][x][i].second != -1) {

			if (word[word_num][cnt + 1] == map[next[y][x][i].second][next[y][x][i].first]) {

				find_word(next[y][x][i].first, next[y][x][i].second, cnt + 1);

				return;

			}

		}



		int next_x = x + dx[i];

		int next_y = y + dy[i];



		if (!is_range(next_x, next_y)) {

			next[y][x][i] = make_pair(10, 10);

			continue;

		}

		next[y][x][i] = make_pair(next_x, next_y);



		if (map[next_y][next_x] == word[word_num][cnt + 1])

			find_word(next_x, next_y, cnt + 1);

	}

	return;

}



int main() {

	int T;



	scanf("%d", &T);

	while (T--) {

		int n, x = -1, y = -1;

		memset(map, 0, sizeof(map));

		memset(next, -1, sizeof(next));



		for (int i = 0; i < 5; i++)

			for (int j = 0; j < 5; j++)

				scanf(" %1c", &map[i][j]);



		scanf("%d", &n);

		for (int i = 0; i < n; i++)

			scanf("%s", word[i]);



		for (word_num = 0; word_num < n; word_num++) {

			flag = false;

			for (int i = 0; i < 5; i++) {

				for (int j = 0; j < 5; j++) {

					if (flag)

						goto finish;

					if (map[i][j] == word[word_num][0]) {



						x = j, y = i;

						find_word(x, y, 0);

					}

					if (i == 4 && j == 4 && !flag) {

						flag = true;

						printf("%s NO\n", word[word_num]);

					}

				}

			}

		finish:;

		}

	}

}
