//
// Created by xuting on 2020/6/10.
//

#ifndef FINAL_PJ_CHINESE_CHESS_MODEL_H
#define FINAL_PJ_CHINESE_CHESS_MODEL_H

#include <vector>
#include <string>
#include "chess.h"
#include "chess_board.h"
#include "chinese_chessboard.h"


struct movement_for_regret {//为了悔棋的每一步的记录结构。aim表示被吃掉的棋子。
    int startx, starty, aimx, aimy;
    chess* aim;
};

struct ChineseChessModel {
    ChineseChessModel() {};
    ~ChineseChessModel(){};
    std::vector<struct movement_for_regret> recordings;//记录
    std::vector<std::string> displays;//要展示的棋谱容器。
    chessboard Board;
    Chinese_chessboard board_ui;
    void output_vmovement(std::vector<struct movement_for_regret> v);//查看recordings的内容，方便debug。
    void play();
    void recording_for_display(int startx, int starty, int aimx, int aimy);//棋谱记录
    void recording_for_regret(int startx, int starty, int aimx, int aimy, chess* aim);//为了悔棋的记录
    void chess_regret();//悔棋函数
};


#endif //FINAL_PJ_CHINESE_CHESS_MODEL_H
