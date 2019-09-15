/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action17863110617_qq_com;
    QWidget *centralWidget;
    QFrame *frame;
    QPushButton *Vel;
    QPushButton *angle;
    QPushButton *yaw_rate;
    QPushButton *OpenFile;
    QPushButton *cursor;
    QSlider *xAxis_zoom;
    QSlider *yAxis_zoom;
    QLabel *label;
    QLabel *label_2;
    QRadioButton *showMovie;
    QRadioButton *Analyse;
    QSlider *move_speed;
    QLabel *label_3;
    QRadioButton *Normal;
    QFrame *frame_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menu_2;
    QMenu *menu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1775, 976);
        action17863110617_qq_com = new QAction(MainWindow);
        action17863110617_qq_com->setObjectName(QStringLiteral("action17863110617_qq_com"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(1420, 20, 171, 811));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        Vel = new QPushButton(frame);
        Vel->setObjectName(QStringLiteral("Vel"));
        Vel->setGeometry(QRect(30, 380, 181, 41));
        angle = new QPushButton(frame);
        angle->setObjectName(QStringLiteral("angle"));
        angle->setGeometry(QRect(30, 440, 181, 41));
        yaw_rate = new QPushButton(frame);
        yaw_rate->setObjectName(QStringLiteral("yaw_rate"));
        yaw_rate->setGeometry(QRect(30, 500, 181, 41));
        OpenFile = new QPushButton(frame);
        OpenFile->setObjectName(QStringLiteral("OpenFile"));
        OpenFile->setGeometry(QRect(30, 20, 181, 41));
        cursor = new QPushButton(frame);
        cursor->setObjectName(QStringLiteral("cursor"));
        cursor->setGeometry(QRect(30, 80, 181, 41));
        xAxis_zoom = new QSlider(frame);
        xAxis_zoom->setObjectName(QStringLiteral("xAxis_zoom"));
        xAxis_zoom->setGeometry(QRect(50, 185, 18, 160));
        xAxis_zoom->setOrientation(Qt::Vertical);
        yAxis_zoom = new QSlider(frame);
        yAxis_zoom->setObjectName(QStringLiteral("yAxis_zoom"));
        yAxis_zoom->setGeometry(QRect(170, 185, 18, 160));
        yAxis_zoom->setOrientation(Qt::Vertical);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 150, 91, 21));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(140, 150, 91, 21));
        showMovie = new QRadioButton(frame);
        showMovie->setObjectName(QStringLiteral("showMovie"));
        showMovie->setGeometry(QRect(30, 710, 181, 51));
        Analyse = new QRadioButton(frame);
        Analyse->setObjectName(QStringLiteral("Analyse"));
        Analyse->setGeometry(QRect(30, 640, 181, 51));
        move_speed = new QSlider(frame);
        move_speed->setObjectName(QStringLiteral("move_speed"));
        move_speed->setGeometry(QRect(30, 815, 181, 18));
        move_speed->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 780, 111, 21));
        Normal = new QRadioButton(frame);
        Normal->setObjectName(QStringLiteral("Normal"));
        Normal->setGeometry(QRect(30, 570, 181, 51));
        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(40, 20, 1401, 821));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1775, 25));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(action17863110617_qq_com);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        action17863110617_qq_com->setText(QApplication::translate("MainWindow", "17863110617@qq.com", Q_NULLPTR));
        Vel->setText(QApplication::translate("MainWindow", "Vel", Q_NULLPTR));
        angle->setText(QApplication::translate("MainWindow", "angle", Q_NULLPTR));
        yaw_rate->setText(QApplication::translate("MainWindow", "yaw_rate", Q_NULLPTR));
        OpenFile->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", Q_NULLPTR));
        cursor->setText(QApplication::translate("MainWindow", "\345\205\211\346\240\207\346\215\225\346\215\211", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Zoom X", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Zoom Y", Q_NULLPTR));
        showMovie->setText(QApplication::translate("MainWindow", "     \345\274\200\345\220\257\345\212\250\347\224\273", Q_NULLPTR));
        Analyse->setText(QApplication::translate("MainWindow", "      Analyse", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Move Speed", Q_NULLPTR));
        Normal->setText(QApplication::translate("MainWindow", "      Normal", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("MainWindow", "\345\205\263\344\272\216", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
