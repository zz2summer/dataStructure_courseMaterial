// paishui.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <ctime>
#include <iostream>
using namespace std;

void bubble_up(int list[],int count)
{
for(int i=0;i<count;i++ )
	for(int j=count-1;j>i;j--)
		if(list[j-1]>list[j])

		{
			int tmp=list[j-1];
			list[j-1]=list[j];
			list[j]=tmp;
		}
}
int _tmain(int argc, _TCHAR* argv[])
{
    int i;
    int array[100]={0};
    srand((unsigned)time(NULL));
    cout<<"�ܹ�������100������:"<<endl;
    for(i=0;i<100;i++)
    {
		int numtemp=rand()%1000;
		array[i]=numtemp;
	    cout<<array[i]<<"\t";
	}
    cout<<endl;
    bubble_up(array,100);
    cout<<"��ԭ100�����������Ľ����:"<<endl;
    for(i=0;i<100;i++)
         cout<<array[i]<<"\t";
    cout<<endl;
    return 0;
}


