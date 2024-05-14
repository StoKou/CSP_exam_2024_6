#include<cstdio>
using namespace std;

char word[10];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        
        scanf("%s",word);
        printf("%s",word);
    }
    for(int i=1;i<=m;i++){
        scanf("%s",word);
        printf("%s",word);
    }
    return 0;
}