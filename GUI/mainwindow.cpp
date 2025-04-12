#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QPen>
#include <QTimer>
#include <QMessageBox>
#include <QDebug>
#include"CPUSimulator.hpp"
#include"cpuscheduleros.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     setFixedSize(1000, 600);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);  // <-- attach your scene to the view
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    //ui->graphicsView->setMinimumSize(800, 600);

    //scene->setSceneRect(0, 0, 2000, 1000);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clearGraph(){
    for (QGraphicsItem *item : scene->items()) {
        if (!item->data(0).toBool()) { // Keep items where data(0) == true
            scene->removeItem(item);
            delete item;
        }
    }

}

void MainWindow::drawProcessBlock(int row, int startTime, int colorID, double processWidth) {

    int rowHeight = 40;
    int startY = 200;
    int leftMargin = 100;

    // Map color ID to color
        QColor color;
        switch (colorID % 20) {
        case 0:  color = Qt::red; break;
        case 1:  color = Qt::green; break;
        case 2:  color = Qt::blue; break;
        case 3:  color = Qt::yellow; break;
        case 4:  color = Qt::cyan; break;
        case 5:  color = Qt::magenta; break;
        case 6:  color = Qt::gray; break;
        case 7:  color = Qt::darkRed; break;
        case 8:  color = Qt::darkGreen; break;
        case 9:  color = Qt::darkBlue; break;
        case 10: color = Qt::darkYellow; break;
        case 11: color = Qt::darkCyan; break;
        case 12: color = Qt::darkMagenta; break;
        case 13: color = Qt::darkGray; break;
        case 14: color = Qt::lightGray; break;
        case 15: color = QColor("#FFA07A"); break; // LightSalmon
        case 16: color = QColor("#20B2AA"); break; // LightSeaGreen
        case 17: color = QColor("#9370DB"); break; // MediumPurple
        case 18: color = QColor("#FF69B4"); break; // HotPink
        case 19: color = QColor("#87CEFA"); break; // LightSkyBlue
        default: color = Qt::black; break;
        }



    // Calculate position
    int x = leftMargin + startTime * scaleFactor;
    int y = startY + row * rowHeight;

    int width = processWidth * scaleFactor;
    int height = rowHeight;

    // Draw rectangle
    scene->addRect(x, y, width, height, QPen(Qt::white), QBrush(color));
}

int label_X = 150;
void MainWindow::drawLabels(int pid ){

    // Map color ID to color
    QColor color;
    switch (pid % 20) {
    case 0:  color = Qt::red; break;
    case 1:  color = Qt::green; break;
    case 2:  color = Qt::blue; break;
    case 3:  color = Qt::yellow; break;
    case 4:  color = Qt::cyan; break;
    case 5:  color = Qt::magenta; break;
    case 6:  color = Qt::gray; break;
    case 7:  color = Qt::darkRed; break;
    case 8:  color = Qt::darkGreen; break;
    case 9:  color = Qt::darkBlue; break;
    case 10: color = Qt::darkYellow; break;
    case 11: color = Qt::darkCyan; break;
    case 12: color = Qt::darkMagenta; break;
    case 13: color = Qt::darkGray; break;
    case 14: color = Qt::lightGray; break;
    case 15: color = QColor("#FFA07A"); break; // LightSalmon
    case 16: color = QColor("#20B2AA"); break; // LightSeaGreen
    case 17: color = QColor("#9370DB"); break; // MediumPurple
    case 18: color = QColor("#FF69B4"); break; // HotPink
    case 19: color = QColor("#87CEFA"); break; // LightSkyBlue
    default: color = Qt::black; break;
    }

    int width = 20 ;
    QGraphicsRectItem* importantItem = scene->addRect(label_X, 300, width, width, QPen(Qt::white), QBrush(color));
    importantItem->setData(0, true); // This will be kept
    label_X+= 30;


}




void  MainWindow::drawGraphOutlines(int burstTime ){

    int viewWidth = ui->graphicsView->viewport()->width();
    int leftMargin = 100;  //aseb msafa ad eh abl ma arsm
    scaleFactor = (viewWidth - leftMargin - 20) / static_cast<double>(burstTime);
    int numRows = 1;
    int rowHeight = 40;
    int startY = 200;

    for (int i = 0; i <= numRows; ++i) {
        int y = startY + i * rowHeight;
        scene->addLine(leftMargin, y, leftMargin + burstTime * scaleFactor, y, QPen(Qt::white));
    }

    for (int t = 0; t <= burstTime; ++t) {
        int x = leftMargin + t * scaleFactor;
        scene->addLine(x, startY, x, startY + numRows * rowHeight, QPen(Qt::white));

        QGraphicsTextItem *text = scene->addText(QString::number(t) );
        text->setPos(x - 10, startY+40);
    }

    scene->addLine(leftMargin, startY, leftMargin, startY + numRows * rowHeight, QPen(Qt::white));
    scene->addLine(leftMargin, startY + numRows * rowHeight,
                   leftMargin + totalBurstTime * scaleFactor, startY + numRows * rowHeight, QPen(Qt::white));



}



void MainWindow::on_pushButton_clicked()
{
    scaleFactor = 60;
    int totalBurstTime = sim->getInitialTotalBurstTime();  // total burst time

    qDebug()<<"in main"<<totalBurstTime;
    int viewWidth = ui->graphicsView->viewport()->width();
    int leftMargin = 100;  //aseb msafa ad eh abl ma arsm
    scaleFactor = (viewWidth - leftMargin - 20) / static_cast<double>(totalBurstTime);
    int numRows = 1;
    int rowHeight = 40;
    int startY = 200;

    for (int i = 0; i <= numRows; ++i) {
        int y = startY + i * rowHeight;
        scene->addLine(leftMargin, y, leftMargin + totalBurstTime * scaleFactor, y, QPen(Qt::gray));
    }

    for (int t = 0; t <= totalBurstTime; ++t) {
        int x = leftMargin + t * scaleFactor;
        scene->addLine(x, startY, x, startY + numRows * rowHeight, QPen(Qt::lightGray));

        QGraphicsTextItem *text = scene->addText(QString::number(t) + "s");
        text->setPos(x - 10, startY - 30);
    }

    scene->addLine(leftMargin, startY, leftMargin, startY + numRows * rowHeight, QPen(Qt::black));
    scene->addLine(leftMargin, startY + numRows * rowHeight,
                   leftMargin + totalBurstTime * scaleFactor, startY + numRows * rowHeight, QPen(Qt::black));

    // shelha b3den jusst for test
    drawProcessBlock(0,0,0,1);
}


void MainWindow::on_newProccesButton_clicked()
{



    clearGraph();

    totalBurstTime += ui->newProcessspinBox->value() ;
    qDebug() <<  totalBurstTime ;
    drawGraphOutlines(totalBurstTime) ;


    //to be romved --- just building

    drawProcessBlock(0,0,0,1);
    drawProcessBlock(0,1,0,1);

    drawLabels(0 );

    /*
     * --na2s :
     * h3ml history lel last drawed rectangels to re-draw them
     * tzbeet el UI/Ux ()
     *          -in adding new process , add piority section if sechdular is piority sechdeular
     *          -add
     * time :
     *      - draw process
     *      - stauts bar (table)
     *
      */

    /*
     * @m7tag ehh mn el back-end:
     * intial total burst time
     * main function to send :
     *                         pid that allocat the CPU this sec (i smapped to a color)
     *
     *
     * backend need to handel :: when add new proccess , i want to give it a pid


    */

}



