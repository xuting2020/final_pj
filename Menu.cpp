//
// Created by xuting on 2020/6/7.
//

#include "Menu.h"

#include "pattern_select.h"
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>

#include <iostream>

void Menu::iniUI()
{
    initTypeMenu();
    initPatternMenu();
    initLevelMenu();
    this->setCentralWidget(type_menu);
}

void Menu::initTypeMenu()
{
    //创建 中国象棋, 国际象棋, 退出三个QPushButton，并垂直布局
    type_menu = new QWidget();
    btn_CN_chess = new QPushButton(tr("中国象棋"));
    btn_chess = new QPushButton(tr("国际象棋"));
    btn_exit = new QPushButton(tr("退出"));

    QGridLayout *type_layout = new QGridLayout;
    btn_CN_chess->setFixedSize(180,75);
    btn_chess->setFixedSize(180,75);
    btn_exit->setFixedSize(180,75);

    btn_CN_chess->setStyleSheet("font-size: 30px;color:white;");
    btn_chess->setStyleSheet("font-size: 30px;color:white;");
    btn_exit->setStyleSheet("font-size: 30px;color:white;");

    QSpacerItem* vspacer = new QSpacerItem(120, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
    type_layout->addItem(vspacer, 0, 2);
    type_layout->addWidget(btn_CN_chess,1,2);//这个是坐标
    type_layout->addWidget(btn_chess,2,2);
    type_layout->addWidget(btn_exit,3,2);
    type_layout->addItem(vspacer, 4, 2);
    type_menu->setLayout(type_layout);
}

void Menu::initPatternMenu()
{
    pattern_menu = new QWidget();
    btn_AI = new QPushButton(tr("人机对战"));
    btn_person = new QPushButton(tr("本地对战"));
    btn_last_game = new QPushButton(tr("打开残局"));
    btn_back_to_type = new QPushButton(tr("返回"));

    QGridLayout *pattern_layout = new QGridLayout;
    btn_AI->setFixedSize(180,75);
    btn_person->setFixedSize(180,75);
    btn_last_game->setFixedSize(180,75);
    btn_back_to_type->setFixedSize(180,75);

    btn_AI->setStyleSheet("font-size: 30px;color:white;");
    btn_person->setStyleSheet("font-size: 30px;color:white;");
    btn_last_game->setStyleSheet("font-size: 30px;color:white;");
    btn_back_to_type->setStyleSheet("font-size: 30px;color:white;");

    QSpacerItem* vspacer = new QSpacerItem(120, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
    pattern_layout->addItem(vspacer, 0, 2);
    pattern_layout->addWidget(btn_AI,1,2);//这个是坐标
    pattern_layout->addWidget(btn_person,2,2);
    pattern_layout->addWidget(btn_last_game,3,2);
    pattern_layout->addWidget(btn_back_to_type,4,2);
    pattern_layout->addItem(vspacer, 5, 2);

    pattern_menu->setLayout(pattern_layout);
}

void Menu::initLevelMenu()
{
    level_menu = new QWidget();
    btn_easy = new QPushButton(tr("新手"));
    btn_normal = new QPushButton(tr("中级"));
    btn_hard = new QPushButton(tr("高级"));
    btn_back_to_patt = new QPushButton(tr("返回"));

    QGridLayout *level_layout = new QGridLayout;
    btn_easy->setFixedSize(180,75);
    btn_normal->setFixedSize(180,75);
    btn_hard->setFixedSize(180,75);
    btn_back_to_patt->setFixedSize(180,75);

    btn_easy->setStyleSheet("font-size: 30px;color:white;");
    btn_normal->setStyleSheet("font-size: 30px;color:white;");
    btn_hard->setStyleSheet("font-size: 30px;color:white;");
    btn_back_to_patt->setStyleSheet("font-size: 30px;color:white;");

    QSpacerItem* vspacer = new QSpacerItem(120, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
    level_layout->addItem(vspacer, 0, 2);
    level_layout->addWidget(btn_easy,1,2);//这个是坐标
    level_layout->addWidget(btn_normal,2,2);
    level_layout->addWidget(btn_hard,3,2);
    level_layout->addWidget(btn_back_to_patt,4,2);
    level_layout->addItem(vspacer, 5, 2);
    level_menu->setLayout(level_layout);

}

void Menu::iniSignalSlots()
{
    connect(btn_CN_chess,SIGNAL(clicked()),this,SLOT(on_btn_CN_chess()));
    connect(btn_chess,SIGNAL(clicked()),this,SLOT(on_btn_chess()));
    connect(btn_exit,SIGNAL(clicked()),this,SLOT(close()));

    connect(btn_AI,SIGNAL(clicked()),this,SLOT(on_btn_AI()));
    connect(btn_person,SIGNAL(clicked()),this,SLOT(on_btn_person()));
    connect(btn_last_game,SIGNAL(clicked()),this,SLOT(on_btn_last_game()));
    connect(btn_back_to_type,SIGNAL(clicked()),this,SLOT(on_btn_back_to_type()));

    connect(btn_easy,SIGNAL(clicked()),this,SLOT(on_btn_easy()));
    connect(btn_normal,SIGNAL(clicked()),this,SLOT(on_btn_normal()));
    connect(btn_hard,SIGNAL(clicked()),this,SLOT(on_btn_hard()));
    connect(btn_back_to_patt,SIGNAL(clicked()),this,SLOT(on_btn_back_to_patt()));
}

void Menu::on_btn_CN_chess()
{
    m_type = ChessType::CNCHess;

    type_menu = this->centralWidget();
    type_menu->setParent(0);
    type_menu->hide();
    this->setCentralWidget(pattern_menu);
    pattern_menu->show();
}

void Menu::on_btn_chess()
{
    m_type = ChessType ::Chess;

    type_menu = this->centralWidget();
    type_menu->setParent(0);
    type_menu->hide();
    this->setCentralWidget(pattern_menu);
    pattern_menu->show();
}

void Menu::on_btn_exit()
{

}

void Menu::on_btn_AI()
{
    m_pattern = Pattern ::AI;

    pattern_menu = this->centralWidget();
    pattern_menu->setParent(0);
    pattern_menu->hide();
    this->setCentralWidget(level_menu);
    level_menu->show();
}

void Menu::on_btn_person()
{
    m_pattern = Pattern ::Person;

    pattern_menu = this->centralWidget();
    pattern_menu->setParent(0);
    pattern_menu->hide();
    this->setCentralWidget(level_menu);
    level_menu->show();
}

void Menu::on_btn_last_game()
{

}

void Menu::on_btn_back_to_type()
{
    pattern_menu = this->centralWidget();
    pattern_menu->setParent(0);
    pattern_menu->hide();
    this->setCentralWidget(type_menu);
    type_menu->show();
}

void Menu::on_btn_easy()
{
    m_level = Level::Easy;
    this->hide();//主界面关闭
    patt_sel *w = new patt_sel(this) ;//将类指针实例化
    connect(w,SIGNAL(sendsignal()),this,SLOT(reshow()));//当点击子界面时，调用主界面的reshow()函数
    w->show();
}

void Menu::on_btn_normal()
{
    m_level = Level::Normal;
    this->hide();//主界面关闭
    patt_sel *w = new patt_sel(this) ;//将类指针实例化
    connect(w,SIGNAL(sendsignal()),this,SLOT(reshow()));//当点击子界面时，调用主界面的reshow()函数
    w->show();
}

void Menu::on_btn_hard()
{
    m_level = Level::Hard;
    this->hide();//主界面关闭
    patt_sel *w = new patt_sel(this) ;//将类指针实例化
    connect(w,SIGNAL(sendsignal()),this,SLOT(reshow()));//当点击子界面时，调用主界面的reshow()函数
    w->show();
}

void Menu::on_btn_back_to_patt()
{
    level_menu = this->centralWidget();
    level_menu->setParent(0);
    level_menu->hide();
    this->setCentralWidget(pattern_menu);
    pattern_menu->show();
}

void Menu::reshow()
{
    this->show();
}

Menu::Menu (QWidget *parent)
        : QMainWindow(parent)
{
    iniUI();//界面创建与布局
    iniSignalSlots();//信号与槽的关联
    setWindowTitle("菜单");//设置窗体标题
    resize(800,600);//设置窗口大小
    //设置窗口背景（使用图片）
    this->setStyleSheet("border-image: url(/home/xuting/CLionProjects/final_pj/login.png)");

}