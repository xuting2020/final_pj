//
// Created by xuting on 2020/6/7.
//

#ifndef FINAL_PJ_CHINESE_CHESSBOARD_H
#define FINAL_PJ_CHINESE_CHESSBOARD_H

#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QMainWindow>
#include <QString>
//#include <QtMultimedia/QMediaPlayer>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QPen>
#include <QDebug>

#include "chess_piece.h"


class Chinese_chessboard : public QMainWindow
{
    Q_OBJECT

private:

    QWidget *cn_AI;
    QPushButton *btn_music;
    QPushButton *btn_regret;
    QPushButton *btn_new_game;
    QPushButton *btn_save_game;
    QPushButton *btn_exit;
    //QMediaPlayer *player;

    //QWidget *cn_person;

private slots:
    void on_btn_music();
    void on_btn_regret();
    void on_btn_new_game();
    void on_btn_save_game();

public:
    //chinese_chessboard *cn_ui;
    int selectID;   //被选中的棋子
    bool red_turn;     //是否轮到红方走
    ChessPiece pieces[32]; //32颗棋子
    int regret_cnt;
    short size;
    bool music_state;

private:
    void iniUI();
    void iniSignalSlots();
    void paintEvent(QPaintEvent *);
    void drawPieces(QPainter &pt, int id);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    QPoint getRoundCoord(QPoint p);
    bool isValidCoord(QPoint p);
    int findPieceByCoord(QPoint p);
    QPoint center(int row, int col); //将棋盘行、列坐标转换成像素坐标
    QPoint currentCoordinates,lastCoordinates;//当前的坐标和上一次移动的坐标

public:
    explicit Chinese_chessboard(QWidget *parent = 0);
    void display_update();

};




#endif //FINAL_PJ_CHINESE_CHESSBOARD_H
