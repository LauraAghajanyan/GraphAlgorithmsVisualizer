#include "StartWidget.h"

StartWidget::StartWidget(QWidget *parent)
    : QWidget(parent)
{
    startLabel = new QLabel("Welcome");
    start = new QPushButton("Start");

    startHLayout1 = new QHBoxLayout;
    startHLayout2 = new QHBoxLayout;
    startVLayout = new QVBoxLayout;

    startHLayout1->addWidget(startLabel,5,Qt::AlignHCenter);
    startHLayout2->addWidget(start,5,Qt::AlignHCenter);

    startVLayout->addLayout(startHLayout1);
    startVLayout->addLayout(startHLayout2);
    
    setLayout(startVLayout);
}



