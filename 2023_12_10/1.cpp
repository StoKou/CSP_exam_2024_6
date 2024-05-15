#include<cstdio>

const int N=1001;
const int M=11;
int res[N]={0};
int compa[N][M]={0};

int maxcap[M],nowcap[M];
int maxindex=1;//1 --start
int main(){
    int n,m;
    int x;
    scanf("%d%d",&n,&m);
    //init
    res[1]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&x);
            compa[i][j]=x;//store
            }//store first as max--start   
        
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j){
                bool flag=true;
                for(int k=1;k<=m;k++){
                    if(compa[i][k]>=compa[j][k]){
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    maxindex=j;
                    res[i]=j;
                    break;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d",res[i]);
        if(i<n){
            printf("\n");
        }
    }

}