#include<bits/stdc++.h>

int s;
char c1[1024];
int printnum=0;
int guide=0;
int cnt=0;
char res[2048];
int get_ten(char c){
    if(c>='0'&&c<='9'){
        return c-'0';
    }else{
        return (c-'a')+10;
    }
}
int get_ten_num(char c1,char c2){
    int num1=get_ten(c1);
    int num2=get_ten(c2);
    return num1*16+num2;
}
void get_printnum(){
    int num1=0;
    int b8=get_ten_num(c1[guide-1],c1[guide]);
    while(b8!=0){
        int low=b8%2;
        printnum=128*printnum+low;
        b8=b8/2;
    }
    printnum *=128;
}
void print_cnt(int num){
    for(int i=0;i<num;i++){
        if(cnt!=0&&cnt%16==0)
            printf("\n");
        printf("%c%c",c1[guide+1],c1[guide+2]);
        res[cnt]=c1[guide+1];
        res[cnt+1]=c1[guide+2];
        guide+=2;
        cnt+=2;
    }
}
void print_back(int o,int l){
    if(o<l){
        int guide_2=cnt-2*o;
        int cnt_2=0;
        for(int i=0;i<l;i++){
            if(cnt!=0&&cnt%16==0)
                printf("\n");
            printf("%c%c",res[guide_2+cnt_2],res[guide_2+cnt_2+1]);
            cnt_2=(cnt_2+2)%(2*o);
            res[cnt]=res[guide_2+cnt_2];
            res[cnt+1]=res[guide_2+cnt_2+1];
            cnt+=2;
        }
    }else if(o>=l){
        int guide_2=cnt-2*o;
        int cnt_2=0;
        for(int i=0;i<l;i++){
            if(cnt!=0&&cnt%16==0)
                printf("\n");
            printf("%c%c",res[guide_2+cnt_2],res[guide_2+cnt_2+1]);
            cnt_2+=2;
            res[cnt]=res[guide_2+cnt_2];
            res[cnt+1]=res[guide_2+cnt_2+1];
            cnt+=2;
        }
    }
}
void mode_0(char c3,char c4){
    int num=get_ten_num(c3,c4);
    int high_six=num/4;
    if(high_six<60){
        print_cnt(high_six+1);
    }else{
        int next=high_six-59;
        if(next==1){
            guide+=2;
            int b8=get_ten_num(c1[guide-1],c1[guide]);
            print_cnt(b8+1);
        
        }else if(next==2){
            guide+=2;
            int num1=get_ten_num(c1[guide-1],c1[guide]);
            guide+=2;
            int num2=get_ten_num(c1[guide-1],c1[guide]);
            int b8=128*num2+num1;
            print_cnt(b8);
        }else if(next==3){
            guide+=2;
            int num1=get_ten_num(c1[guide-1],c1[guide]);
            guide+=2;
            int num2=get_ten_num(c1[guide-1],c1[guide]);
            guide+=3;
            int num3=get_ten_num(c1[guide-1],c1[guide]);
            int b8=128*128*num3+128*num2+num1;
            print_cnt(b8);
        }else if(next==4){

        }
    }

}
void mode_1(char c3,char c4){
    int num=get_ten_num(c3,c4);
    int l=(num%32-1)/4+4;
    guide+=2;
    int num2=get_ten_num(c1[guide-1],c1[guide]);
    int o=num/32*128+num2;
    // printf("\no:%d l:%d cnt:%d\n",o,l,cnt);
    print_back(o,l);
}
void mode_2(char c3,char c4){
    int num=get_ten_num(c3,c4);
    int high_six=num/4;
    guide+=2;//
    int num1=get_ten_num(c1[guide-1],c1[guide]);
    guide+=2;
    int num2=get_ten_num(c1[guide-1],c1[guide]);
    int o=128*num2+num1;
    int l=high_six+1;
    
    print_back(o,l);
}
void select_mode(char c3,char c4){
    int mode=get_ten(c4)%4;
    // printf("\nmode:%d\n",mode);
    if(mode==0){
        mode_0(c3,c4);
    }else if(mode==1){
        mode_1(c3,c4);
    }else{
        mode_2(c3,c4);
    }
}
void get_output(){
    for(int i=0;i<s*2;i++){
        if(i!=0&&i%16==0)
            getchar();
        scanf("%c",&c1[i]);
    }
    while(c1[guide]>='8'){
        guide+=2;
    }
    guide+=1;
    get_printnum();
    
    while(printnum*2>cnt){
        guide+=2;
        select_mode(c1[guide-1],c1[guide]);
    }
    
}

int main(){
    scanf("%d",&s);
    getchar();
    get_output();
    
}