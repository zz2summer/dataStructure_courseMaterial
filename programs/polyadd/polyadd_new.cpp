#include <stdio.h> 
#include <stdlib.h> 
#include <iostream>
using namespace std;
typedef struct term//结点数据的定义，包含每项的系数coef和指数expn 
{  
    int coef;   //系数
 
    int   expn;   //指数
 
}term; 
  
typedef struct LNode//结点的定义
 
{  
    term data;  
    struct LNode *polyNode; 
}LNode,*Linklist; 
  
typedef Linklist polynomial; 
  
void Poly_Initialize(polynomial *p)//初始化多项式
 
{  
    *p = (Linklist)malloc(sizeof(LNode));  
    (*p)->polyNode = NULL;        //先建立头结点
  
    (*p)->data.coef = 0;                 //头结点数据域存储此链表的大小
  
    (*p)->data.expn = -1; 
} 
  
int Location_Find( polynomial *p, term item)//找到要插入的位置
 
{  
    int location =0; 
    Linklist t = *p; 
    t = t->polyNode;  
    while((t != NULL) && (t->data.expn >= item.expn)) 
    {  
        if( t->data.expn == item.expn ) 
            printf("这个阶次已经存在!\n"); 
        location++; 
        t = t->polyNode; 
    }  
    return location; 
} 
  
void List_Showdata(Linklist *L)//显示链表中的所有数据
 
{  
   
    printf("多项式之和降幂排列:\n"); 
    Linklist t; 
    t = *L;  
    t = t->polyNode; 
    if(t != NULL) 
        do 
        {  
            cout<<endl<<t->data.coef<<"   "<<t->data.expn; 
            t = t->polyNode; 
        }while(t != NULL); 
    printf("\n"); 
}  
int List_Insert(Linklist *L,int i,term item)//将数据item插入到链表的i位置的后面 
{  
    Linklist t; 
    t = *L; 
    int j = 0; 
    if(i<0) 
    {  
        printf("wrong number!\n"); 
        return 1; 
    }  
    while(t && j<i) 
    {  
        t = t->polyNode; 
        j++; 
    }  
    Linklist s = (Linklist)malloc(sizeof(LNode)); 
    s->data.coef = item.coef; 
    s->data.expn = item.expn; 
    s->polyNode = t->polyNode; 
    t->polyNode = s; 
    return 0; 
}  
int Poly_Creat( polynomial *p)//建立多项式 
{   
    int n;//n为多项式的项数 
    term temp[100]; 
    int i,j,k=0;
	int tmp=0;
	int sig;
	char s[100];  
	printf("输入这个多项式的项    2x^4-3x^2+3x^0#\n"); 
	cin.getline(s,100);
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]>='0'&&s[i]<='9')
			tmp+=(s[i]-'0');
		if(s[i]=='x')
		{
			temp[k].coef=tmp;
			tmp=0;
			if(sig==-1)
			{
					temp[k].coef=-temp[k].coef;
					sig=0;
			}
		}
		if((s[i]=='+'||s[i]=='-'||s[i]=='#')&&i)
		{
			temp[k].expn=tmp;
			if(s[i]=='-')sig=-1;		
			tmp=0;
			k++;
		}
        if((s[i]=='-')&&i==0)
			sig=-1;
	}
	n=k;
    for (i=0; i<n; i++)  
    {   
		cout<<temp[i].coef<<"   "<<temp[i].expn<<endl;
        j = Location_Find(p,temp[i]); 
        List_Insert(p,j,temp[i]); 
    }  
    return 0; 
} 
  
void List_Connect(Linklist *L,Linklist *K)//连接两个链表 
{  
    Linklist p = *L; 
    Linklist q = *K;  
    while(p->polyNode != NULL) 
        p = p->polyNode; 
    p->polyNode = q; 
} 
  
int Poly_Add(polynomial *p1, polynomial *p2)//多项式相加，结果放入另一个链表 
{  
    int i = 0; 
    term sum;  
    Linklist pa = (*p1)->polyNode; 
    Linklist pb = (*p2)->polyNode; 
    polynomial pc;  
    Poly_Initialize(&pc);  
    while((pa != NULL) && (pb != NULL)) 
    {  
        if(pa->data.expn > pb->data.expn) 
        {  
            List_Insert(&pc,i,pa->data); 
            i++;  
            pa = pa->polyNode; 
        }  
        else if(pa->data.expn < pb->data.expn) 
        {  
            List_Insert(&pc,i,pb->data); 
            i++;  
            pb = pb->polyNode; 
        } 
        else 
        {  
            sum.coef = pa->data.coef+pb->data.coef; 
            sum.expn = pa->data.expn;  
            if((sum.coef) != 0) 
            {  
                List_Insert(&pc,i,sum); 
                i++; 
            }  
            pa = pa->polyNode; 
            pb = pb->polyNode; 
  
        } 
    }  
    if(pa != NULL)  // A表余下节点
        List_Connect(&pc,&pa); 
    if(pb != NULL)  // B表余下节点
        List_Connect(&pc,&pb); 
    List_Showdata(&pc); 
    return 0; 
} 
 
 
  
int main() 
{  
    polynomial poly1,poly2; 
    Poly_Initialize(&poly1); 
    Poly_Initialize(&poly2); 
    Poly_Creat(&poly1); 
    Poly_Creat(&poly2);  
    Poly_Add(&poly1,&poly2); 
    return 0; 
}