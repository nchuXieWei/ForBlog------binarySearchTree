#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"
int main()
{
	int size = 0;
	int data = 0;
	printf("������ϣ�������ݴ�С:\n");
	scanf("%d", &size);
	
	printf("������ϣ�����ҵ�����:\n");
	while (scanf("%d", &data) != 0)
	{
		printf("�����ĵȴ�����\n");

		Initialize(size);
		searchCompare(data);
		printf("������ϣ�����ҵ�����:\n");
	}
	
	getchar();
	return 0;
}