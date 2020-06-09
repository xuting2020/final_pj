//
// Created by xuting on 2020/6/9.
//

#ifndef FINAL_PJ_CHESS_BOARD_H
#define FINAL_PJ_CHESS_BOARD_H

#include <memory.h>
#include "chess.h"

class chessboard{
private:
    chess *c[10][9];//用指针调用各个棋子，实现多态
//    char chessword[15][4]={"帅","相","炮","士","車","馬","兵","","卒","马","车","仕","砲","象","将"};//名字
public:
    chessboard(){memset(c, NULL, sizeof(c));};//把指针初始化为零指针
    ~chessboard();//析构函数
    //初始化函数，生成棋子
    void init();
    //通过棋盘坐标获取指针
    chess* get(int x,int y){return c[x][y];}
    //
    int getid(int x,int y){ if(c[x][y]!=NULL) return c[x][y]->get();return 0;}
    //显示棋盘
    void show();
    //棋子移动及移动是否合法判断
    bool move(int startx,int starty,int aimx,int aimy);
    //每次点击棋盘调用的函数
    bool move_steps(int x,int y);
    //
    void move_regret(int startx,int starty,int aimx,int aimy,chess *aim);
    //起始棋子的坐标
    int x_start,y_start;
    //
    int state=0;
    //被吃掉的棋子的指针（无则为NULL）
    chess* aim;
    //游戏结束标志
    static bool end;//判断结束
    //谁的游戏回合
    static int player;
};

#endif //FINAL_PJ_CHESS_BOARD_H
