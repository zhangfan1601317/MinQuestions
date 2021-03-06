// MinQuestions.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <istream>
#include <algorithm>
#include <ctime>
#include <vector>
using namespace std;
void __swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void __quickSort(int inputdata[], int l, int r)
{
	if (l >= r)
		return;
	__swap(inputdata[l], inputdata[rand() % (r - l + 1) + l]);
	int v = inputdata[l];


	int lt = l;
	int gt = r + 1;
	int i = l + 1;
	while (i < gt)
	{
		if (inputdata[i] < v)
		{
			__swap(inputdata[i], inputdata[lt + 1]);
			lt++;
			i++;
		}
		else if (inputdata[i]>v)
		{
			__swap(inputdata[i], inputdata[gt - 1]);
			gt--;
		}
		else
		{
			i++;
		}
	}
	__swap(inputdata[l], inputdata[lt]);
	__quickSort(inputdata, l, lt - 1);
	__quickSort(inputdata, gt, r);
}
void quickSort(int inputdata[],int n) {
	__quickSort(inputdata,0,n-1);
}
int main()
{
	int n;
	int minQuestions = 0;
	cin >> n;
	vector<int>inputdata;
	int data;
	int i;
	for (int i = 0; i < n; i++)
	{
		cin >> data;
		inputdata.push_back(data);
	}
	
	sort(inputdata.begin(), inputdata.end());

	int num;
	for (i = 0; i < n; i++)
	{
		num = 1;
		if (i < n - 2)
		{
			if (inputdata[i + 1] - inputdata[i] <= 10)
			{
				num++;
				if (inputdata[i + 2] - inputdata[i + 1] <= 10)
				{
					num++;
					i += 2;
				}
				else
				{
					num++;
					minQuestions++;
					i++;
				}
			}
			else if (inputdata[i + 1] - inputdata[i] <= 20)
			{
				num += 2;
				minQuestions++;
				i++;
			}
			else
			{
				num += 2;
				minQuestions += 2;
			}
		}
		else if (i == n - 2)
		{
			if (inputdata[i + 1] - inputdata[i] <= 20)
			{
				num+=2;
				minQuestions++;
				i++;
			}
			else
			{
				num += 2;
				minQuestions += 4;
				i++;
			}
		}
	}
	if (num != 3)
		minQuestions += (3 - num);
	cout << minQuestions << endl;
	return 0;
}

