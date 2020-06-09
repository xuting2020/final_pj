//
// Created by xuting on 2020/6/9.
//

#ifndef FINAL_PJ_CHESS_MOVE_H
#define FINAL_PJ_CHESS_MOVE_H

#include "chinese_chessboard.h"
#include "chess_piece.h"

class Piece_move
{
public:

    //判断棋子是否可以移动
    bool can_move(int id,bool is_dead,int x,int y);
    //判断各种棋子是否可以移动
    bool can_move_guard(int id,bool is_dead, int x,int y);
    bool can_move_rook(int id,bool is_dead,int x,int y);
    bool can_move_general(int id,bool is_dead,int x,int y);
    bool can_move_elephant(int id,bool is_dead,int x,int y);
    bool  can_move_cannon(int id,bool is_dead,int x,int y);
    bool can_move_horse(int id,bool is_dead,int x,int y);
    bool can_move_soldier(int id,bool is_dead,int x,int y);
    //判断是否该坐标是否有棋子
    bool be_chesspiece(int row,int col);
    //根据行列坐标得出棋子的id
    int get_chess_id(int row,int col);
    //计算即将行走的棋子与某一坐标之间有几颗棋子
    int num_chess(int id,int x,int y);
    //判断两个棋子是否是同一方的
    bool same_color(int id1,int id2);


    Piece_move();

};


#endif //FINAL_PJ_CHESS_MOVE_H
