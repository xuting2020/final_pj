//
// Created by xuting on 2020/6/9.
//

#include <iostream>
#include "chess_board.h"

using namespace std;

bool chessboard::end=true;
int chessboard::player=-1;

void chessboard :: init(){//初始化，棋子的生成
    c[0][0]=new rook(0);        c[0][8]=new rook(0);
    c[0][1]=new horse(0);       c[0][7]=new horse(0);
    c[0][2]=new elephant(0);    c[0][6]=new elephant(0);
    c[0][3]=new guard(0);       c[0][5]=new guard(0);
    c[0][4]=new general(0);     c[9][4]=new general(1);
    c[2][1]=new cannon(0);      c[2][7]=new cannon(0);
    c[3][0]=new soldier(0);     c[3][2]=new soldier(0);
    c[3][4]=new soldier(0);     c[3][6]=new soldier(0);
    c[3][8]=new soldier(0);     c[6][8]=new soldier(1);
    c[6][0]=new soldier(1);     c[6][2]=new soldier(1);
    c[6][4]=new soldier(1);     c[6][6]=new soldier(1);
    c[7][1]=new cannon(1);      c[7][7]=new cannon(1);
    c[9][0]=new rook(1);        c[9][8]=new rook(1);
    c[9][1]=new horse(1);       c[9][7]=new horse(1);
    c[9][2]=new elephant(1);    c[9][6]=new elephant(1);
    c[9][3]=new guard(1);       c[9][5]=new guard(1);
}

void chessboard :: show(){
    cout<<"吴  零一二三四五六七八"<<endl<<endl;
    char num[10][4]={"零","一","二","三","四","五","六","七","八","九"};
    for(int i=0;i<10;i++){
        if(i==5) cout<<"    ——楚 河 汉 界———"<<endl;
        cout<<num[i]<<"  ";
        for(int j=0;j<9;j++){
            if(c[i][j]!=NULL)
                cout<<c[i][j]->getname();
            else if((i==1&&j==4)||(i==8&&j==4))
                cout<<"米";
            else
                cout<<"〇";
        }
        cout<<endl;
    }
}

bool chessboard::move(int startx,int starty,int aimx,int aimy)
{
    if(startx>=0&&startx<10&&starty>=0&&starty<9//初步判断传入的点是否符合规则
       &&aimx>=0&&aimx<10&&aimy>=0&&aimy<9//起始、目标坐标不越界
       &&getid(startx,starty)&&getid(startx,starty)*player>0//起始坐标是本回合玩家的棋子
       &&c[startx][starty]->judge_move(*this,startx,starty,aimx,aimy)){//各类棋子的走法是否正确判断
        if(getid(aimx,aimy)==7||getid(aimx,aimy)==-7) delete c[aimx][aimy];
        else aim=c[aimx][aimy];
        //如果目的坐标十“将”或者“帅”则删除指针，游戏结束。
        //否则不删除指针，为了悔棋时恢复改子。
        c[aimx][aimy]=c[startx][starty];
        c[startx][starty]=NULL;
        player*=-1;
        return true;
    }
    cout<<"走法错误，不符合规则"<<endl;
    return false;
}

bool::chessboard::move_steps(int x, int y){
    if(!state){//state=0:起始坐标也没有获取。
        if(x>=0&&x<10&&y>=0&&y<9&&getid(x,y)&&getid(x,y)*player>0){//点击的是己方棋子
            state=1;//获取起始坐标
            x_start=x;
            y_start=y;
        }
        return false;
    }
    else{//state=1的情况，再调用move函数
        bool b;
        if(x>=0&&x<10&&y>=0&&y<9&&getid(x,y)&&getid(x,y)*player>0){//点击的是仍己方棋子，更改起始坐标
            x_start=x;
            y_start=y;
            return false;
        }
        else{//不是己方棋子，调用move函数。
            b=move(x_start,y_start,x,y);
            if(b) state=0;//目标坐标也正确，b为true，这一步合法且在move实施了。重置state。
            return b;
        }
    }
}

void chessboard::move_regret(int startx,int starty,int aimx,int aimy, chess *aim){//悔棋移动
    c[startx][starty]=c[aimx][aimy];
    c[aimx][aimy]=aim;
    player=-player;
}

chessboard::~chessboard(){
    for(int i=0;i<10;i++)
        for(int j=0;j<9;j++)
            if(c[i][j]!=NULL){
                delete c[i][j];
                c[i][j]=NULL;
            }
}