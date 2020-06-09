//
// Created by xuting on 2020/6/10.
//

#include <iostream>
#include "chinese_chess_model.h"

using namespace std;

static void output_vstring(vector<string> v)
{
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
}

static string to_chinese_number(int n) {
    switch (n) {
        case 0:return "一";
        case 1:return "二";
        case 2:return "三";
        case 3:return "四";
        case 4:return "五";
        case 5:return "六";
        case 6:return "七";
        case 7:return "八";
        case 8:return "九";
        case 9:return "十";
    }
}

void ChineseChessModel::output_vmovement(vector<struct movement_for_regret> v)
{
    for(int i=0;i<v.size();i++){
        cout<<v[i].startx<<" "<<v[i].starty<<" "<<v[i].aimx<<" "<<v[i].aimy<<" "<<endl;
    }
}

void ChineseChessModel::recording_for_regret(int startx, int starty, int aimx, int aimy, chess* aim) {
    struct movement_for_regret mv_temp;
    mv_temp.startx = startx;
    mv_temp.starty = starty;
    mv_temp.aimx = aimx;
    mv_temp.aimy = aimy;
    mv_temp.aim = aim;
    recordings.push_back(mv_temp);
}

void ChineseChessModel::chess_regret() {
    struct movement_for_regret rmove = recordings[recordings.size() - 1];//获取最新的下棋记录
    Board.move_regret(rmove.startx, rmove.starty, rmove.aimx, rmove.aimy, rmove.aim);
    recordings.pop_back();//删除最新的记录
    displays.pop_back();//删除最新的记录
}

void ChineseChessModel::recording_for_display(int startx, int starty, int aimx, int aimy) {
    string to_chinese_number(int n);
    string result=Board.get(aimx, aimy)->getname();
    string temp;
    if (Board.player*(startx-aimx)<0) temp = "进";
    else if (Board.player*(startx-aimx)>0) temp = "退";
    else temp = "平";
    result = result  + to_chinese_number(Board.player>0?starty:8-starty) + temp;
    if (starty == aimy) result = result + to_chinese_number((startx > aimx ? (startx - aimx) : (aimx - startx)) - 1);
    else result = result + to_chinese_number(aimy);
    displays.push_back(result);
};

void ChineseChessModel::play(){
    Board.init();
    Board.show();
    do{
        int x,y;
        int sid,aid;
        int reg=0;
        do{
            cout<<"是否悔棋？输入1悔棋，输入0不悔棋";
            cin>>reg;
            if(reg) {
                chess_regret();
                output_vstring(displays);
                output_vmovement(recordings);
                Board.show();
            }
        }while(reg);
        do{
            sid=aid=0;
            cout<<"请输入坐标：";
            cin>>x>>y;
        }while(!Board.move_steps(x,y));//在move函数中完成移动
        Board.show();
//        board_ui.show();
        //board_ui.update(Board.get()); repaint in update function
        recording_for_display(Board.x_start,Board.y_start,x,y);
        recording_for_regret(Board.x_start,Board.y_start,x,y,Board.aim);
        output_vstring(displays);
        output_vmovement(recordings);
    }while(Board.end);
    cout<<"结束，赢家是Player"<<(Board.player==1?1:2)<<endl;
}