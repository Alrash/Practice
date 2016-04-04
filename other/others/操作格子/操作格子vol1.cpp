/*
 *��n�����ӣ������ҷų�һ�ţ����Ϊ1-n
 *����m�β�������3�ֲ������ͣ�
 *1.�޸�һ�����ӵ�Ȩֵ
 *2.������һ�θ���Ȩֵ��
 *3.������һ�θ��ӵ����ֵ
 *����ÿ��2��3���������������Ľ��
 *
 *�����ʽ
 *��һ��2������n��m
 *������һ��n��������ʾn�����ӵĳ�ʼȨֵ
 *������m�У�ÿ��3������p,x,y��p��ʾ�������ͣ�p=1ʱ��ʾ�޸ĸ���x��ȨֵΪy��p=2ʱ��ʾ������[x,y]�ڸ���Ȩֵ�ͣ�p=3ʱ��ʾ������[x,y]�ڸ�������Ȩֵ
 */

#include <iostream>
#include <cmath>

using namespace std;

typedef struct Node
{
	int left, right;
	int max;
	int sum;
	int num;
	struct Node *lt, *rt;
}Tree, *BiTree;

int create(BiTree &T, int left, int right);
int pretraverse(BiTree T);
int inittree(BiTree &T, int num, int pos);
int Max(BiTree T, int left, int right, int &max);
int Sum(BiTree T, int left, int right, int &sum);
int replace(BiTree &T, int pos, int num, int n);

int main() 
{
	BiTree T = NULL;
	int n, num, m;
	int which, pos1, pos2;
	int max = 0, sum = 0;
	int count = 0, *arr;

	cin >> n >> m;

	arr = new int[m];
	create(T, 1, n);
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		inittree(T, num, i + 1);
	}

	for (int i = 0; i < m; i++)
	{
		cin >> which >> pos1 >> pos2;
		switch (which)
		{
		case 1:
			replace(T, pos1, pos2, n);
			//pretraverse(T);
			break;
		case 2:
			Sum(T, pos1, pos2, sum);
			arr[count++] = sum;
			sum = 0;
			break;
		case 3:
			Max(T, pos1, pos2, max);
			arr[count++] = max;
			max = 0;
			break;
		}
	}
	//replace(T, 1, 4, n);
	//Max(T, 1, 4, sum);
	//cout << sum;
	//pretraverse(T);

	for (int i = 0; i < count; i++)
		cout << arr[i] << endl;

	delete[] arr;
	return 0;
}

int init(BiTree &N, int left, int right)
{
	N = new Node;
	
	N->left = left;
	N->right = right;
	N->max = N->sum = 0;
	N->num = 0;
	N->lt = N->rt = NULL;
	
	return 0;
}

int create(BiTree &T, int left, int right)
{
	if (T == NULL)
	{
		init(T, left, right);
	}
	if (T->left != T->right)
	{
		int tmp = (left + right) / 2;
		create(T->lt, left, tmp);
		create(T->rt, tmp + 1, right);
	}
	return 0;
}

int inittree(BiTree &T, int num, int pos)
{
	if (pos == T->left && pos == T->right)
	{
		T->sum = num;
		T->max = num;
		T->num = pos;
	}
	else
	{
		if (T->max < num)
		{
			T->max = num;
			T->num = pos;
		}
		T->sum += num;

		int tmp = (T->left + T->right) / 2;
		if (pos > tmp)
			inittree(T->rt, num, pos);
		else
			inittree(T->lt, num, pos);
	}

	return 0;
}

int Max(BiTree T, int left, int right, int &max)
{
	if (left <= T->num && right >= T->num)
	{
		if (max < T->max)
			max = T->max;

		return 0;
	}
	if (T->left != left || T->right != right)
	{
		int tmp = (T->left + T->right) / 2;
		if (right <= tmp)
			Max(T->lt, left, right, max);
		else
		{
			if (left > tmp)
				Max(T->rt, left, right, max);
			else
			//if (T->left <= tmp && T->right > tmp)
			{
				Max(T->lt, left, tmp, max);
				Max(T->rt, tmp + 1, right, max);
			}
		}
	}
	else
	{
		if (max < T->max)
			max = T->max;
	}

	return 0;
}

int Sum(BiTree T, int left, int right, int &sum)
{
	if (T->left != left || T->right != right)
	{
		int tmp = (T->left + T->right) / 2;
		if (right <= tmp)
			Sum(T->lt, left, right, sum);
		else
		{
			if (left > tmp)
				Sum(T->rt, left, right, sum);
			else
				//if (T->left <= tmp && T->right > tmp)
			{
				Sum(T->lt, left, tmp, sum);
				Sum(T->rt, tmp + 1, right, sum);
			}
		}
	}
	else
		sum += T->sum;
	return 0;
}

int fund(BiTree T, int pos, BiTree arr[], int &count)
{
	arr[count] = T;
	//cout << arr[count]->sum << endl;
	count++;
	//if (T->left != pos || T->right != pos)
	if(T->left != T->right)
	{
		int mid = (T->left + T->right) / 2;
		if (mid >= pos)
			fund(T->lt, pos, arr, count);
		else
			fund(T->rt, pos, arr, count);
	}

	return 0;
}

int change(BiTree T, int &max, int &max_num)
{
	if (T)
	{
		if (max < T->max)
		{
			max = T->max;
			max_num = T->num;
		}
		if (T->lt && T->lt->max > max)
			change(T->lt, max, max_num);
		if (T->rt && T->rt->max > max)
			change(T->rt, max, max_num);
	}
	return 0;
}

int replace(BiTree &T, int pos, int num, int n)
{
	int len = (int)(n / log((double)n)) + 1;
	BiTree *arr = new BiTree[len];
	int count = 0, max = 0, max_num = 0;

	fund(T, pos, arr, count);

	arr[count - 1]->max = num;
	arr[count - 1]->sum = num;
	for (int i = count - 2; i >= 0; i--)
	{
		//arr[i]->sum = arr[i]->sum - arr[i]->max + num;
		arr[i]->sum = arr[i]->lt->sum + arr[i]->rt->sum;
		arr[i]->max = 0;
		change(arr[i], max, max_num);
		arr[i]->max = max;
		arr[i]->num = max_num;
		max = 0;
	}

	delete[] arr;
	return 0;
}

int pretraverse(BiTree T)
{
	if (T)
	{
		cout << T->left << " " << T->right << " "<< T->sum << " " << T->max << " " << T->num << endl;
		pretraverse(T->lt);
		pretraverse(T->rt);
	}

	return 0;
}