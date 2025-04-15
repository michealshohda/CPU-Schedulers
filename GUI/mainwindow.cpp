#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QPen>
#include <QTimer>
#include <QMessageBox>
#include <QDebug>
#include <QTimer>
#include "cpuscheduleros.h"
#include "global.h"
#include <QThread>
#include<Qlist>
#include "rectangle.h"

QList<rectangle> rectanglesHistory ;
int leftMargin = 100;  //aseb msafa ad eh abl ma arsm

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
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
//function to Write labels (Processes: and RemainingTime )
void MainWindow::setupLegendLabels() {
    QGraphicsTextItem* processesLabel = scene->addText("Processes:");
    processesLabel->setDefaultTextColor(Qt::white);
    processesLabel->setFont(QFont("Arial", 10, QFont::Bold));

    processesLabel->setPos(60, 300);
    processesLabel->setData(0, true);

    QGraphicsTextItem* timeLabel = scene->addText("Remaining Time:");
    timeLabel->setDefaultTextColor(Qt::white);
    timeLabel->setFont(QFont("Arial", 10, QFont::Bold));

    timeLabel->setPos(40, 347);
    timeLabel->setData(0, true);
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

    // Draw rectangle and mark it as an important item is the sene so as not be deleted
    QGraphicsRectItem *rect = scene->addRect(x, y, width, height, QPen(Qt::white), QBrush(color));
    //rect->setData(0, true);
    rectanglesHistory.append({startTime,colorID}) ;

}


void MainWindow::Re_drawRectangles() {

    for (const rectangle& rec : rectanglesHistory) {
        drawProcessBlock(0, rec.startTime, rec.colorID, 1);
    }

}


int label_X_remaining_time = 150;
void MainWindow::writeRemainingTime(int pid, int remainingTime) {
    // Find existing label if any
    bool found = false;
    QGraphicsTextItem* existingLabel = nullptr;

    // Loop through all items in the scene to find matching text label
    foreach(QGraphicsItem* item, scene->items()) {
        QGraphicsTextItem* textItem = dynamic_cast<QGraphicsTextItem*>(item);
        if (textItem && textItem->data(1).isValid() && textItem->data(1).toInt() == pid) {
            // Found existing label for this pid
            existingLabel = textItem;
            found = true;
            break;
        }
    }

    if (found) {
        // Update existing label text
        existingLabel->setPlainText(QString::number(remainingTime));
    } else {
        // Create new label
        QString timeText = QString::number(remainingTime);
        QGraphicsTextItem* timeLabel = scene->addText(timeText);

        // Set text properties
        timeLabel->setDefaultTextColor(Qt::white);
        timeLabel->setFont(QFont("Arial", 8));

        // Find the position of the process's color square
        QGraphicsRectItem* processRect = nullptr;
        foreach(QGraphicsItem* item, scene->items()) {
            QGraphicsRectItem* rectItem = dynamic_cast<QGraphicsRectItem*>(item);
            if (rectItem && rectItem->data(2).isValid() && rectItem->data(2).toInt() == pid) {
                processRect = rectItem;
                break;
            }
        }

        if (processRect) {
            // Position the time label under the process label (which is under the square)
            // Get the position of the rectangle
            qreal rectX = processRect->rect().x();
            qreal rectWidth = processRect->rect().width();

            // Center the text under the rectangle
            qreal textWidth = timeLabel->boundingRect().width();
            qreal textX = rectX + (rectWidth - textWidth) / 2;
            timeLabel->setPos(textX, 300 + 20 + 12); // Square height (20) + process label height (~10) + 2px margin
        } else {
            // Fallback positioning if process rectangle not found
            timeLabel->setPos(label_X_remaining_time, 350);
            label_X_remaining_time += 30;
        }

        // Store the pid as data in the text item for future identification
        timeLabel->setData(0, true); // Mark as important (don't clear)
        timeLabel->setData(1, pid);  // Store the pid for identification
    }
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

    // Add text label below the square
    QString labelText = QString("P%1").arg(pid);
    QGraphicsTextItem* textLabel = scene->addText(labelText);

    // Set text properties
    textLabel->setDefaultTextColor(Qt::white); // White text for visibility on dark background
    textLabel->setFont(QFont("Arial", 8)); // Smaller font size

    // Position the text centered under the square
    // Calculate position to center the text under the rectangle
    qreal textWidth = textLabel->boundingRect().width();
    qreal textX = label_X + (width - textWidth) / 2;
    textLabel->setPos(textX, 300 + width + 2); // 2 pixels gap between square and text

    // Mark text as important so it won't be cleared
    textLabel->setData(0, true);
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
                   leftMargin + burstTime * scaleFactor, startY + numRows * rowHeight, QPen(Qt::white));



}


