//
// Created by xuting on 2020/6/9.
//

#include "chess_move.h"
#include "chinese_chessboard.h"

class Chinese_chessboard cn_chessboard;

bool Piece_move::be_chesspiece(int row, int col)
{
    for(int i=0;i<32;i++){
        if(cn_chessboard.pieces[i].row==row && cn_chessboard.pieces[i].col==col\
        && !cn_chessboard.pieces[i].is_dead)
            return true;
    }
    return false;
}

bool Piece_move::can_move(int id, bool is_dead, int x, int y)
{

}
