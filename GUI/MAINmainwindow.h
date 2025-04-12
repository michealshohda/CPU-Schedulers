#ifndef MAINMAINWINDOW_H  // Fixed typo in header guard (was MAINMAINWINDOW_H)
#define MAINMAINWINDOW_H

#include <QMainWindow>
#include "cpuscheduleros.h"

// Forward declaration of UI namespace
namespace Ui {
class MAINmainwindow;  // Changed from MainWindow to MAINmainwindow
}

class MAINmainwindow : public QMainWindow  // Changed class name
{
    Q_OBJECT

public:
    explicit MAINmainwindow(QWidget *parent = nullptr);  // Updated constructor
    ~MAINmainwindow();  // Updated destructor

private slots:
    void on_finish_clicked();
    void on_Next_clicked();

private:
    Ui::MAINmainwindow *ui;    // Pointer to UI class (must match .ui file)
    CPUSchedulerOS *cpuscheduler;
    void updateStatusBar(const QString &algorithm);
};

#endif // MAINMAINWINDOW_H
