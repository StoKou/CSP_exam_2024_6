#include<cstdio>

const int N=1001;
const int M=11;
int res[N]={-1};
int compa[N][M]={0};

int cp(int *a,int *b,int len){//a[any]>b[any] or a[any]<b[any] or neither
    int cout1=0,cout2=0;
    for(int i=1;i<=len){
        if(a[i]>b[i]){
            cout1++;
        }
        if(a[i]<b[i]){
            cout2++;
        }
    }
    if(cout1==len)  return 1;//
    else if(cout2==len) return -1;
    else return 0;
}
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
            nowcap[j]=x;
            if(i==1){
                maxcap[j]=x;
            }//store first as max--start   
        }
        int te=cp(maxcap,nowcap,m);//result
        if(te==1){//max>now
            res[i]=maxindex;
            
        }else if(te==-1){//max<now
            for(int j=1;j<=m;j++){
                maxcap[j]=nowcap[j];
            }
            maxindex=i;//change max
        }
    }
    for(int i=2;i<=n;i++){
        if(res[i]==-1){
            for(int j=i;j<=n;j++){
                if(cp(compa[i],compa[j],m)==-1){
                    res[i]=j;
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