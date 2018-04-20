#include <cstdio>
#include <cstdlib>
/*
https://blog.csdn.net/darexk/article/details/63696460
*/
void gcd(int a, int b, int& d, int &x, int &y)
{
    if(!b)
    {
        d = a;
        x = 1;
        y = 0;
    }
    else
    {
        gcd(b, a%b, d, x, y);
        int tmpx=x;
        int tmpy=y;

        x = tmpy;
        y = tmpx - tmpy*(a/b);
    }
}
int main()
{
    int a, b, x, y, d;
    scanf("%d%d", &a, &b);
    gcd(a, b, d, x, y);
    printf("%d*%d + %d*%d = %d\n", a, x, b, y, d);
    system("pause");
    return 0;
}

