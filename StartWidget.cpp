#include "StartWidget.h"

StartWidget::StartWidget(QWidget *parent)
    : QWidget(parent)
{   

    setAutoFillBackground(true);

    QPalette palette = this->palette();
    palette.setColor(QPalette::Window, QColor("#1D4A59"));
    setPalette(palette);

    startLabel = new QLabel("Welcome to Graph Algorithms Visualization application! ");

    startLabel->setStyleSheet("QLabel {"
                            "  color: white;"
                            "  font-size: 25pt;"
                            "  font-weight: bold;"
                            "  font-family: 'Courier New';"
                            "  padding: 10px;"
                            "  background-color: #1D4A59;"  // Dark shade for contrast
                            "}");

    start = new QToolButton;

    start->setIcon(QIcon("Icons/information.png"));
    start->setIconSize(QSize(90, 90));
    start->setAutoRaise(true);
    start->setToolTip("Start");
    start->setStyleSheet("QToolButton { border: none; }");

    startHLayout1 = new QHBoxLayout;
    startHLayout2 = new QHBoxLayout;
    startVLayout = new QVBoxLayout;

    startHLayout1->addWidget(startLabel,5,Qt::AlignHCenter);
    startHLayout2->addWidget(start,5,Qt::AlignHCenter);

    startVLayout->addLayout(startHLayout1);
    startVLayout->addLayout(startHLayout2);
    
    setLayout(startVLayout);
}



