//
// Created by xuting on 2020/6/9.
//

#include "chess.h"
#include "chess_board.h"

using namespace std;



bool horse::judge_move(chessboard &cb,int startx,int starty,int aimx,int aimy){
    int tempx=aimx-startx,tempy=aimy-starty;
    int sid=cb.getid(startx, starty),aid=cb.getid(aimx, aimy);
    if(sid*aid<=0&&(tempx*tempx+tempy*tempy==5)&&!cb.get(startx+tempx/2,starty+tempy/2))
        return true;
    return false;
}


bool soldier::judge_move(chessboard &cb,int startx,int starty,int aimx,int aimy){
    int tempx=aimx-startx,tempy=aimy-starty;
    int sid=cb.getid(startx, starty),aid=cb.getid(aimx, aimy);
    if(sid*aid<=0&&sid*tempx<=0){
        if(abs(tempx)==1&&tempy==0) return true;
        if(abs(tempy)==1&&tempx==0)
            if((startx/5==0&&sid>0)||(startx/5==1&&sid<0)) return true;
        return false;
    }
    return false;
}

bool general::judge_move(chessboard &cb,int startx,int starty,int aimx,int aimy){
    int tempx=aimx-startx,tempy=aimy-starty;
    int sid=cb.getid(startx, starty),aid=cb.getid(aimx, aimy);
    if(sid*aid<=0&&tempy*tempy+tempx*tempx==1&&aimx%7>=0&&aimx%7<=2&&aimy>=3&&aimy<=5)
        return true;
    return false;
}

general::~general(){chessboard::end=false;}



bool elephant::judge_move(chessboard &cb,int startx,int starty,int aimx,int aimy){
    int tempx=aimx-startx,tempy=aimy-starty;
    int sid=cb.getid(startx, starty),aid=cb.getid(aimx, aimy);
    if(sid*aid<=0&&tempy*tempy+tempx*tempx==8&&startx/5==aimx/5&&!cb.get(startx+tempx/2,starty+tempy/2))
        return true;
    return false;
}



bool cannon::judge_move(chessboard &cb,int startx,int starty,int aimx,int aimy){
    int tempx=aimx-startx,tempy=aimy-starty;
    int sid=cb.getid(startx, starty),aid=cb.getid(aimx, aimy);
    if(sid*aid<=0&&!(tempx&&tempy)&&(tempx+tempy)){
        int tot=0;
        if(tempx!=0){
            int sign=tempx>0?1:-1;
            for(int i=1;i<abs(tempx);i++)
                if(cb.get(startx+sign*i,starty)) tot++;
        }
        else{
            int sign=tempy>0?1:-1;
            for(int i=1;i<abs(tempy);i++)
                if(cb.get(startx,starty+sign*i)) tot++;
        }
        if(!aid)
        {if(!tot) return true;}
        else
        {if(tot==1) return true;}
    }
    return false;
}


bool guard::judge_move(chessboard &cb,int startx,int starty,int aimx,int aimy){
    int tempx=aimx-startx,tempy=aimy-starty;
    int sid=cb.getid(startx, starty),aid=cb.getid(aimx, aimy);
    if(sid*aid<=0&&tempy*tempy+tempx*tempx==2&&aimx%7>=0&&aimx%7<=2&&aimy>=3&&aimy<=5)
        return true;
    return false;
}


bool rook::judge_move(chessboard &cb,int startx,int starty,int aimx,int aimy){
    int tempx=aimx-startx,tempy=aimy-starty;
    int sid=cb.getid(startx, starty),aid=cb.getid(aimx, aimy);
    if(sid*aid<=0&&!(tempx&&tempy)&&(tempx+tempy)){
        if(tempx!=0){
            int sign=tempx>0?1:-1;
            for(int i=1;i<abs(tempx);i++)
                if(cb.get(startx+sign*i,starty)) return false;
        }
        else{
            int sign=tempy>0?1:-1;
            for(int i=1;i<abs(tempy);i++)
                if(cb.get(startx,starty+sign*i)) return false;
        }
        return true;
    }
    return false;
}
