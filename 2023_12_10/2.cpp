#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=10*x+(c-'0');
        c=getchar();
    }

    return x*f;
}
inline long long LLread(){
    long long x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=10*x+(c-'0');
        c=getchar();
    }
    return x*f;
}
long long preList[10000]{2,3};
int preListSize=2;
void FillPreList(long long n=1e10){
    long long C=sqrt(n)+1;
    for(int i=5;i<=C;i++){
        bool flag=true;
        for(int j=0;j<preListSize;j++){
            if(i%preList[j]==0){
                flag=false;
                break;
            }
        }
        if(flag==true){
                preList[preListSize++]=i;//记录所有质数
        }
    }
}
long long Nums[15]{0};
int Ks[15]{0};

int main(){
    int n=read();
    long long Maxnum=0;
    for(int i=1;i<=n;i++){
        Nums[i]=LLread();
        Ks[i]=read();
        Maxnum=Maxnum>Nums[i]?Maxnum:Nums[i];//记录输入最大值
    }
    FillPreList(Maxnum);
    for(int i=1;i<=n;i++){
        int Curindex=0,Curcnt=0;
        long long CurAns=1;
        while(Curindex<preListSize){
            if(Nums[i]%preList[Curindex]==0)//能够整除当前质数
            {
                Curcnt++;                   //不修改index,寻找当前能够整除质数的最大个数
                Nums[i] /= preList[Curindex];
            }
            else{
                if(Curcnt>=Ks[i])//cnt>=Ks,满足题目要求,计入结果
                {
                    CurAns *= pow(preList[Curindex],Curcnt);
                }
                Curcnt=0;//clear
                ++Curindex;//寻找下一个质数
            }
        }
        cout << CurAns<<'\n';
    }

    return 0;
}