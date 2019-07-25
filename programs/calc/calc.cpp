#include <STDIO.H> 
#include <STDLIB.H>
#include <iostream>
using namespace std;
#define     MAXSIZE     32
typedef struct{
     int data[MAXSIZE];//数据段
     int top;//栈指针 
}sqstack;
sqstack *sqstack_create()  //创建栈
{
     sqstack *sq;
     sq =(sqstack *)malloc(sizeof(sqstack));
     if(sq == NULL )
     {
         return NULL;
     }
     sq->top = -1;
     return sq;
 }
int sqstack_push(sqstack *sq, int *data)//入栈操作 
{
     if(sq->top == MAXSIZE-1)//full
     {
         return -1;
     }
     else
     {
         sq->data[++sq->top] = *data;
     }
     return 0;
}
int sqstack_top(sqstack *sq, int *data)//取得栈顶数据 
{
     if(sq->top == -1)//empty
     {
         return -1;
     }
     *data = sq->data[sq->top];
     return 0; 
}   
int sqstack_pop(sqstack *sq, int *data)//出栈操作 
{     
     if(sq->top == -1)//empty
     {
         return -1;
     }
     *data = sq->data[sq->top--];
     return 0; 
}   
int compute(sqstack *snum, int ope)  //运算
{
     int n1, n2, n;
     sqstack_pop(snum, &n1);
     sqstack_pop(snum, &n2);
     switch(ope)
     {
         case '+':   n=n1+n2; 
                     printf("%d+%d=%d\n", n1, n2, n); 
                     break;
         case '-':   n=n2-n1; printf("%d-%d=%d\n", n2, n1, n);break;
         case '*':   n=n1*n2; printf("%d*%d=%d\n", n1, n2, n);break;
         case '/':   n=n2/n1; printf("%d/%d=%d\n", n2, n1, n);break;
         default:             return -1;//break;
     }
     sqstack_push(snum, &n);//将运算结果压入数字栈
     return 0; 
}   
void deal_bracket(sqstack *snum, sqstack *sope)//处理括号 
{
     int old_ope;
     sqstack_top(sope, &old_ope);//取得栈顶运算符
     while(old_ope != '(')
     {
         sqstack_pop(sope, &old_ope);
         compute(snum, old_ope);
         sqstack_top(sope, &old_ope);//取得栈顶运算符
     }
     sqstack_pop(sope, &old_ope); 
}   
int sqstack_is_empty(sqstack *sq) 
{
     return (sq->top == -1); 
}   
int get_pri(int ope) 
{
     switch(ope)
     {
         case '(':   return 0;
         case '+':
         case '-':   return 1;
         case '*':
         case '/':   return 2;
     } 
} 
void deal_ope(sqstack *snum, sqstack *sope, int ope)//处理运算符 
{
     int old_ope;
     if(ope == '('||sqstack_is_empty(sope))
     {
         sqstack_push(sope, &ope);
         return ;
     }
     sqstack_top(sope, &old_ope);
     if(get_pri(ope) > get_pri(old_ope))
     {
         sqstack_push(sope, &ope);
         return ;
     }
     while(get_pri(ope) <= get_pri(old_ope))// * +
     {
         sqstack_pop(sope,&old_ope);
         compute(snum,old_ope);
         if(sqstack_is_empty(sope))
             break;
         sqstack_top(sope,&old_ope);
     }
     sqstack_push(sope,&ope); 
}
int checkexp(char str[])
{
	int i;
	int bk=0;
	for(i=0;str[i]!='\0';i++)
		if(str[i]=='(')  bk++;
	for(i=0;str[i]!='\0';i++)
		if(str[i]==')') bk--;
	if(!bk) 
		return 1;
	else
		return 0;
}
int main() {
     sqstack *snum;//运算数字栈
     sqstack *sope;//运算符栈
     int i = 0, value = 0, flag = 0, old_ope;
     char str[MAXSIZE]="\0";// = "1+3-(2*5-2*(4-4/2))*(8-6)+5";//所要计算的表达式
     //初始化

     snum = sqstack_create();
     sope = sqstack_create();

	 cout<<"输入要计算的表达式= ";   
	 gets(str);      //输入要计算的表达式

	 if(!checkexp(str)) //表达式检查
	 {
		 cout<<"输入的表达式括号不匹配！"<<endl;
         return 0;
	 }

	 while(str[i] != '\0')
     {
         if(str[i] >= '0' && str[i] <= '9')//数字
         {
             value = value*10 + str[i]-'0';
             flag = 1;
         }
         else//运算符
         {
             if(flag == 1)//取得了运算的数字
             {
                 sqstack_push(snum, &value);//数值入 运算数字栈
                 value = 0;
                 flag = 0;
             }
             if(str[i] == ')')
             {
                 deal_bracket(snum,sope);
             }
             else//(+-*/
             {
                 deal_ope(snum,sope,str[i]);
             }
         }
         i++;
     }
     if(flag)
     {
         sqstack_push(snum,&value);
     }
     while(!sqstack_is_empty(sope))
     {
         sqstack_pop(sope, &old_ope);
         compute(snum, old_ope);
     }
     sqstack_pop(snum, &value);

     cout<<" 表达式  "<<str<<" 计算结果为："<<value<<endl;   //      printf("%s = %d\n", str, value);
     return 0; 
} 


