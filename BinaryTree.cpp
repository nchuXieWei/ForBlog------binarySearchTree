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


//�������в��Ҹ���data���������򷵻�true
bool searchByArray(int data)
{
	for (int i = 0;i < Size;++i)
		if (Array[i] == data)
			return true;
		else
			_sleep(1);  //����ǰԪ�ز��Ǹ���data���������ͣ1���룬Ŀ����Ϊ��͹�Գ�������ҺͶ��������ҵĲ��
	return false;
}

//�ڶ������в��Ҹ���data���������򷵻�true
bool searchByTree(BinaryTree t,int data)
{
	
	if (t == NULL)
		return false;
	if (t->data == data&&t->frequency > 0)
		return true;

	_sleep(1);//����ǰԪ�ز��Ǹ���data���������ͣ1���룬Ŀ����Ϊ��͹�Գ�������ҺͶ��������ҵĲ��
	if (data < t->data)
		return searchByTree(t->left, data);
	if (data > t->data)
		return searchByTree(t->right, data);

	return false;
}

//����size����size��С�����鼰���������
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

//�����������������ݣ��������Ѵ������������frequency
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



//������Ͷ���������в��Ҹ��������Ƿ���ڣ�������ķ�ʱ��
void searchCompare(int data)
{
	clock_t start = 0;
	clock_t end = 0;
	bool finded = false;

	start = clock();
	finded=searchByArray(data);
	end = clock();
	if (finded)
		printf("�ҵ��˸�����\n");
	else
		printf("δ�ҵ�������\n");
	printf("ͨ������Ѱ�һ���ʱ�䣺%ld-%ld=%ld\n", end,start,end - start);

	start = clock();
	searchByTree(Tree,data);
	end = clock();
	printf("ͨ��������Ѱ�һ���ʱ��%ld-%ld=%ld\n",end,start, end - start);
}