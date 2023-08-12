#include <iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
int main()
{
    int num;
    scanf("%d",&num);
    if (num == 1) printf("%d", 0);
    else if(num<=1000)
    {
        int prime[100];
        bool visited[1000]{false};
        int cnt = 0;
        for (int i = 2; i <= num; ++i)
        {
            if(!visited[i])
            {
                prime[cnt++] = i;
                visited[i] = true;
            }
            for (int j = 0; j < cnt && i * prime[j] <= num; ++j)
            {
                visited[i * prime[j]] = true;
                if (i % prime[j] == 0)break;
            }
        }
        double res = 2*double(cnt) / num/num;
        printf("%.10lf", res);
    }
    else
    {
        double res = 2 /double(log(num))/ num;
        printf("%.10lf",res);
    }
}