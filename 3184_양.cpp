#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
const int MAX = 251;

char map[MAX][MAX];
bool isChecked[MAX][MAX];
queue<pair<int, int> > q;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int cntOfSheep = 0;
int cntOfWolf = 0;
int r, c;

void bfs(int x, int y) {

	pair<int, int> p;
	p.first = x;
	p.second = y;
	isChecked[x][y] = true;
	q.push(p);

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
			
			if (map[nx][ny] == '.' && !isChecked[nx][ny]) {
				isChecked[nx][ny] = true;
				p.first = nx;
				p.second = ny;
				q.push(p);
			}
			else if (map[nx][ny] == 'o' && !isChecked[nx][ny]) {
				isChecked[nx][ny] = true;
				cntOfSheep += 1;
				p.first = nx;
				p.second = ny;
				q.push(p);
			}
			else if (map[nx][ny] == 'v' && !isChecked[nx][ny]) {
				isChecked[nx][ny] = true;
				cntOfWolf += 1;
				p.first = nx;
				p.second = ny;
				q.push(p);
			}
		}
	}

}

int main() {

	scanf("%d %d", &r, &c);

	memset(isChecked, false, sizeof(isChecked));

	for (int i = 0; i < r; i++) {
		scanf("%s", map[i]);
	}

	int ansOfSheep = 0;
	int ansOfWolf = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (!isChecked[i][j]) {
				if (map[i][j] == 'o' || map[i][j] == 'v') {
					if (map[i][j] == 'o') cntOfSheep += 1;
					else cntOfWolf += 1;
					bfs(i, j);
					if (cntOfSheep > cntOfWolf) {
						ansOfSheep += cntOfSheep;
					}
					else {
						ansOfWolf += cntOfWolf;
					}

					cntOfSheep = 0, cntOfWolf = 0;
				}
				
			}
		}
	}

	printf("%d %d\n", ansOfSheep, ansOfWolf);


	return 0;
}