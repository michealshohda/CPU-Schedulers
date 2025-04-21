#include "MAINmainwindow.h"
#include "ui_MAINmainwindow.h"
#include<QMessageBox>
#include <QPixmap>
MAINmainwindow::MAINmainwindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MAINmainwindow)
{
    ui->setupUi(this);
    setBackgroundImage(this, ":/OSbackground.jpg" );
    setFixedSize(612,320);


    ui->comboBox->addItem("First Come First Serve");
    ui->comboBox->addItem("Shortest Job First");
    ui->comboBox->addItem("PRIORITY");
    ui->comboBox->addItem("Round Robin");
    // Connect combo box change signal
    connect(ui->comboBox, &QComboBox::currentTextChanged,
            this, &MAINmainwindow::updateStatusBar);
}

MAINmainwindow::~MAINmainwindow()
{
    delete ui;
}

void MAINmainwindow::setBackgroundImage(QMainWindow *window, const QString &imagePath) {
    QPixmap pixmap(imagePath);

    if (pixmap.isNull()) {
        qDebug() << "Error: Failed to load image at" << imagePath;
        return;
    }

    qDebug() << "Successfully loaded image at" << imagePath << ", size:" << pixmap.size();

    QPalette palette;
    palette.setBrush(QPalette::Window, QBrush(pixmap));  // Use QPalette::Window to set the background
    window->setPalette(palette);
}

void MAINmainwindow::updateStatusBar(const QString &algorithm)
{
    if (algorithm == "PRIORITY") {
        statusBar()->showMessage("Priority range: 1-10 | Burst time range: 1-100| Arrival time range :1-100");
    }
    else if (algorithm == "Round Robin") {
        statusBar()->showMessage("Time quantum range: 1-100 | Burst time range: 1-100|Arrival time range :1-100");
    }
    else if (algorithm == "Shortest Job First") {
        statusBar()->showMessage("Burst time range: 1-100|Arrival time range :1-100");
    }
    else { // FCFS
        statusBar()->showMessage("Burst time range: 1-100|Arrival time range :1-100");
    }
}

void MAINmainwindow::on_finish_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Thank You");
    msgBox.setText("We are privileged to utilize our application,do you really want to close the app?");
    msgBox.setIcon(QMessageBox::NoIcon);

    // Add buttons
    QPushButton *closeButton = msgBox.addButton(QMessageBox::Close);
    QPushButton *noButton = msgBox.addButton(QMessageBox::No);


    // Execute the dialog
    msgBox.exec();

    // Check which button was clicked
    if (msgBox.clickedButton() == closeButton) {
        QApplication::closeAllWindows();  // Close the app
    }
}


void MAINmainwindow::on_Next_clicked()
{
    QString nb = ui->nbprocesses->text();
    bool ok;
    int processCount = nb.toInt(&ok);  // Try to convert to integer

    if (ok && processCount > 0) {  // Check if conversion succeeded and is positive
            QString selectedAlgorithm = ui->comboBox->currentText();
            cpuscheduler = new CPUSchedulerOS(this);
            cpuscheduler->setAlgorithm(selectedAlgorithm); // Pass the selected algorithm
            cpuscheduler->setProcessCount(processCount);   // Pass the process count
            if (selectedAlgorithm == "Shortest Job First" || selectedAlgorithm == "PRIORITY") {
                cpuscheduler->showPreemptiveOption(true);
            } else {
                cpuscheduler->showPreemptiveOption(false);
            }
            cpuscheduler->show();
    } else {
        QMessageBox::warning(this, "Invalid Input",
                             "Please enter a valid positive number of processes");
        // Optional: Clear/Reset the input field
        ui->nbprocesses->clear();
        ui->nbprocesses->setFocus();
    }
}


