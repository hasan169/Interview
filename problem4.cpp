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
struct node{
    node* next;
    int value;
};
node* stacks[10005];
node* stacksTail[10005];
int main(){
    string str;
    int testcase,i,n,q,x,j;
   // freopen("input.txt","r",stdin);
    scanf("%d",&testcase);
    for(int t = 1; t <= testcase; t++ ){
        scanf("%d%d",&n,&q);
        for( i = 1; i <= n; i++){
            stacks[i] = (struct node*)malloc(sizeof(struct node)); // initializing each stack
            stacks[i]->next = NULL;
            stacksTail[i] = NULL;
        }
        printf("Case %d:\n",t);
        while( q-- ){
            getline(cin,str);
            cin>>str;
        //    cout<<str<<endl;
            if(str == "push"){
                cin>>i>>x;
                node* temp = (struct node*)malloc(sizeof(struct node));
                temp->value = x;
                temp->next = stacks[i]->next;
                if(stacks[i]->next == NULL){
                    stacksTail[i] = temp;
                }
                stacks[i]->next = temp;
            }
            else if(str == "pop"){
                cin>>i;
                if( stacks[i]->next != NULL){
                    node* temp = stacks[i]->next;
                    stacks[i]->next = temp->next;
                    free(temp);
                }
            }
            else if(str == "put"){
                cin>>i>>j;
                if(stacks[j]->next != NULL ){
                    stacksTail[j]->next = stacks[i]->next;
                    stacks[i]->next = stacks[j]->next;
                    stacks[j]->next = NULL;
                }
            }
            else{
                cin>>i;
                if(stacks[i]->next != NULL){
                    node* temp = stacks[i]->next;
                    printf("%d\n",temp->value);
                }
                else{
                    printf("Empty!\n");
                }
            }
        }
        for( i = 1; i <= n; i++ ){
            node* temp = stacks[i];
            while( temp != NULL){
                free(temp);
                temp = temp->next;
            }
            if(stacksTail[i] != NULL){
                free(stacksTail[i]);
            }
        }
    }
    return 0;
}
