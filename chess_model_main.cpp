//
// Created by xuting on 2020/6/10.
//
#include <QtWidgets/QApplication>
#include "chinese_chess_model.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChineseChessModel Model1;
    Model1.play();
    return a.exec();
}