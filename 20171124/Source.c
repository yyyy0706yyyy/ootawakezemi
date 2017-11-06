#define _CRT_SECURE_NO_WARNINGS

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
	int BUNT;/*�]��*/
	int SAC_FLY;/*�]���t���C*/
	int STEAL;/*����*/
};

int main()
{
	FILE *fp;
	char *filename = "data.txt";
	char *output = "output.txt";
	int i, j;
	double data[17];

	struct player pro[9];

	if ((fp = fopen(filename, "r")) == NULL) {
		printf("file open error\n");
		exit(EXIT_FAILURE);
	}
	for (j = 0; j < 9; j++) {
		fscanf(fp, "%s", pro[j].name);
		printf("%s ", pro[j].name);
		for (i = 0; i < 17; i++) {
			fscanf(fp, "%lf", &data[i]);
			printf("%f ", data[i]);
		}
		printf("\n");
		pro[j].AVE = 1000 * data[1];
		pro[j].AVE2 = 1000 * (data[4] + data[5] + data[6]) / data[2];
		pro[j].AVE3 = 1000 * (data[5] + data[6]) / data[2];
		pro[j].HOMERUN = 1000 * data[6] / data[2];
		pro[j].OBP = 1000 * data[14];
		pro[j].RISP = 1000 * data[17];
		pro[j].STEAL = 1000 * data[11]/((data[3] - data[4] - data[5] - data[6]) + data[7] + data[8]);
	}



	fclose(fp);
	return 0;
}