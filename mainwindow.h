#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "StartWidget.h"
#include "SelectWidget.h"
#include "AdjInWidget.h"
#include "VisualizeWidget.h"
#include <QStackedWidget>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QLabel>
#include <QWidget>
#include <QMenuBar>
#include <QVector>
#include <QTimer>
#include <QScrollArea>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QStackedWidget* stackedWidget;
    StartWidget* startwidget;
    SelectWidget* selectwidget;
    AdjInWidget* adjwidget;
    VisualizeWidget* viswidget;
    QWidget* startingWidget;
    QLabel* startingLabel;
    //creating a menubar
    QMenuBar* menuBar;
    QMenu *help_menu;
    QAction *about_us;
public slots:
    void MainWindow::aboutUsMessageBox();
private slots:
    void onEnterAdjMatPressed();
public:
    MainWindow();
    ~MainWindow();
};

#endif // MAINWINDOW_H
