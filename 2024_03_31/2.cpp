#include<cstdio>
#include<cstring>
using namespace std;

char word[10];
int same[10000000]={0};
int diff[10000000]={0};

int cout_same=0;
int cout_diff=0;
void gn(char* s){
    int len=strlen(s);
    int index=0;
    for(int i=0;i<len;i++){
        if(s[i]>='A'&&s[i]<='Z'){
            index=(i+1)*(index+(s[i]-'A'));
        }
        else{
            index=(i+1)*(index+(s[i]-'a'));
        }
    }

    same[index]++;
    diff[index]++;
    if(same[index]==2){
        cout_same++;
    }
    if(diff[index]==1){
        cout_diff++;
    }
    return;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    getchar();
    for(int i=1;i<=n;i++){
        scanf("%s",word);
        gn(word);
        // printf("%s\n",word);
    }
    for(int i=1;i<=m;i++){
        scanf("%s",word);
        gn(word);
        // printf("%s\n",word);
    }
    printf("%d\n%d",cout_same,cout_diff);
    return 0;
}