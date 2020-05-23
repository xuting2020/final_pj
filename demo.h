//
// Created by xuting on 2020/5/23.
//

#ifndef FINAL_PJ_UI_H
#define FINAL_PJ_DEMO_H

#include <QtWidgets/QDialog>

#include <QtWidgets/QCheckBox>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>


class QWDlgManual : public QDialog
{
Q_OBJECT

private:
    QCheckBox   *chkBoxUnder;
    QCheckBox   *chkBoxItalic;
    QCheckBox   *chkBoxBold;

    QRadioButton    *rBtnBlack;
    QRadioButton    *rBtnRed;
    QRadioButton    *rBtnBlue;

    QPlainTextEdit  *txtEdit;

    QPushButton     *btnOK;
    QPushButton     *btnCancel;
    QPushButton     *btnClose;

    void    iniUI();//UI 创建与初始化
    void    iniSignalSlots();//初始化信号与槽的链接

private slots:
    void on_chkBoxUnder(bool checked); //Underline 的clicked(bool)信号的槽函数

    void on_chkBoxItalic(bool checked);//Italic 的clicked(bool)信号的槽函数

    void on_chkBoxBold(bool checked); //Bold 的clicked(bool)信号的槽函数

    void setTextFontColor(); //设置字体颜色

public:
    QWDlgManual(QWidget *parent = 0);
    ~QWDlgManual();

};


#endif //FINAL_PJ_UI_H
