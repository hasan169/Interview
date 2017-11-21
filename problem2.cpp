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
char str[105];
int main(){
    int length,counter;
    bool lowerCase,upperCase,digit;
   // freopen("input.txt","r",stdin);
    while(scanf("%s",str) == 1){
        lowerCase = false;
        upperCase = false;
        digit = false;
        counter = 0;
        length = strlen(str);
        for( int i = 0; i < length; i++ ){
            if(str[i] >= 'a' && str[i] <= 'z')lowerCase = true; // sets lowercase to true if a lowercase char found
            if(str[i] >= 'A' && str[i] <= 'Z')upperCase = true; // sets uppercase to true if a uppercase char found
            if(str[i] >= '0' && str[i] <= '9') digit = true; // sets digit to true if a digit found
            if(lowerCase && upperCase && digit){ // checking if all the requirements are true
                counter++; // incrementing counter
                /*
                    setting each boolean to false
                */
                digit = false;
                lowerCase = false;
                upperCase = false;
            }
        }
        printf("%d\n",counter); // printing ans
    }
    return 0;
}
