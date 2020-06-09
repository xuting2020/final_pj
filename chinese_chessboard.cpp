//
// Created by xuting on 2020/6/7.
//

#include <iostream>
#include <QPainter>
#include <QPixmap>
#include <QPen>
#include <QDebug>
#include <QPushButton>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QtMultimedia/QMediaPlayer>
#include <QTextCodec>
#include "chinese_chessboard.h"
#include "chess_piece.h"



Chinese_chessboard::Chinese_chessboard(QWidget *parent) :
        QMainWindow(parent)
{
    iniUI();
    iniSignalSlots();
    setWindowTitle("中国象棋");
    this->setFixedSize(size*10+300,size*10+100);

    //初始化32颗棋子
    for(int i=0; i<32; i++) {
        pieces[i].init_piece(i);
    }
}


void Chinese_chessboard::iniUI()
{
    music_state = true;
    regret_cnt =0;
    size = 60;//棋盘格子的宽度与高度
    selectID = -1;//是否被选中
    red_turn = false;//默认黑方先行

    cn_AI = new QWidget();
    btn_music = new QPushButton(tr("音乐"));
    btn_regret = new QPushButton(tr("悔棋"));
    btn_save_game = new QPushButton(tr("保存"));
    btn_new_game = new QPushButton(tr("重来"));
    btn_exit = new QPushButton(tr("exit"));

    auto *vlayout = new QVBoxLayout;
    auto *bottom_menu_layout = new QHBoxLayout;
    btn_music->setFixedSize(80,40);
    btn_regret->setFixedSize(80,40);
    btn_save_game->setFixedSize(80,40);
    btn_new_game->setFixedSize(80,40);
    btn_exit->setFixedSize(80,40);

    bottom_menu_layout->addWidget(btn_music);
    bottom_menu_layout->addWidget(btn_regret);
    bottom_menu_layout->addWidget(btn_save_game);
    bottom_menu_layout->addWidget(btn_new_game);
    bottom_menu_layout->addWidget(btn_exit);
    auto* hspacer = new QSpacerItem(300, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);
    bottom_menu_layout->addItem(hspacer);
    auto* vspacer = new QSpacerItem(120, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
    vlayout->addItem(vspacer);
    vlayout->addLayout(bottom_menu_layout);
    cn_AI->setLayout(vlayout);
    setCentralWidget(cn_AI);


    //player = new QMediaPlayer;

}

void Chinese_chessboard::iniSignalSlots()
{
    connect(btn_music,SIGNAL(clicked()),this,SLOT(on_btn_music()));
    connect(btn_regret,SIGNAL(clicked()),this,SLOT(on_btn_regret()));
    connect(btn_save_game,SIGNAL(clicked()),this,SLOT(on_btn_save_game()));
    connect(btn_new_game,SIGNAL(clicked()),this,SLOT(on_btn_new_game()));
    connect(btn_exit,SIGNAL(clicked()),this,SLOT(close()));

}

void Chinese_chessboard::on_btn_music()
{
    if(music_state){
        music_state = false;
//        player->setMedia(QUrl::fromLocalFile("\\absolute path of musisc MIX.mp3"));
//        player->setVolume(30);
//        player->play();
    }
    else{
      music_state = true;
//      player->pause();
    }
}

void Chinese_chessboard::on_btn_regret()
{
    if(regret_cnt>6){
        std::cout<<"已经达到最大悔棋次数"<<std::endl;
    }
    else{
        regret_cnt += 1;
    }
}

void Chinese_chessboard::on_btn_save_game()
{

}

void Chinese_chessboard::on_btn_new_game()
{

}


void Chinese_chessboard::paintEvent(QPaintEvent *)
{
    std::cout<<"paint event"<<std::endl;
	QPixmap *pixmap = new QPixmap( "/home/xuting/CLionProjects/final_pj/cn_chessboard-bgd.png");

    QPainter p;
    p.begin(this);
    //画出背景图
    p.drawPixmap(0,0,width(),height(),*pixmap);
    //设置坐标系
//    p.translate(currentCoordinates);

    QPen pen;
    pen.setWidth(10);
    pen.setColor(Qt::gray);
    p.setPen(pen);

    p.drawPoint(size-5,size-5);
    p.drawPoint(size*9+5,size-5);
    p.drawPoint(size-5,size*10+5);
    p.drawPoint(size*9+5,size*10+5);
    //设置画笔颜色和宽度
    QPen background=p.pen();
    background.setColor(Qt::black);
    background.setWidth(2);
    p.setPen(background);
    //qDebug() << size << endl;
    //画棋盘的外轮廓线
    p.drawLine(size-5,size-5,size*9+5,size-5);
    p.drawLine(size-5,size-5,size-5,size*10+5);
    p.drawLine(size-5,size*10+5,size*9+5,size*10+5);
    p.drawLine(size*9+5,size-5,size*9+5,size*10+5);
    background.setWidth(1);
    p.setPen(background);
    short n=1;
    //画棋盘的18条垂直线
    for(;n<10;n++)
    {
        p.drawLine(size*n,size,size*n,size*5);// 每个格子高size
        p.drawLine(size*n,size*6,size*n,size*10);//Vertical
    }
    //画楚河汉界的两条短垂直线
    p.drawLine(size,size*5,size,size*6);//楚河汉界也是高size
    p.drawLine(size*9,size*5,size*9,size*6);
    //画棋盘的10条水平线
    for(n=1;n<=10;n++)
        p.drawLine(size,size*n,size*9,size*n);//Horizon 每个格子宽size
    //画棋盘“士”行走的斜线
    p.drawLine(size*4,size,size*6,size*3);              //斜线轨迹
    p.drawLine(size*6,size,size*4,size*3);
    p.drawLine(size*4,size*8,size*6,size*10);
    p.drawLine(size*6,size*8,size*4,size*10);
    //画楚河汉界
    QPointF point(size*2.6, size*5.7);
    p.setFont(QFont("Arial", 30));
    p.drawText(point, "楚河            汉界");

    //画出棋子
    for(int i=0; i<32; i++) {
        drawPieces(p, i);
    }
    //画图结束
    p.end();
}

void Chinese_chessboard::drawPieces(QPainter &p, int id)
{
    //棋子已死，就不绘制
    if(pieces[id].is_dead) {
        return;
    }
    int r = size/2;   //棋子半径
    //获取棋子中心点的像素坐标，根据中心点坐标绘制棋子
    QPoint c = center(pieces[id].row, pieces[id].col);
    //根据棋子中心点的像素坐标，计算出棋子上面的文字所在的矩形
    QRect rect = QRect(c.x()-r, c.y()-r, size, size);
    //红方棋子设置文字为红色
    if(pieces[id].is_red) {
        p.setPen(Qt::red);
    } else {
        p.setPen(Qt::black);
    }
    //设置棋子背景颜色为黄色，被鼠标选中的设为绿色
    if(selectID == id) {
        p.setBrush(QBrush(Qt::green));
    } else {
        p.setBrush(QBrush(Qt::darkYellow));
    }
    //绘制棋子为圆形
    p.drawEllipse(c, r, r);
    //绘制棋子文字
    p.drawText(rect, pieces[id].piece_name(),QTextOption(Qt::AlignCenter));
}

QPoint Chinese_chessboard::center(int row, int col)
{
    QPoint origin = QPoint(size,size);
    return QPoint(origin.x()+size*col, origin.y()+size*row);
}

void Chinese_chessboard::mousePressEvent(QMouseEvent *event)
{
    auto coord = event->pos();
    std::cout<<coord.x()<<" "<<coord.y()<<std::endl;
    auto round_coord = getRoundCoord(coord);
    bool is_valid = isValidCoord(round_coord);
    if(is_valid){
        std::cout<<"valid, x: "<<round_coord.x()<<" y: "<<round_coord.y()<<std::endl;
    } else
        std::cout<<"invalid, x: "<<round_coord.x()<<" y: "<<round_coord.y()<<std::endl;
    if(event->button()==Qt::LeftButton)
    {
        this->repaint();
    }
}

QPoint Chinese_chessboard::getRoundCoord(QPoint p)
{
    int x = std::round(p.x()/60.0)*60;
    int y = std::round(p.y()/60.0)*60;
    float dx = p.x() - x;
    float dy = p.y() - y;
    float dist = std::hypot(dx, dy);
    if(dist<16.0)
        return QPoint(x,y);
    else
        return QPoint(-1,-1);
}

bool Chinese_chessboard::isValidCoord(QPoint p)
{
    if(p.x()==-1 || p.y()==-1)
        return false;
    if(p.x()<60 || p.x()>540 || p.y()<60 || p.y()>600 )
        return false;
    return true;
}

void Chinese_chessboard::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        currentCoordinates = currentCoordinates - lastCoordinates + event->pos();
        lastCoordinates = event->pos();
        event->accept();
        this->update();
    }
}










