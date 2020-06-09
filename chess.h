//
// Created by xuting on 2020/6/9.
//

#ifndef FINAL_PJ_CHESS_H
#define FINAL_PJ_CHESS_H

#include <string>

class chessboard;

class chess{
private:
    int id;//棋子等级
    std::string name;//棋子名字
public:
    chess(int i,std::string _name):id(i),name(_name){}
    int get(){return id;}//获取棋子等级
    std::string getname(){return name;}//获取棋子名字
    virtual bool judge_move(chessboard &cb,int startx,int starty,int aimx,int aimy)=0;//判断步伐是否合法
    virtual ~chess(){};//虚析构
};


class horse : public chess{//马的实现
public:
    horse(int i) : chess((i==0?-2:2),(i==0?"馬":"傌")){}//id，horse(0)表示id=-2,否则为2.表示两方
    bool judge_move(chessboard &cb,int startx,int starty,int aimx,int aimy);
};

class soldier : public chess{//兵（卒）的实现
public:
    soldier(int c) : chess((c==0?-1:1),(c==0?"兵":"卒")){}
    bool judge_move(chessboard &cb,int startx,int starty,int aimx,int aimy);
};

class general : public chess{//帅（将）的实现
public:
    general(int c) : chess((c==0?-7:7),(c==0?"帅":"将")){}
    bool judge_move(chessboard &cb,int startx,int starty,int aimx,int aimy);
    ~general();
};

class elephant : public chess{//象（相）的实现
public:
    elephant(int c) : chess((c==0?-6:6),(c==0?"相":"象")){}
    bool judge_move(chessboard &cb,int startx,int starty,int aimx,int aimy);
};

class cannon : public chess{//炮的实现
public:
    cannon(int c) : chess((c==0?-5:5),(c==0?"炮":"砲")){}
    bool judge_move(chessboard &cb,int startx,int starty,int aimx,int aimy);
};

class guard: public chess{//士（仕）的实现
public:
    guard(int c) : chess((c==0?-4:4),(c==0?"士":"仕")){}
    bool judge_move(chessboard &cb,int startx,int starty,int aimx,int aimy);
};

class rook : public chess{//车的实现
public:
    rook(int c) : chess((c==0?-3:3),(c==0?"車":"俥")){}
    bool judge_move(chessboard &cb,int startx,int starty,int aimx,int aimy);
};

#endif //FINAL_PJ_CHESS_H
