#include <stdio.h>
#include <stdlib.h>

struct player {
	char name[20];
	int OBP;/*�o�ۗ�*/
	int AVE;/*1�ۑňȏ㗦*/
	int AVE2;/*2�ۑňȏ㗦*/
	int AVE3;/*3�ۑňȏ㗦*/
	int HOMERUN;/*�{�ۑŗ�*/
	int RISP;/*���_���ŗ�*/
};

int main()
{
	FILE *fp;
	char *filename = "data.txt";
	char *output = "output.txt";
	int i, j, k;
	double data[22];

	struct player pro[9];

	if ((fp = fopen(filename, "r")) == NULL) {
		printf("file open error\n");
		exit(EXIT_FAILURE);
	}
	for (j = 0; j < 9; j++) {
		fscanf(fp, "%s", pro[j].name);
		printf("%s", pro[j].name);
		for (i = 0; i < 22; i++) {
			fscanf(fp, "%lf", &data[i]);
			printf("%f", data[i]);
		}
		printf("\n");
	}
	fclose(fp);
	return 0;
}