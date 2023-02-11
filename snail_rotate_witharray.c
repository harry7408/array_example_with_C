#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//90,180,270도일때 회전 가능 (1 반환)
int introtateArray(int** arr1,int degree, int count);

//degree에 입력받은 각도만큼 회전하는 함수 (90도를 1~3번 돌리는 방법이용)
void rotateArray(int*** a, int degree, int count);

//배열을 출력하는 함수
void printArray(int** ar, int num);

int main()
{
	int num,degree;
	printf("원하는 배열의 사이즈를 입력하세요 : ");
	scanf("%d", &num);
	int** arr = (int**)malloc(sizeof(int*) * num);  /* 2차원 배열을 만들기 위한 이중포인터 동적할당 */
	int i, j;
	int x = 0, y = -1;
	int dir = 1;
	int value = 1;
	int len = num;
	
	for (i = 0; i < len; i++)
	{
		arr[i] = (int*)malloc(sizeof(int) * num);
	}
	
	/* 달팽이 배열 만드는 과정 */
	while (1)
	{
		for (i = 0; i < len; i++)
		{
			y += dir;
			arr[x][y] = value++;
		}
		/* 꼭지점에 도달하면 횟수 1 차감 */
		len--;

		if (len < 0) break;

		for (i = 0; i < len; i++)
		{
			x += dir;
			arr[x][y] = value++;
		}
		/* 방향 전환 */
		dir = dir * (-1);
	}
	/* 달팽이 배열 출력 */
	printArray(arr, num);
	printf("\n");
	while(1)
	{
		printf("\n회전 각도를 입력하세요 : ");
		scanf("%d", &degree);
		
		if (degree == 270 && introtateArray(arr, degree, num) == 1)
		{
			printf("\n=====270도 회전=====\n");
			rotateArray(&arr, degree, num);
			continue;
		}
		else if (degree == 90 && introtateArray(arr, degree, num) == 1)
		{
			printf("\n=====90도 회전=====\n");
			rotateArray(&arr, degree, num);
			continue;
		}
		else if (degree == 180 && introtateArray(arr, degree, num) == 1)
		{
			printf("\n=====180도 회전=====\n");
			rotateArray(&arr, degree, num);
			continue;
		}
		/* 90, 180, 270을 제외한 숫자를 입력하면 프로그램 종료 */
		else 
			break;
			
	}
	

	for (i = 0; i < num; i++)
	{
		free(arr[i]);
	}
	free(arr);
	return 0;
}
/* 회전 가능한지 여부를 알려주는 함수 */
int introtateArray(int** arr1, int degree,int count)
{
	if (degree == 90 || degree == 180 || degree == 270) { return 1; }
	else
		return 0;
}
/* call-by-reference를 위해 삼중포인터를 인자로 */
void rotateArray(int*** a, int degree, int count)
{
	int i, j, k;
	int** temp = (int**)malloc(sizeof(int*) * count);
	for (i = 0; i < count; i++)
	{
		temp[i] = (int*)malloc(sizeof(int) * count);
	}
	/* 기본 90도 회전 */
	if (degree == 90)
	{
		for (i = 0; i < count; i++)
		{
			for (j = 0; j < count; j++)
			{
				temp[i][j] = (*a)[i][j];
			}
		}

		for (i = 0; i < count; i++)
		{
			for (j = 0; j < count; j++)
			{
				(*a)[j][count - i - 1] = temp[i][j];
			}
		}
		printArray(*a, count);
	}

	/* 90도 회전 2번 진행 */
	if (degree == 180)
	{

		for (k = 0; k < 2; k++)
		{
			for (i = 0; i < count; i++)
			{
				for (j = 0; j < count; j++)
				{
					temp[i][j] = (*a)[i][j];
				}
			}
			for (i = 0; i < count; i++)
			{
				for (j = 0; j < count; j++)
				{
					(*a)[j][count - 1 - i] = temp[i][j];
				}
			}
		}
		printArray(*a, count);
	}
	/* 90도 회전 3번 진행 */
	if (degree == 270)
	{
		for (k = 0; k < 3; k++)
		{
			for (i = 0; i < count; i++)
			{
				for (j = 0; j < count; j++)
				{
					temp[i][j] = (*a)[i][j];
				}
			}

			for (i = 0; i < count; i++)
			{
				for (j = 0; j < count; j++)
				{
					(*a)[j][count - 1 - i] = temp[i][j];
				}
			}
		}
		printArray(*a, count);
	}
}

void printArray(int** ar, int num)
{
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			printf("%5d\t", ar[i][j]);
		}
		printf("\n");
	}
}