#include <stdio.h> 
#include <malloc.h> 
  
typedef struct node 
{  
  int data;  
  struct node *next; 
}node; 
node *head; 
int k; 
// ��������
node * creates() 
{  
 node *p,*s,*h; 
 int j=1,x, n;  
 p=h=(node*)malloc(sizeof(node)); 
 h->next=NULL;  
 printf("�����������ȣ�"); 
 scanf("%d",&n);  
 printf("������ %d ������ڵ��ֵ��",n); 
 while(j<=n) 
 {  
    scanf("%d",&x);  
    s=(node*)malloc(sizeof(node)); 
    s->data=x; 
    p->next=s; 
    p=s; 
    j++; 
 }  
  p->next=NULL; 
  return h; 
} 
 
  
void insertsNode(node *head, int k, int i) 
{  
 /*�ڴ���ͷ��㵥����ĵ�k��Ԫ��֮ǰ����Ԫ��i*/ 
 int j; 
 node *p, *t; 
 p=head; 
 j=0;  
 while ( p && j<k-1 ) /*��p��ָ���,����û���ҵ�����λ�������ѭ��*/ 
 {  
     p = p->next; 
     j++; 
 }  
 if (!p||j>k-1)  /*kС��1����ڱ�*/ 
  printf("����λ�ò��ԡ�\n");  
 t=(node *)malloc (sizeof (node)); /*�����½��*/ 
 t->data=i;  
 t->next=p->next; /*�����½��*/ 
 p->next=t; 
}  
 
  
void deletesNode(node *h,int i) 
{  
 /*�ڴ���ͷ��㵥�������ɾ��Ԫ��Ϊi�Ľڵ�*/ 
 node *p,*s,*q; 
 int j=1; 
 p=h;  
 while(p->next!=NULL) 
 {  
  q=p->next; 
  if(q->data==i) 
   break; 
  p=p->next; 
  j++; 
 } 
  
 if(p->next==NULL) 
 {  
    printf("�Ҳ�����Ҫɾ����Ԫ��\n"); 
    return; 
 } 
 else 
 {  
  s=p->next; 
  p->next=s->next; 
  free(s);  
     printf("��λ��%d�ɹ�ɾ��%d\n",j,i); 
 } 
} 
  
node *lianjie(node *L1,node *L2) 
{
 /*��������������L1��L2����L2���ӵ�L1*/   
  node *p1, *p2; 
  p1=L1; 
  p2=p1->next;  
  while(p2->next!=NULL) 
  {  
      p2=p2->next;  
  }//P2ָ������L1�����һ���ڵ�
  
  p2->next=L2->next;//�ѱ���ĵ�һ���ڵ�ӵ���һ֮��Ȼ���ͷű��
 
  return p1; 
} 
  
void hebing (node *L)//�������L����ͬ��Ԫ��
 
{  
  node *s,*t,*r; 
  s=L->next; 
  while(s)  
  { 
     t=s; 
     r=s->next; 
     while(t->next) 
     {  
      if(s->data==r->data) 
      {  
        t->next=r->next; 
        r=t->next; 
      } 
      else 
      {  
        t=t->next; 
        r=r->next; 
      } 
    }  
    s=s->next; 
  } 
} 
  
void print(node *h) 
{
 /*��ʾ������ڵ�Ԫ��ֵ*/   
    printf("\n�����е�Ԫ��Ϊ") ; 
 node *s; 
 s=h->next; 
 if(s!=NULL) 
 {  
  while(s!=NULL) 
  {  
     printf(" %d ",s->data) ;
     s=s->next; 
  } 
 } 
 else  
  printf("����һ���ձ�%d"); 
 printf("\n"); 
} 
  
int main() 
{  
 node *p,*q,*r,*s; 
 int a,b; 
 char c;  
 printf("/***********������Ĵ��������롢ɾ���Ȼ�������*************/\n"); 
 p=creates();  
 while(1) 
 {  
    printf("\n��������Ҫ�����Ԫ�ص�λ��:"); 
    scanf("%d",&b);  
    printf("\n��������Ҫ�����Ԫ��:"); 
    scanf("%d",&a); 
    insertsNode(p,b,a); 
 
    printf("\n�㻹Ҫ��������Ԫ������ѡ��(Y|N)�� "); 
 
    c=getchar(); 
 
    printf("%c",c); 
 
    if(c!='Y'&& c!='y') 
    { 
      break; 
    }  
 } 
 print(p);  
 printf("\n����Ҫɾ����Ԫ����:");  
 scanf("%d",&a); 
 deletesNode(p,a); 
 print(p);  
 printf("/*****************�� �� �� �� �� �� *********/\n"); 
 q=creates(); 
 r=creates(); 
 s= lianjie(q,r); 
 hebing(s); 
 print(s);  
 
 return 0; 
} 