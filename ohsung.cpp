#include <stdio.h>
#include <string.h>

char map[5][5];
char word[10][11];
int cache[5][5][11];

int word_num, k;

int solve(int x, int y, int cnt) {
	if (x >= 5 || y >= 5 || x < 0 || y < 0 || cnt >= 11) return 0;
	if (map[y][x] != word[k][cnt]) return 0;
	if (map[y][x] == word[k][cnt] && word[k][cnt + 1] == '\0') return 1;

	int &ret = cache[y][x][cnt];
	if (ret != -1) return ret;

	return ret = (solve(x + 1, y, cnt + 1) ||
				  solve(x - 1, y, cnt + 1) ||
				  solve(x, y + 1, cnt + 1) ||
				  solve(x, y - 1, cnt + 1) ||
				  solve(x + 1, y + 1, cnt + 1) ||
				  solve(x + 1, y - 1, cnt + 1) ||
				  solve(x - 1, y + 1, cnt + 1) ||
				  solve(x - 1, y - 1, cnt + 1));
}

int main() {
	int T;

	scanf("%d", &T);
	while (T--) {
		int res = -1;
		memset(map, 0, sizeof(map));
		memset(word, 0, sizeof(word));
		memset(cache, -1, sizeof(cache));

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++)
				scanf(" %1c", &map[i][j]);
		}
		scanf("%d", &word_num);
		for (int i = 0; i < word_num; i++)
			scanf("%s", word[i]);

		for (k = 0; k < word_num; k++) {
			res = -1;
			memset(cache, -1, sizeof(cache));
			for (int i = 0; i < 5; i++) {
				if (res == 1)
					break;
				for (int j = 0; j < 5; j++) {
					if (res == 1)
						break;
					if (map[i][j] == word[k][0]) {
						res = solve(j, i, 0);
						memset(cache, -1, sizeof(cache));
					}
				}
			}
			if (res == 1)
				printf("%s YES\n", word[k]);
			else if (res == 0 || res == -1)
				printf("%s NO\n", word[k]);
		}
	}
}
