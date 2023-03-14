#include <iostream>
#include <math.h>

#define ll longlong
using namespace std;

typedef struct pos {
	double x;
	double y;
} pos;

char map[100][100];
pos bot[4], workbench[50];
int workbenchNum = 0;

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

bool readMap() {
	int id = 0;
	for (int i = 0; i < 100; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < 100; j++) {
			map[i][j] = line[j];
			switch (line[j]) {
				case 'A':{
					bot[id].x = 0.25*(i+1);
					bot[id].y = 0.25*(j+1);
				}
			}
			if (line[j] == 'A') {

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
