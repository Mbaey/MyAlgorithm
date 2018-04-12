#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
/* 1.txt
8 1 3
*/
const int N=100;
int map[N][N]= {0}, num=1, n;
void disp()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n ; j++)
        {
            printf("%d \t", map[i][j]);
        }
        printf("\n");
    }
    printf("%d **************************\n", num);
}
/*//��Ѫ����������϶�̫���ˡ���
void chessBoard(int tr, int tc, int dr, int dc, int size){
    if(size == 2){
        for(int i=tr; i<tr+size; i++){
            for(int j=tc; j<tc+size ;j++){
                if(map[i][j]==0){
                    map[i][j]= num;
                }
            }
        }
        num++;
    }else{
        int tmp=size/2;
        if(tmp>dr && tmp > dc){//����
            map[tmp][tmp]=num;//����
            map[tmp][tmp-1]=num;//����
            map[tmp-1][tmp]=num;//����
            num++;
            chessBoard(tr, tc, dr, dc, tmp);
            chessBoard(tr+tmp, tc+tmp, tmp, tmp, tmp);
            chessBoard(tr+tmp, tc, tmp, tmp-1, tmp);
            chessBoard(tr, tc+tmp, tmp-1, tmp, tmp);
        }else if(tmp < dr && tmp > dc){//44  31 ����
            map[tr+tmp][tc+tmp]=num;//����
            map[tr][tc]=num;//����
            map[tr][tc+tmp]=num;//����
            num++;
            chessBoard(tr, tc, tr, tc, tmp);
            chessBoard(tr+tmp, tc+tmp, tr+tmp, tc+tmp, tmp);
            chessBoard(tr+tmp, tc, tr+tmp, tc, tmp);
            chessBoard(tr, tc+tmp, tr, tc+tmp, tmp);
        }else if(tmp>dr && tmp < dc){//����
            map[tr+tmp][tc+tmp]=num;//����
            map[tr][tc]=num;//����
            map[tr][tc+tmp]=num;//����
        }else{//����
            map[tr][tc+tmp]=num;//����
            map[tr][tc]=num;//����
            map[tr+tmp][tc]=num;//����
        }
    }
}
*/
void chessBoard(int tr, int tc, int dr, int dc, int size)
{

    if(size == 1)
    {
        return;
    }
    else
    {
        int tn=num++;
        int s=size/2;
        if(tr+s>dr && tc+s>dc) //����
        {
            chessBoard(tr, tc, dr, dc, s);
        }
        else
        {
            map[tr+s-1][tc+s-1]=tn;
            chessBoard(tr, tc, tr+s-1, tc+s-1, s);
        }


        if(tr+s>dr && tc+s <= dc) //����
        {
            chessBoard(tr, tc+s, dr, dc, s);
        }
        else
        {
            map[tr+s-1][tc+s]=tn;
            chessBoard(tr, tc+s, tr+s-1, tc+s, s);
        }

         if(tr+s <= dr && tc+s > dc) //44  31 ����
        {
            chessBoard(tr+s, tc, dr, dc, s);
        }
        else
        {
            map[tr+s][tc+s-1]=tn;
            chessBoard(tr+s, tc, tr+s, tc+s-1, s);
        }

        if(tr+s<= dr && tc+s <= dc) //����
        {
            chessBoard(tr+s, tc+s, dr, dc, s);
        }
        else
        {
            map[tr+s][tc+s]=tn;
            chessBoard(tr+s, tc+s, tr+s, tc+s, s);
        }
    }
    disp();
}
int main()
{
    freopen("1.txt", "r", stdin);
    int dr, dc;
    cin >> n >> dr >> dc;
    map[dr][dc]=num++;
    chessBoard(1,1,dr,dc,n);
    disp();
    return 0;
}
