#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BinaryTree.h"

int Size;
int *Array = NULL;
BinaryTree Tree = NULL;
bool searchByTree(BinaryTree t, int data);
bool searchByArray(int data);
BinaryTree Insert(BinaryTree t, int data);


//在数组中查找给定data，若存在则返回true
bool searchByArray(int data)
{
	for (int i = 0;i < Size;++i)
		if (Array[i] == data)
			return true;
		else
			_sleep(1);  //若当前元素不是给定data，则程序暂停1毫秒，目的是为了凸显出数组查找和二叉树查找的差距
	return false;
}

//在二叉树中查找给定data，若存在则返回true
bool searchByTree(BinaryTree t,int data)
{
	
	if (t == NULL)
		return false;
	if (t->data == data&&t->frequency > 0)
		return true;

	_sleep(1);//若当前元素不是给定data，则程序暂停1毫秒，目的是为了凸显出数组查找和二叉树查找的差距
	if (data < t->data)
		return searchByTree(t->left, data);
	if (data > t->data)
		return searchByTree(t->right, data);

	return false;
}

//根据size创建size大小的数组及二叉查找树
void Initialize(int size)
{
	static bool Initialized = false;
	if (Initialized)
		return;
	Size = size;
	Initialized = true;
	srand((unsigned int)time(NULL));
	Array = (int *)malloc(size * sizeof(int));

	for (int i = 0;i < size;++i)
	{
		Array[i] = rand()*rand();
	}

	Tree = Insert(Tree, Array[0]);
	for (int i = 1;i < size;++i)
	{
		Insert(Tree,Array[i]);
	}
}

//向二叉查找树插入数据，若数据已存在则递增结点的frequency
BinaryTree Insert(BinaryTree t,int data)
{
	if (t == NULL)
	{
		BinaryTree temp = (BinaryTree)malloc(sizeof(BinaryTreeNode));
		temp->data = data;
		temp->frequency = 1;
		temp->left = temp->right = NULL;
		return temp;
	}
	if (data < t->data)
		t->left = Insert(t->left, data);
	else if (data > t->data)
		t->right = Insert(t->right, data);
	else
		t->frequency++;
	return t;
}



//在数组和二叉查找树中查找给定数据是否存在，并输出耗费时间
void searchCompare(int data)
{
	clock_t start = 0;
	clock_t end = 0;
	bool finded = false;

	start = clock();
	finded=searchByArray(data);
	end = clock();
	if (finded)
		printf("找到了该数据\n");
	else
		printf("未找到该数据\n");
	printf("通过数组寻找花费时间：%ld-%ld=%ld\n", end,start,end - start);

	start = clock();
	searchByTree(Tree,data);
	end = clock();
	printf("通过二叉树寻找花费时间%ld-%ld=%ld\n",end,start, end - start);
}