void MainWindow::on_pushButton_clicked()
{

    totalBurstTime = sim->getInitialTotalBurstTime();  // total burst time
    drawGraphOutlines(totalBurstTime);
    setupLegendLabels();



      //----make a new thread------
        QThread *thread = new QThread;

        // connect your existing GUI update slots to simulator's signals
        connect(sim, &CPUSimulator::drawProcessBlock, this, [=](int x, int y, int pid, int width){ //el variables dol seems weired
            drawProcessBlock(x, y, pid, width); // safe GUI call
        });
        connect(sim, &CPUSimulator::drawLabelsWithRemainingTime, this, [=](int pid, int remainingTime) {
            drawLabels(pid);
            writeRemainingTime(pid,remainingTime);
        });
        connect(sim, &CPUSimulator::updateRemainingTime, this, [=](int pid,int remainingTime) {
            writeRemainingTime(pid,remainingTime);
        });

        // Cleanup after done
        connect(sim, &CPUSimulator::finished, thread, &QThread::quit);
        connect(sim, &CPUSimulator::finished, sim, &CPUSimulator::deleteLater);
        connect(thread, &QThread::finished, thread, &QThread::deleteLater);


        // Move simulator to thread
        sim->moveToThread(thread);

        // Start simulation when thread starts
        connect(thread, &QThread::started, sim, &CPUSimulator::runSimulation);

        thread->start();
       //---------




    //el naaaaa2sssssss
    /* add graph lables :2ly hya kol process deh el color bt3ha eh (el function ghza bs a7otha fen ?!)
     * add check box if he wants el gantchart 3la tool with no live view:
     *                                              s3tha htb2a run.simulation() 3ady gdn bs hnshel kol sleep() mmkn n3mlha as new function
     * tournaround & waiting time show in gui


*/

}


void MainWindow::on_newProccesButton_clicked()
{
/*
// pass it's data:
                    *ana 3awz a3rf a5er PID 3lshan adeh lel gdead +1(done)
                    *ana 3awz azwd 7ta lel piority if the selected schdular is a piority
                    ** lw el procces 5elst , run.simulation ht5ls fa el thread ht2fel, ..bs hwa mmkn yadd new process.. 7d yshoflna 7l , n8yr condition el while fel run.simulation we tb2a while true ?!

// gui of adding new process and redraw(shrink) the already drawn processes(done)
*/
    clearGraph();
    totalBurstTime += ui->newProcessspinBox->value() ;
    drawGraphOutlines(totalBurstTime) ;
    int viewWidth = ui->graphicsView->viewport()->width(); //update scale Factor
    scaleFactor = (viewWidth - leftMargin - 20) / static_cast<double>(totalBurstTime);
    Re_drawRectangles();
    sim->addProcess(Process(pid_Global+1,sim->getCurrentTime(),ui->newProcessspinBox->value()));
    drawLabels(pid_Global+1);
    writeRemainingTime(pid_Global+1, ui->newProcessspinBox->value());
    pid_Global++ ;


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
     *
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










