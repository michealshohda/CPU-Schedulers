#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Headers.hpp"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QPen>
#include "global.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT



public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void drawProcessBlock(int row, int startTime, int colorID, double processWidth);
    void drawLabels(int pid );
    void writeRemainingTime(int pid, int remainingTime);
    void setupLegendLabels();




private slots:
    void on_pushButton_clicked();
    void on_newProccesButton_clicked();


private:
    Ui::MainWindow *ui;

    QGraphicsView *view;
    QGraphicsScene *scene;
    QTimer *timer;

    double scaleFactor =40 ;
    int totalBurstTime = 0 ;


    void drawGraphOutlines(int burstTime );

    void clearGraph();
    void Re_drawRectangles() ;

};
#endif // MAINWINDOW_H
