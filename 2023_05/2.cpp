#include<bits/stdc++.h>
int n,d;
int Q[10000][20];
int QKT[10000][10000]{0};
int KT[20];
int V[10000][20];
int W[10000];
int RES[10000][20]{0};
int multiple(int *a1,int *a2,int len){
    int res=0;
    for(int i=0;i<len;i++){
        res+=a1[i]*a2[i];
    }
    return res;
}

void getdata(){
    for(int i=0;i<n;i++){
        for(int j=0;j<d;j++){
            scanf("%d",&Q[i][j]);
            getchar();
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<d;j++){
            scanf("%d",&KT[j]);
            getchar();
        }
        for(int k=0;k<n;k++){
            QKT[k][i]=multiple(Q[k],KT,d);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<d;j++){
            scanf("%d",&V[i][j]);
            getchar();
        }
    }
    for(int i=0;i<n;i++){
        scanf("%d",&W[i]);
        for(int j=0;j<n;j++){
            QKT[i][j]=QKT[i][j]*W[i];
        }
    }
    
}

void matrix_multiple(){
    for(int i=0;i<n;i++){
        for(int j=0;j<d;j++){
            for(int i1=0;i1<n;i1++){
                RES[i][j]+=QKT[i][i1]*V[i1][j];
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&d);
    getdata();
    matrix_multiple();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<d;j++){
            printf("%d ",RES[i][j]);
        }
        if(i<n-1)
            printf("\n");
    }
}  