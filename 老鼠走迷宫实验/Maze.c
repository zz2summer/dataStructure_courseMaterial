#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int createMaze();       //��������Թ�
int createFreeMaze();   //�����Զ����Թ�
void createWall();      //�����Թ���ǽ
int visit(int row2, int col2) ;

int startI = 1, startJ = 1;          // ���
int success = 0;
//�Թ�����
int maze[100][100];
int row = 0;
int col = 0;
//�Թ�����2����ǽ�ڣ�0����ͨ��

//�����Թ���ǽ
void createWall()   
{
    //�����Թ���ǽ,��һ�С���һ�С����һ�С����һ�о�Ϊǽ��
    for(int i = 0; i < col; i++)//��һ��
         maze[0][i] = 2;
    for(int i = 1; i < row; i++)//��һ��
         maze[i][0] = 2;
    for(int i = 1; i < col; i++)//���һ��
         maze[row-1][i] = 2;    
    for(int i = 1; i < row-1; i++)//���һ��
         maze[i][col-1] = 2;
}

//��������Թ�
int createMaze()
{
    srand(time(0));
    for(int i = 1; i < row-1; i++)
    {
        for(int j = 1; j < col-1; j++)
        {
             if((rand()%100+1) % 2 == 0)
                maze[i][j] = 0;
             else
                maze[i][j] = 2;
         }
     }
    maze[1][1] = 0;
    maze[row-2][col-2] = 0;
}

//�����Զ����Թ�
int createFreeMaze()
{
    for(int i = 1; i < row-1; i++)
    {
        //��һ�У���һ��Ϊ���
        if(i == 1)
        {
           printf("�Թ���%d�У���%d��  ",i,col-3);
           for(int j = 2; j < col-1; j++)
              scanf("%d",&maze[i][j]);
        }
        //���һ��,���һ��Ϊ����
        else if(i == row-2)  
        {
            printf("�Թ���%d�У���%d��",i,col-3);
            for(int j = 1; j < col-2; j++)
               scanf("%d",&maze[i][j]);
        }
        else
        {
            printf("�Թ���%d�У���%d��",i,col-2);
            for(int j = 1; j < col-1; j++)
                scanf("%d",&maze[i][j]);
         }
     }
    maze[1][1] = 0;           //���Ϊͨ��
    maze[row-2][col-2] = 0;   //����Ϊͨ��
}

int visit(int row2, int col2) 
{ 
    int endI = row-2, endJ = col-2;      // ����
    //�õ��߹������Ϊ1
    maze[row2][col2] = 1; 
    //�ߵ��յ㣬�ɹ�
    if(row2 == endI && col2 == endJ)
        success = 1; 
    //���ĸ�����ݹ���ú���visit()
    if(success != 1 && maze[row2][col2+1] == 0) 
          visit(row2, col2+1); 
    if(success != 1 && maze[row2+1][col2] == 0) 
          visit(row2+1, col2); 
    if(success != 1 && maze[row2][col2-1] == 0) 
          visit(row2, col2-1); 
    if(success != 1 && maze[row2-1][col2] == 0) 
          visit(row2-1, col2); 
 
    //�õ��߹�����û�ɹ�����õ�������Ϊ0
    if(success != 1) 
        maze[row2][col2] = 0; 
    
    return success; 
} 

int main(void) 
{ 
    int i, j;

    printf("�������Թ�����row(0<row<100)��");    
    scanf("%d",&row);
    printf("�������Թ�����col(0<col<100)��");
    scanf("%d",&col);

    createWall();//�����Թ���ǽ

    int choice;
    printf("��ѡ�񴴽�����Թ������Զ����Թ���1Ϊ����Թ���2Ϊ�Զ����Թ���:");
    scanf("%d",&choice);
    if(choice == 1)
    {
        createMaze();   //�����Թ�
    }
    else if(choice == 2)
    {
         printf("\n�������Զ����Թ���ǽ�ں�ͨ����2����ǽ�ڣ�0����ͨ��\n");
         createFreeMaze();
     }

    printf("\n��ʾ�Թ���\n"); 
    for(i = 0; i < row; i++)
    { 
        for(j = 0; j < col; j++) 
        {
            if(maze[i][j] == 2) 
                printf("��"); 
            else 
                printf("  "); 
        }
       printf("\n"); 
    }

    if(visit(startI, startJ) == 0)
    {
        printf("\nû���ҵ����ڣ�\n"); 
    }
   else 
   { 
        printf("\n��ʾ·����\n"); 
        for(i = 0; i < row; i++) 
       { 
            for(j = 0; j < col; j++)
            { 
                if(maze[i][j] == 2) 
                    printf("��"); 
                else if(maze[i][j] == 1) 
                    printf("��"); 
                else 
                    printf("  "); 
            } 
            printf("\n"); 
        } 
    }

    system("pause");

    return 0; 
}