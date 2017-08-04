#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"
int main()
{
	int size = 0;
	int data = 0;
	printf("请输入希望的数据大小:\n");
	scanf("%d", &size);
	
	printf("请输入希望查找的数据:\n");
	while (scanf("%d", &data) != 0)
	{
		printf("请耐心等待……\n");

		Initialize(size);
		searchCompare(data);
		printf("请输入希望查找的数据:\n");
	}
	
	getchar();
	return 0;
}