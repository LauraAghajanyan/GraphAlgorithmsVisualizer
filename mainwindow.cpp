#include "mainwindow.h"

QVector<QVector<int>> globMat;

MainWindow::MainWindow()
{
    resize(900,900);
    stackedWidget = new QStackedWidget;
    startwidget = new StartWidget;
    selectwidget = new SelectWidget;
    adjwidget = new AdjInWidget;
    incwidget = new IncInWidget;
    funwidget = new FunInWidget;
    viswidget = new VisualizeWidget;

    globMat = adjwidget->getAdjMatrix();

    //GlobalMatrix = adjwidget->getAdjMatrix();
    stackedWidget->addWidget(startwidget); // index 0
    stackedWidget->addWidget(selectwidget); // index 1
    stackedWidget->addWidget(adjwidget); // index 2
    stackedWidget->addWidget(incwidget); // index 3
    stackedWidget->addWidget(funwidget); // index 4
    stackedWidget->addWidget(viswidget); //index 5
    menuBar = new QMenuBar(this);
    mode_menu = new QMenu("Mode",this);
    light = new QAction("Light",this);
    dark = new QAction("Dark",this);
    help_menu = new QMenu("Help",this);
    about_us = new QAction("About us",this);

    mode_menu->addAction(light);
    mode_menu->addAction(dark);
    help_menu->addAction(about_us);

    menuBar->addMenu(mode_menu);
    menuBar->addMenu(help_menu);

    setMenuBar(menuBar);

    setCentralWidget(stackedWidget);

    connect(startwidget->start,&QPushButton::clicked,this,[this](){
        //delete startwidget;
        stackedWidget->setCurrentIndex(1);
    });
    
    //select widget
    connect(selectwidget->selectGoBack,&QPushButton::clicked,this,[this](){
        stackedWidget->setCurrentIndex(0);
    });
    connect(selectwidget->selectAdj,&QPushButton::clicked,this,[this](){
        stackedWidget->setCurrentIndex(2);
    });
    connect(selectwidget->selectInc,&QPushButton::clicked,this,[this](){
        stackedWidget->setCurrentIndex(3);
    });
    connect(selectwidget->selectDragAndDrop,&QPushButton::clicked,this,[this](){
        stackedWidget->setCurrentIndex(4);
    });

    //adjecent widget
    connect(adjwidget->adjGoHome,&QPushButton::clicked,this,[this](){
        stackedWidget->setCurrentIndex(0);
    });
    connect(adjwidget->adjGoSelect,&QPushButton::clicked,this,[this](){
        stackedWidget->setCurrentIndex(1);
    });

    //incidence widget
    connect(incwidget->incGoHome,&QPushButton::clicked,this,[this](){
        stackedWidget->setCurrentIndex(0);
    });
    connect(incwidget->incGoSelect,&QPushButton::clicked,this,[this](){
        stackedWidget->setCurrentIndex(1);
    });

    //fun widget
    connect(funwidget->dragDropGoHome,&QPushButton::clicked,this,[this](){
        stackedWidget->setCurrentIndex(0);
    });
    connect(funwidget->dragDropGoSelect,&QPushButton::clicked,this,[this](){
        stackedWidget->setCurrentIndex(1);
    });

    //from adjwidget go to viswidget when pressing Enter
    connect(adjwidget->enterAdjMat, &QPushButton::clicked, this, &MainWindow::onEnterAdjMatPressed);

}

void MainWindow::onEnterAdjMatPressed() {
    auto matrix = adjwidget->getAdjMatrix();
    viswidget->visualizeMatrix(matrix);
    stackedWidget->setCurrentIndex(5); // Move to VisualizeWidget
}

MainWindow::~MainWindow()
{
}
