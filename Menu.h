//
// Created by xuting on 2020/6/7.
//

#ifndef FINAL_PJ_MENU_H
#define FINAL_PJ_MENU_H

#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QMainWindow>

enum ChessType
{
    CNCHess = 0,
    Chess = 1
};

enum Pattern
{
    AI = 0,
    Person = 1
};

enum Level
{
    Easy = 0,
    Normal = 1,
    Hard = 2
};

class Menu : public QMainWindow
{
    Q_OBJECT

private:
    QWidget *type_menu;
    QPushButton *btn_CN_chess;
    QPushButton *btn_chess;
    QPushButton *btn_exit;

    QWidget *pattern_menu;
    QPushButton *btn_AI;
    QPushButton *btn_person;
    QPushButton *btn_last_game;
    QPushButton *btn_back_to_type;

    QWidget *level_menu;
    QPushButton *btn_easy;
    QPushButton *btn_normal;
    QPushButton *btn_hard;
    QPushButton *btn_back_to_patt;

    ChessType m_type;
    Pattern m_pattern;
    Level m_level;


private:
    void iniUI();//UI 创建与初始化
    void iniSignalSlots();//初始化信号与槽的链接
    void initTypeMenu();
    void initPatternMenu();
    void initLevelMenu();


private slots:
    void on_btn_CN_chess();
    void on_btn_chess();
    void on_btn_exit();

    void on_btn_AI();
    void on_btn_person();
    void on_btn_last_game();
    void on_btn_back_to_type();

    void on_btn_easy();
    void on_btn_normal();
    void on_btn_hard();
    void on_btn_back_to_patt();

    void reshow();

signals:
    void sendSignal();

public:
    explicit Menu(QWidget *parent = 0);

};


#endif //FINAL_PJ_MENU_H
