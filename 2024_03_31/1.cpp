#include<iostream>
#include<cstring>
using namespace std;

int art[101]={0};
int flag[101]={0};
int numcout[101]={0};
int main(){
    int n,m,k,x;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>k;
        memset(flag,0,sizeof(flag));
        for(int j=1;j<=k;j++){
            cin>>x;
            numcout[x]++;
            if(flag[x]==0){
                art[x]++;
                flag[x]++;
            }
        }
    }

    for(int i=1;i<=m;i++){
        cout<<art[i]<<" "<<numcout[i]<<" "<<endl;
    }
    return 0;
}

