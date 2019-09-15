#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <qcustomplot.h>

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void myMoveEvent(QMouseEvent *event);

    const QString *FILE_PATH = NULL;

    int paint_Flag = 0;
    int timer_count = 0;
    QCustomPlot *customPlot;
    QCPCurve *tar_Vel;
    QCPCurve *actual_Vel;
    QCPCurve *tar_Angle;
    QCPCurve *actual_Angle;
    QCPCurve *yaw_rate;
    QTimer * Timer;

    int x_scale = 0;
    int y_scale = 0;
    int move_scale = 49;
    int current_x1 = 0;
    int current_x2 = 0;

private:
    Ui::MainWindow *ui;

private slots:
    void on_Vel_clicked();
    void on_angle_clicked();
    void on_yaw_rate_clicked();
    void on_showMovie_clicked();
    void on_OpenFile_clicked();
    void on_xAxis_zoom_valueChanged(int value);
    void on_yAxis_zoom_valueChanged(int value);
    void on_move_speed_valueChanged(int value);
    void on_Analyse_clicked();
    void on_cursor_clicked();
};

class Hrt_Data
{
public:
    Hrt_Data(){};
    ~Hrt_Data(){};

    int rowCount = 0;

    QVector<float> target_vel;
    QVector<float> actual_vel;
    QVector<float> target_angle;
    QVector<float> actual_angle;
    QVector<float> yaw_rate;
    QVector<int> hour;
    QVector<int> minute;
    QVector<int> second;

};


#endif // MAINWINDOW_H
