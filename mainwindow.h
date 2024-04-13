#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "StartWidget.h"
#include "SelectWidget.h"
#include "AdjInWidget.h"
#include "IncInWidget.h"
#include "FunInWidget.h"
#include "VisualizeWidget.h"
#include <QStackedWidget>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QLabel>
#include <QWidget>
#include <QMenuBar>
#include <QVector>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QStackedWidget* stackedWidget;
    StartWidget* startwidget;
    SelectWidget* selectwidget;
    AdjInWidget* adjwidget;
    IncInWidget* incwidget;
    FunInWidget* funwidget;
    VisualizeWidget* viswidget;
    //creating a menubar
    QMenuBar* menuBar;
    QMenu *mode_menu;
    QMenu *help_menu;
    QAction *light;
    QAction *dark;
    QAction *about_us;
private slots:
    void onEnterAdjMatPressed();
public:
    MainWindow();
    ~MainWindow();
};

#endif // MAINWINDOW_H
