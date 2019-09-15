/*
 * HRT SD card Decoder
 * Author:Qi
 * Created date:2019-08-27
 * Project:decoder the data in dataloger and show it in chart and analyze
 * */

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.setWindowTitle("HRT_D SDcard decoder");
    w.setGeometry(10,40,1650,970);

    //w.setWindowIcon(QIcon("./image/logo.png"));

    w.setStyleSheet("background-color:rgb(60,60,60);font-size:15px;color:white");
//    w.setStyleSheet("QMenuBar{background-color:rgb(111,111,1);spacing:10;}""QMenu{background-color:rgb(111,111,1);}""QMenu::item{background-color:green;}");

    w.show();

    return a.exec();
}
