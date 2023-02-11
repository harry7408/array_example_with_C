#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//90,180,270���϶� ȸ�� ���� (1 ��ȯ)
int introtateArray(int** arr1,int degree, int count);

//degree�� �Է¹��� ������ŭ ȸ���ϴ� �Լ� (90���� 1~3�� ������ ����̿�)
void rotateArray(int*** a, int degree, int count);

//�迭�� ����ϴ� �Լ�
void printArray(int** ar, int num);

int main()
{
	int num,degree;
	printf("���ϴ� �迭�� ����� �Է��ϼ��� : ");
	scanf("%d", &num);
	int** arr = (int**)malloc(sizeof(int*) * num);  /* 2���� �迭�� ����� ���� ���������� �����Ҵ� */
	int i, j;
	int x = 0, y = -1;
	int dir = 1;
	int value = 1;
	int len = num;
	
	for (i = 0; i < len; i++)
	{
		arr[i] = (int*)malloc(sizeof(int) * num);
	}
	
	/* ������ �迭 ����� ���� */
	while (1)
	{
		for (i = 0; i < len; i++)
		{
			y += dir;
			arr[x][y] = value++;
		}
		/* �������� �����ϸ� Ƚ�� 1 ���� */
		len--;

		if (len < 0) break;

		for (i = 0; i < len; i++)
		{
			x += dir;
			arr[x][y] = value++;
		}
		/* ���� ��ȯ */
		dir = dir * (-1);
	}
	/* ������ �迭 ��� */
	printArray(arr, num);
	printf("\n");
	while(1)
	{
		printf("\nȸ�� ������ �Է��ϼ��� : ");
		scanf("%d", &degree);
		
		if (degree == 270 && introtateArray(arr, degree, num) == 1)
		{
			printf("\n=====270�� ȸ��=====\n");
			rotateArray(&arr, degree, num);
			continue;
		}
		else if (degree == 90 && introtateArray(arr, degree, num) == 1)
		{
			printf("\n=====90�� ȸ��=====\n");
			rotateArray(&arr, degree, num);
			continue;
		}
		else if (degree == 180 && introtateArray(arr, degree, num) == 1)
		{
			printf("\n=====180�� ȸ��=====\n");
			rotateArray(&arr, degree, num);
			continue;
		}
		/* 90, 180, 270�� ������ ���ڸ� �Է��ϸ� ���α׷� ���� */
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
/* ȸ�� �������� ���θ� �˷��ִ� �Լ� */
int introtateArray(int** arr1, int degree,int count)
{
	if (degree == 90 || degree == 180 || degree == 270) { return 1; }
	else
		return 0;
}
/* call-by-reference�� ���� ���������͸� ���ڷ� */
void rotateArray(int*** a, int degree, int count)
{
	int i, j, k;
	int** temp = (int**)malloc(sizeof(int*) * count);
	for (i = 0; i < count; i++)
	{
		temp[i] = (int*)malloc(sizeof(int) * count);
	}
	/* �⺻ 90�� ȸ�� */
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

	/* 90�� ȸ�� 2�� ���� */
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
	/* 90�� ȸ�� 3�� ���� */
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