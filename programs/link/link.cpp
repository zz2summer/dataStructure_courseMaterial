#include <stdio.h> 
#include <malloc.h> 
  
typedef struct node 
{  
  int data;  
  struct node *next; 
}node; 
node *head; 
int k; 
// 创建链表
node * creates() 
{  
 node *p,*s,*h; 
 int j=1,x, n;  
 p=h=(node*)malloc(sizeof(node)); 
 h->next=NULL;  
 printf("请输入链表长度："); 
 scanf("%d",&n);  
 printf("请输入 %d 个链表节点的值：",n); 
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
 /*在带有头结点单链表的第k个元素之前插入元素i*/ 
 int j; 
 node *p, *t; 
 p=head; 
 j=0;  
 while ( p && j<k-1 ) /*若p不指向空,并且没有找到合适位置则继续循环*/ 
 {  
     p = p->next; 
     j++; 
 }  
 if (!p||j>k-1)  /*k小于1或大于表长*/ 
  printf("插入位置不对。\n");  
 t=(node *)malloc (sizeof (node)); /*生成新结点*/ 
 t->data=i;  
 t->next=p->next; /*插入新结点*/ 
 p->next=t; 
}  
 
  
void deletesNode(node *h,int i) 
{  
 /*在带有头结点单链表的中删除元素为i的节点*/ 
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
    printf("找不到你要删除的元素\n"); 
    return; 
 } 
 else 
 {  
  s=p->next; 
  p->next=s->next; 
  free(s);  
     printf("在位置%d成功删除%d\n",j,i); 
 } 
} 
  
node *lianjie(node *L1,node *L2) 
{
 /*连接两个单链表L1，L2：将L2连接到L1*/   
  node *p1, *p2; 
  p1=L1; 
  p2=p1->next;  
  while(p2->next!=NULL) 
  {  
      p2=p2->next;  
  }//P2指向链表L1的最后一个节点
  
  p2->next=L2->next;//把表二的第一个节点加到表一之后，然后释放表二
 
  return p1; 
} 
  
void hebing (node *L)//清除链表L中相同的元素
 
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
 /*显示单链表节点元素值*/   
    printf("\n链表中的元素为") ; 
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
  printf("这是一个空表%d"); 
 printf("\n"); 
} 
  
int main() 
{  
 node *p,*q,*r,*s; 
 int a,b; 
 char c;  
 printf("/***********单链表的创建、插入、删除等基本操作*************/\n"); 
 p=creates();  
 while(1) 
 {  
    printf("\n请输入你要插入的元素的位置:"); 
    scanf("%d",&b);  
    printf("\n请输入你要插入的元素:"); 
    scanf("%d",&a); 
    insertsNode(p,b,a); 
 
    printf("\n你还要插入其他元素吗？请选择(Y|N)： "); 
 
    c=getchar(); 
 
    printf("%c",c); 
 
    if(c!='Y'&& c!='y') 
    { 
      break; 
    }  
 } 
 print(p);  
 printf("\n你想要删除的元素是:");  
 scanf("%d",&a); 
 deletesNode(p,a); 
 print(p);  
 printf("/*****************单 链 表 的 合 并 *********/\n"); 
 q=creates(); 
 r=creates(); 
 s= lianjie(q,r); 
 hebing(s); 
 print(s);  
 
 return 0; 
} 