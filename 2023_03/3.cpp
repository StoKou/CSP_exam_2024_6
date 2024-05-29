#include<bits/stdc++.h>
#include<vector>
using namespace std;
int n,m;

typedef struct User{
    int DN;
    int Attr_num;
    int attr[100]{0};
}User;

User user[100];

vector< vector<int> >res(100);
bool cmp(int a,int b){
    return a<b;
}
int main(){
    std::cin>>n;
    for(int i=0;i<n;i++){
        std::cin>>user[i].DN;
        std::cin>>user[i].Attr_num;
        int ind,value;
        for(int j=0;j<user[i].Attr_num;j++){
            std::cin>>ind>>value;
            user[i].attr[ind]=value;
        }
    }
    std::cin>>m;
    int attr0,value0;
    char opt;
    for(int i=0;i<m;i++){
        int cnt=0;
        scanf("%d%c%d",&attr0,&opt,&value0);
        getchar();
        // printf("\nopt->%c",opt);
        if(opt==':'){
            for(int j=0;j<n;j++){
                if(user[j].attr[attr0]==value0){
                    res[i].push_back(user[j].DN);
                }
            }
            std::sort(res[i].begin(),res[i].begin()+cnt,cmp);
        }
        else{
            for(int j=0;j<n;j++){
                if(user[j].attr[attr0]!=value0&&user[j].attr[attr0]!=0){
                    res[i].push_back(user[j].DN);
                }
            }
            std::sort(res[i].begin(),res[i].begin()+cnt,cmp);
        }
    }
    bool fisrt=true;
    for(int i=0;i<m;i++){
        fisrt=true;
        for(int j=0;j<res[i].size();j++){
            if(fisrt==true){
                fisrt=false;
                printf("%d",res[i][j]);
            }
            else{
                printf(" %d",res[i][j]);
            }
        }
        printf("\n");
    }

}