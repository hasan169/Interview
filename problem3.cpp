#include<iostream>
#include<string>
#include<queue>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){

    int a,b,testcase;
    scanf("%d",&testcase);
    for( int t = 1; t <= testcase; t++ ){
        scanf("%d%d",&a,&b);
        printf("Case %d: %d%d\n",t,a+b,a-b);
    }
}
