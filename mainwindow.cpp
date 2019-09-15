/*
 * HRT SD card Decoder
 * Author:Qi
 * Created date:2019-08-27
 * Project:decoder the data in dataloger and show it in chart and analyze
 * */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QString>
#include <QStringList>
#include <QDebug>
#include <iostream>
#include <QFrame>
#include <QMouseEvent>
#include <QFileDialog>

//数组类对象、用于存储19D各个时间点的参数
Hrt_Data *hrtRead = new Hrt_Data;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //画出图像
    customPlot = new QCustomPlot(this);
    tar_Vel = new QCPCurve(customPlot->xAxis, customPlot->yAxis);
    tar_Vel->setName("tar_Vel");
    tar_Vel->setPen(QPen(Qt::blue,1.5, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    actual_Vel = new QCPCurve(customPlot->xAxis, customPlot->yAxis);
    actual_Vel->setName("actual_Vel");
    actual_Vel->setPen(QPen(Qt::red,1.5, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    tar_Angle = new QCPCurve(customPlot->xAxis, customPlot->yAxis);
    tar_Angle->setName("tar_Angle");
    tar_Angle->setPen(QPen(Qt::darkYellow,1.5, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    actual_Angle = new QCPCurve(customPlot->xAxis, customPlot->yAxis);
    actual_Angle->setName("actual_Angle");
    actual_Angle->setPen(QPen(Qt::darkCyan,1.5, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    yaw_rate = new QCPCurve(customPlot->xAxis, customPlot->yAxis);
    yaw_rate->setName("yaw_rate");
    yaw_rate->setPen(QPen(Qt::darkGray,1.5, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    Timer = new QTimer(this);

    customPlot->setGeometry(30,55,1350,870);
    customPlot->legend->setVisible(true);
    customPlot->legend->setBrush(QColor(255,255,255,0));
    customPlot->addGraph();
    customPlot->graph(0)->setName("Cursor");
    customPlot->addGraph();
    customPlot->graph(1)->setName("Loss");

    //美化UI界面
    ui->frame->setStyleSheet("font-size:1px;color:red;border: 3px solid rgb(75,161,150);border-radius:20px");
    ui->frame->setGeometry(1405,5,235,890);
    ui->frame_2->setStyleSheet("font-size:1px;color:red;border: 10px solid white;border-radius:20px");
    ui->frame_2->setGeometry(20,5,1370,890);
    ui->OpenFile->setStyleSheet("font-size:20px;color:white;border: 3px solid blue;border-radius:15px");
    ui->cursor->setStyleSheet("font-size:20px;color:white;border: 3px solid blue;border-radius:15px");
    ui->Vel->setStyleSheet("font-size:20px;color:white;border: 3px solid rgb(75,161,150);border-radius:15px");
    ui->angle->setStyleSheet("font-size:20px;color:white;border: 3px solid rgb(75,161,150);border-radius:15px");
    ui->yaw_rate->setStyleSheet("font-size:20px;color:white;border: 3px solid rgb(75,161,150);border-radius:15px");
    ui->Normal->setStyleSheet("font-size:20px;color:white;border: 3px solid rgb(75,161,150);border-radius:20px");
    ui->Analyse->setStyleSheet("font-size:20px;color:white;border: 3px solid rgb(75,161,150);border-radius:20px");
    ui->showMovie->setStyleSheet("font-size:20px;color:white;border: 3px solid rgb(75,161,150);border-radius:20px");
    ui->xAxis_zoom->setStyleSheet("border: 0px solid rgb(75,161,150);");
    ui->label->setStyleSheet("font-size:20px;color:white;border: 0px solid rgb(75,161,150)");
    ui->yAxis_zoom->setStyleSheet("border: 0px solid rgb(75,161,150);");
    ui->label_2->setStyleSheet("font-size:20px;color:white;border: 0px solid rgb(75,161,150)");
    ui->move_speed->setStyleSheet("border: 0px solid rgb(75,161,150);");
    ui->label_3->setStyleSheet("font-size:20px;color:white;border: 0px solid rgb(75,161,150)");

    connect(customPlot,&QCustomPlot::mouseMove,this,&MainWindow::myMoveEvent);
    connect(Timer,SIGNAL(timeout()),this,SLOT(on_showMovie_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Vel_clicked()
{
    paint_Flag = 0;
    if(this->FILE_PATH != NULL)
    {
        QVector<QCPCurveData> dataTargetVel(hrtRead->rowCount),dataActualVel(hrtRead->rowCount);

        //获取实际速度数据、目标速度数据
        for (int i=0; i<hrtRead->rowCount; ++i)
        {
            dataTargetVel[i] = QCPCurveData(i, i , hrtRead->target_vel[i]);
            dataActualVel[i] = QCPCurveData(i, i , hrtRead->actual_vel[i]);
        }
        tar_Vel->data()->set(dataTargetVel,true);
        actual_Vel->data()->set(dataActualVel,true);
        tar_Angle->data()->clear();
        actual_Angle->data()->clear();
        customPlot->graph(1)->setVisible(FALSE);
        //设置图像样式
        customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
        customPlot->axisRect()->setupFullAxesBox();
        customPlot->rescaleAxes();
        customPlot->xAxis->setLabel("Time/20ms");
        customPlot->xAxis->setRange(0,(x_scale+1)*100);
        customPlot->yAxis->setLabel("Velocity m/s");

        //刷新图像
        customPlot->replot();
    }
}

void MainWindow::on_angle_clicked()
{
    paint_Flag = 1;
    if(this->FILE_PATH != NULL)
    {
        QVector<QCPCurveData> dataTargetAngle(hrtRead->rowCount),dataActualAngle(hrtRead->rowCount);

        //获取实际速度数据、目标速度数据
        for(int i=0; i<hrtRead->rowCount; ++i)
        {
            dataTargetAngle[i] = QCPCurveData(i, i , hrtRead->target_angle[i]);
            dataActualAngle[i] = QCPCurveData(i, i , hrtRead->actual_angle[i]);
        }
        tar_Angle->data()->set(dataTargetAngle,true);
        actual_Angle->data()->set(dataActualAngle,true);
        actual_Vel->data()->clear();
        tar_Vel->data()->clear();
        customPlot->graph(1)->setVisible(FALSE);


        //设置图像样式
        customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
        customPlot->axisRect()->setupFullAxesBox();
        customPlot->rescaleAxes();
        customPlot->xAxis->setLabel("Time/20ms");
        customPlot->xAxis->setRange(0,(x_scale+1)*100);
        customPlot->yAxis->setLabel("Angle /deg");

        //刷新图像
        customPlot->replot();
    }
}

void MainWindow::on_yaw_rate_clicked()
{
    paint_Flag = 2;
}

void MainWindow::on_showMovie_clicked()
{
    if(timer_count == 0){
        Timer->start(move_scale+1);
        timer_count++;
    }else if((x_scale+1)*100+timer_count<hrtRead->rowCount){
        customPlot->xAxis->setRange(0+timer_count,(x_scale+1)*100+timer_count);
        customPlot->replot();
        timer_count++;
    }else{
        Timer->stop();
        ui->Normal->setChecked(TRUE);
        timer_count = 0;
    }

}

void MainWindow::on_OpenFile_clicked()
{
    hrtRead->rowCount = 0;

    QString fileName = QFileDialog::getOpenFileName(this,tr("choose the csv doc created by Datalogger"),
                                                    "E:",tr("*"));
    this->FILE_PATH = new QString(fileName);

    //创建文件操作对象
    QFile csvFile(*FILE_PATH);
    QStringList CSVList;
    CSVList.clear();

    //读取文件
    if (csvFile.open(QIODevice::ReadWrite))
    {
        QTextStream stream(&csvFile);
        while (!stream.atEnd())
        {
            CSVList.push_back(stream.readLine());
        }

        csvFile.close();
    }

    //将数据存入数组
    int index = 0;
    QString str_temp = "";
    Q_FOREACH(QString str, CSVList)
    {
        hrtRead->rowCount++;
        for(int j = 0;j<str.length()-1;j++)
        {
            if (str[j] != ',')
            {
                str_temp.append(str[j]);
            }else
            {
                switch(index)
                {
                    case 0:
                        hrtRead->hour.append(str_temp.toFloat());
                        break;
                    case 1:
                        hrtRead->minute.append(str_temp.toFloat());
                        break;
                    case 2:
                        hrtRead->second.append(str_temp.toFloat());
                        break;
                    case 3:
                        hrtRead->target_vel.append(str_temp.toFloat());
                        break;
                    case 4:
                        hrtRead->actual_vel.append(str_temp.toFloat());
                        break;
                    case 5:
                        hrtRead->target_angle.append(str_temp.toFloat());
                        break;
                    case 6:
                        hrtRead->actual_angle.append(str_temp.toFloat());
                        break;
                    case 7:
                        hrtRead->yaw_rate.append(str_temp.toFloat());
                        break;
                }
                str_temp.clear();

                index++;
            }
        }

        index = 0;
    }
//    qDebug()<<"filename : "<<fileName;
}

void MainWindow::myMoveEvent(QMouseEvent *event)
{
    double x = event->pos().x();
    double x_ = customPlot->xAxis->pixelToCoord(x);

    //更新光标位置
    QVector<double> x_2(101), y_2(101);
    for (int i=0; i<101; ++i)
    {
        x_2[i] = x_;
        y_2[i] = customPlot->yAxis->range().lower+
                i*(customPlot->yAxis->range().upper-customPlot->yAxis->range().lower)/101;
    }
    customPlot->graph(0)->setData(x_2,y_2);
    customPlot->graph(0)->setPen(QPen(Qt::green,1.5, Qt::DashLine, Qt::RoundCap, Qt::RoundJoin));
    customPlot->replot();

    if(tar_Vel->dataCount()!=0 || tar_Angle->dataCount()!=0)
    {
        QString *str = new QString;
        switch(paint_Flag)
        {
        case 0:
            *str = QString("Time:%1\n"
                                  "actual Value:%2\n""target Value:%3\n""Loss:%4").arg(QString::number(x_,10,3))
                    .arg(QString::number(tar_Vel->data().data()->at(int(x_))->value,10,3))
                    .arg(QString::number(actual_Vel->data().data()->at(int(x_))->value,10,3))
                    .arg(QString::number(tar_Vel->data().data()->at(int(x_))->value-actual_Vel->data().data()->at(int(x_))->value,10,3));
            break;
        case 1:
            *str = QString("Time:%1\n"
                                  "actual Angle:%2\n""target Angle:%3\n""Loss:%4").arg(QString::number(x_,10,3))
                    .arg(QString::number(tar_Angle->data().data()->at(int(x_))->value,10,3))
                    .arg(QString::number(actual_Angle->data().data()->at(int(x_))->value,10,3))
                    .arg(QString::number(tar_Angle->data().data()->at(int(x_))->value-actual_Angle->data().data()->at(int(x_))->value,10,3));
            break;
        case 2:
            break;
        }

        QToolTip::showText(cursor().pos(),*str);
    }

}

void MainWindow::on_xAxis_zoom_valueChanged(int value)
{
    this->x_scale = value;
    customPlot->xAxis->setRange(0,(x_scale+1)*100);
    customPlot->replot();
}

void MainWindow::on_yAxis_zoom_valueChanged(int value)
{
    this->y_scale = value;
    customPlot->yAxis->setRange(-1,(y_scale+1)*1);
    customPlot->replot();
}

void MainWindow::on_move_speed_valueChanged(int value)
{
    Timer->stop();
    timer_count = 0;
    ui->Normal->setChecked(TRUE);
    move_scale = value*10;
}


void MainWindow::on_Analyse_clicked()
{
    //绘制差值图像
    //获取当前坐标轴范围
    current_x1 = customPlot->xAxis->range().lower;
    current_x2 = customPlot->xAxis->range().upper;
    QVector<double> x_2(current_x2-current_x1+1), y_2(current_x2-current_x1+1);
    float maxLoss = 0;
    float minLoss = 0;
    QString strmax,strmin;

    if(this->FILE_PATH != NULL)
    {
        customPlot->xAxis->setRange(current_x1,current_x2);
        switch(paint_Flag)
        {
        case 0:
            customPlot->yAxis->setLabel("Loss m/s");
            for (int i=current_x1;i<current_x2;i++)
            {
                x_2[i-current_x1] = i;
                y_2[i-current_x1] = tar_Vel->data().data()->at(int(i))->value
                        -actual_Vel->data().data()->at(int(i))->value;
                maxLoss = maxLoss>y_2[i-current_x1]?maxLoss:y_2[i-current_x1];
                minLoss = minLoss<y_2[i-current_x1]?minLoss:y_2[i-current_x1];
            }
            break;
        case 1:
            customPlot->yAxis->setLabel("Loss deg");
            for (int i=current_x1;i<current_x2;i++)
            {
                x_2[i-current_x1] = i;
                y_2[i-current_x1] = tar_Angle->data().data()->at(int(i))->value
                        -actual_Angle->data().data()->at(int(i))->value;
                maxLoss = maxLoss>y_2[i-current_x1]?maxLoss:y_2[i-current_x1];
                minLoss = minLoss<y_2[i-current_x1]?minLoss:y_2[i-current_x1];
            }
            break;
        case 2:
            customPlot->yAxis->setLabel("Loss deg/s");
            break;
        }

        //刷新图像
        tar_Angle->data()->clear();
        actual_Angle->data()->clear();
        actual_Vel->data()->clear();
        tar_Vel->data()->clear();
        customPlot->graph(1)->setVisible(TRUE);
        customPlot->graph(1)->setData(x_2,y_2);
        customPlot->graph(1)->setBrush(QBrush(QColor(75,161,150,230)));
        customPlot->replot();
    }


    strmax = QString::number(maxLoss);
    strmin = QString::number(minLoss);

    QMessageBox::information(NULL, "Analyse", "\nThe max Loss is:"+strmax+"  \nThe min Loss is:"+strmin+"  \n",
                             QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    ui->Normal->setChecked(TRUE);
}

void MainWindow::on_cursor_clicked()
{
    QMessageBox::information(NULL, "maybe future" , "Nothing Here" ,QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
}
