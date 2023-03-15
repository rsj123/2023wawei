#include <iostream>
#include <cmath>
#include <vector>

#define ll longlong
using namespace std;

typedef struct POS {
	double x;
	double y;
} POS;

typedef struct BOT {
	// status = 0 : free
	// status = 1 : going to take
	// status = 2 : going to put
	int status = 0;
	POS pos = {0, 0};
} BOT;

char map[100][100];
BOT bot[4];
// 9个等级的工作台
auto workbench = vector<vector<POS>>(9, vector<POS>(0));

bool readUntilOK() {
	char line[1024];
	while (fgets(line, sizeof line, stdin)) {
		if (line[0] == 'O' && line[1] == 'K') {
			return true;
		}
		//do something
	}
	return false;
}

double dest(POS a, POS b) {
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void readMap() {
	int id = 0;
	for (int i = 0; i < 100; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < 100; j++) {
			map[i][j] = line[j];
			switch (line[j]) {
				case 'A': {
					// 取中心坐标，与 doc 一致，以地图左下角为原点
					// eg: 第一行第一列为 (0.25, 49.75)
					bot[id].pos.x = 0.25 + 0.5 * (i - 1);
					bot[id].pos.y = 50 - (0.25 + 0.5 * (j - 1));
					id++;
					break;
				}
				case '.':
					break;
				default: {
					int level = line[j] - '0';
					// 算法同上
					POS p = {0.25 + 0.5 * (i - 1), 50 - (0.25 + 0.5 * (j - 1))};
					workbench[level].push_back(p);
					break;
				}
			}
		}
	}
}


int main() {
	readUntilOK();
	puts("OK");
	fflush(stdout);
	int frameID;
	while (scanf("%d", &frameID) != EOF) {
		readUntilOK();
		printf("%d\n", frameID);
		int lineSpeed = 3;
		double angleSpeed = 1.5;
		for (int robotId = 0; robotId < 4; robotId++) {
			printf("forward %d %d\n", robotId, lineSpeed);
			printf("rotate %d %f\n", robotId, angleSpeed);
		}
		printf("OK\n", frameID);
		fflush(stdout);
	}
	return 0;
}
