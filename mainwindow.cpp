#include "mainwindow.h"

MainWindow::MainWindow()
{
    resize(1000,1000);
    setWindowTitle("Graph Algorithms Visualizer");
    setWindowIcon(QIcon("Icons/knowledge-graph.png"));

    
    //show a logo of our application
    startingWidget = new QWidget;
    // Create a QLabel and set its pixmap to the photo you want to display
    startingLabel = new QLabel(startingWidget);
    QPixmap photo("Icons/knowledge-graph.png");
    startingLabel->setPixmap(photo);
    // Set the photo label to be full-screen
    startingLabel->setGeometry(0, 0, width(), height());
    startingLabel->setAlignment(Qt::AlignCenter);
    // Set the photo widget as the central widget of the main window
    setCentralWidget(startingWidget);

    stackedWidget = new QStackedWidget;
    startwidget = new StartWidget;
    selectwidget = new SelectWidget;
    adjwidget = new AdjInWidget;
    viswidget = new VisualizeWidget;

    stackedWidget->addWidget(startwidget); // index 0
    stackedWidget->addWidget(selectwidget); // index 1
    stackedWidget->addWidget(adjwidget); // index 2
    stackedWidget->addWidget(viswidget); //index 3

    QTimer::singleShot(3000, this, [=]() {
        QScrollArea *scrollArea = new QScrollArea;
        scrollArea->setWidget(stackedWidget);
        scrollArea->setWidgetResizable(true);  // Make the scroll area resizable

        // Set the scroll area as the central widget of the main window
        setCentralWidget(scrollArea);
        //setCentralWidget(stackedWidget);
        delete startingWidget;
    });

    menuBar = new QMenuBar(this);
    
    help_menu = new QMenu("Help",this);
    about_us = new QAction("About us",this);

    help_menu->addAction(about_us);
    about_us->setIcon(QIcon("Icons/knowledge-graph.png"));

    menuBar->addMenu(help_menu);

    setMenuBar(menuBar);

    //setCentralWidget(stackedWidget);

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

    //adjecent widget
    connect(adjwidget->adjGoHome,&QPushButton::clicked,this,[this](){
        stackedWidget->setCurrentIndex(0);
    });
    connect(adjwidget->adjGoSelect,&QPushButton::clicked,this,[this](){
        stackedWidget->setCurrentIndex(1);
    });

    //visualize widget
    connect(viswidget->visualizeGoHome,&QPushButton::clicked,this,[this](){
        stackedWidget->setCurrentIndex(0);
    });
    connect(viswidget->visualizeGoSelect,&QPushButton::clicked,this,[this](){
        stackedWidget->setCurrentIndex(1);
    });
    connect(viswidget->visualizeGoBack,&QPushButton::clicked,this,[this](){
        stackedWidget->setCurrentIndex(2);
    });
    //from adjwidget go to viswidget when pressing Enter
    connect(adjwidget->enterAdjMat, &QPushButton::clicked, this, &MainWindow::onEnterAdjMatPressed);

    connect(about_us,&QAction::triggered,this,&MainWindow::aboutUsMessageBox);

}

void MainWindow::aboutUsMessageBox(){
    QMessageBox::about(this, tr("About our application"),
            tr("The 'Graph Algorithms Visualization' application is an interactive tool designed to demonstrate and visualize the workings of various graph algorithms in real time. Aimed at students and professionals alike, it provides a user-friendly interface that allows users to input graphs either through adjacency matrices or, in future updates, incidence matrices. Users can choose from a selection of algorithms, such as Dijkstra's and Prim's, to apply to their graph. The application visually displays the original graph, the steps of the algorithm, and the final results, including shortest paths and minimum spanning trees. It also includes functionality to detect and illustrate cycles within the graph. Enhanced by features like a drag-and-drop interface for graph construction and planned expansions for more complex algorithms, this tool serves as both an educational resource and a practical aid in understanding the dynamic nature of graph algorithms."));
}

void MainWindow::onEnterAdjMatPressed() {
    auto matrix = adjwidget->getAdjMatrix(); //prim
    auto matrix1 = adjwidget->getAdjMatrix(); // dijkstra
    auto matrix2 = adjwidget->getAdjMatrix(); // cycle

    if(adjwidget->checkPrim->isChecked() && adjwidget->isMatrixSymmetric(matrix)){
        viswidget->visualizeMatrix(matrix); //original
        //prim
        viswidget->matrixPrim =  viswidget->primMST(matrix);
        viswidget->visualizeMatrixPrim(viswidget->matrixPrim);
        //dijkstra
        viswidget->matrixDijkstra =  viswidget->dijkstraShortestPathMatrix(matrix1,adjwidget->adjSource->text().toInt() - 1, adjwidget->adjDest->text().toInt() - 1);
        viswidget->visualizeMatrixDijk(viswidget->matrixDijkstra);
        //cycle
        viswidget->matrixCycle = viswidget->findCycle(matrix2);
        viswidget->visualizeMatrixCycle(viswidget->matrixCycle);
    }
    else{
        viswidget->visualizeMatrix(matrix); //original
        //prim
        //viswidget->matrixPrim =  viswidget->primMST(matrix);
        //viswidget->visualizeMatrixPrim(viswidget->matrixPrim);
        //dijkstra
        viswidget->matrixDijkstra =  viswidget->dijkstraShortestPathMatrix(matrix1,adjwidget->adjSource->text().toInt() - 1, adjwidget->adjDest->text().toInt() - 1);
        viswidget->visualizeMatrixDijk(viswidget->matrixDijkstra);
        //cycle
        viswidget->matrixCycle = viswidget->findCycle(matrix2);
        viswidget->visualizeMatrixCycle(viswidget->matrixCycle);
    }
    stackedWidget->setCurrentIndex(3); // Move to VisualizeWidget
}

MainWindow::~MainWindow()
{
}
