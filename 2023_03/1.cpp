#include<bits/stdc++.h>
using namespace std;

int n,a,b;
int area[101][4];
int res[101][101]{0};

bool is_inmap(int x,int y){
    if(x>0&&x<=a&&y>0&&y<=b&&res[x][y]==1)
        return true;
    return false;
}
bool is_valid(int x,int y){
    if(is_inmap(x,y))
        return true;
    else{
        if(is_inmap(x-1,y-1)||is_inmap(x+1,y-1)||is_inmap(x+1,y+1)||is_inmap(x-1,y+1))
            return true;
        return false;
    }
}
void print_res(){
    for(int i=a;i>0;i--){
        for(int j=1;j<=b;j++){
            printf("%d",res[i][j]);
        }
        printf("\n");
    }
}
int main(){
    scanf("%d%d%d",&n,&a,&b);
    for(int i=0;i<n;i++) 
        scanf("%d%d%d%d",&area[i][0],&area[i][1],&area[i][2],&area[i][3]);
    
    for(int i=0;i<n;i++){
        int x1=area[i][0],y1=area[i][1];
        int x4=area[i][2],y4=area[i][3];
        printf("\n(%d%d)(%d%d)\n",x1,x4,y1,y4);
        for(int j=x1;j<=x4;j++){
            for(int k=y1;k<=y4;k++){
                res[k][j]=1;
            }
        }
        
        
    }
    int res1=0;
    for(int i=a;i>0;i--){
        for(int j=1;j<=b;j++){
            if(is_valid(i,j))
                res1++;
            printf("%d",res[i][j]);
        }
        printf("\n");
    }
    printf("%d",res1);
}