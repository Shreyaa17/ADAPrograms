#include<stdio.h>
int board[40][40];
int tile=1;
void tilingBoard(int trow, int tcol, int drow, int dcol,int size)
{
    if(size==1)
        return;
    int qsize=size/2;
    int tileToUse=tile++;
    if(drow<=trow+qsize-1 && dcol<=tcol+qsize-1)
    {
        tilingBoard(trow,tcol,drow,dcol,qsize);
    }
    else
    {
        board[trow+qsize-1][tcol+qsize-1]=tileToUse;
        tilingBoard(trow,tcol,trow+qsize-1,tcol+qsize-1,qsize);
    }
    if(drow<=trow+qsize-1 && dcol>=tcol+qsize)
    {
        tilingBoard(trow,tcol+qsize,drow,dcol,qsize);
    }
     else
    {
        board[trow+qsize-1][tcol+qsize]=tileToUse;
        tilingBoard(trow,tcol+qsize,trow+qsize-1,tcol+qsize,qsize);
    }
    if(drow>=trow+qsize && dcol<=tcol+qsize-1)
    {
        tilingBoard(trow+qsize,tcol,drow,dcol,qsize);
    }
    else
    {
        board[trow+qsize][tcol+qsize-1]=tileToUse;
        tilingBoard(trow+qsize,tcol,trow+qsize,tcol+qsize-1,qsize);
    }
    if(drow>=trow+qsize && dcol>=tcol+qsize)
    {
        tilingBoard(trow+qsize,tcol+qsize,drow,dcol,qsize);
    }
    else
    {
        board[trow+qsize][tcol+qsize]=tileToUse;
        tilingBoard(trow+qsize,tcol+qsize,trow+qsize,tcol+qsize,qsize);
    }
}

int main()
{
    int n,drow,dcol,i,j;
    printf("Enter the size\n");
    scanf("%d", &n);
    printf("Enter defective row and column\n");
    scanf("%d %d", &drow, &dcol);
    tilingBoard(0,0,drow,dcol,n);
    printf("Chess Board after Tiling:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}
