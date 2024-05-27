#include<bits/stdc++.h>
using namespace std;
int n;
int res[100]{0};
int num[100][64];
bool same_date(int *a1,int *a2){
    for(int i=0;i<64;i++){
        if(a1[i]!=a2[i])
            return false;
    }
    return true;
}

void update_res(){
    for(int i=0;i<n;i++){
        if(res[i]<1){
        int cout=1;
        res[i]=1;
        for(int j=i+1;j<n;j++){
            if(same_date(num[i],num[j])==true){
                cout++;
                res[j]=cout;
            }
        }
        }
        
    }
}

void input_data(){
    char c;
    for(int i=0;i<n;i++){
        for(int j=0;j<8;j++){
            for(int k=0;k<8;k++){
                scanf("%c",&c);
                num[i][j*8+k]=c;
            }
            getchar();
        }
    }
    
}
int main(){
    scanf("%d",&n);
    getchar();
    input_data();
    update_res();
    for(int i=0;i<n;i++){
        printf("%d",res[i]);
        if(i<n-1){
            printf("\n");
        }
    }
    // printf("\n");
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<64;j++){
    //         printf("%c",num[i][j]);
    //     }
    //     printf("\n");
    // }
}