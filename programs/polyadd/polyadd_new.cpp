#include <stdio.h> 
#include <stdlib.h> 
#include <iostream>
using namespace std;
typedef struct term//������ݵĶ��壬����ÿ���ϵ��coef��ָ��expn 
{  
    int coef;   //ϵ��
 
    int   expn;   //ָ��
 
}term; 
  
typedef struct LNode//���Ķ���
 
{  
    term data;  
    struct LNode *polyNode; 
}LNode,*Linklist; 
  
typedef Linklist polynomial; 
  
void Poly_Initialize(polynomial *p)//��ʼ������ʽ
 
{  
    *p = (Linklist)malloc(sizeof(LNode));  
    (*p)->polyNode = NULL;        //�Ƚ���ͷ���
  
    (*p)->data.coef = 0;                 //ͷ���������洢������Ĵ�С
  
    (*p)->data.expn = -1; 
} 
  
int Location_Find( polynomial *p, term item)//�ҵ�Ҫ�����λ��
 
{  
    int location =0; 
    Linklist t = *p; 
    t = t->polyNode;  
    while((t != NULL) && (t->data.expn >= item.expn)) 
    {  
        if( t->data.expn == item.expn ) 
            printf("����״��Ѿ�����!\n"); 
        location++; 
        t = t->polyNode; 
    }  
    return location; 
} 
  
void List_Showdata(Linklist *L)//��ʾ�����е���������
 
{  
   
    printf("����ʽ֮�ͽ�������:\n"); 
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
int List_Insert(Linklist *L,int i,term item)//������item���뵽�����iλ�õĺ��� 
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
int Poly_Creat( polynomial *p)//��������ʽ 
{   
    int n;//nΪ����ʽ������ 
    term temp[100]; 
    int i,j,k=0;
	int tmp=0;
	int sig;
	char s[100];  
	printf("�����������ʽ����    2x^4-3x^2+3x^0#\n"); 
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
  
void List_Connect(Linklist *L,Linklist *K)//������������ 
{  
    Linklist p = *L; 
    Linklist q = *K;  
    while(p->polyNode != NULL) 
        p = p->polyNode; 
    p->polyNode = q; 
} 
  
int Poly_Add(polynomial *p1, polynomial *p2)//����ʽ��ӣ����������һ������ 
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
    if(pa != NULL)  // A�����½ڵ�
        List_Connect(&pc,&pa); 
    if(pb != NULL)  // B�����½ڵ�
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