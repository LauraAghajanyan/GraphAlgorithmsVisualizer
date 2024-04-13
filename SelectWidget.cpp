#include "SelectWidget.h"

SelectWidget::SelectWidget(QWidget *parent)
    : QWidget(parent)
{
    selectLabel = new QLabel("Select widget");

    selectAdj = new QPushButton("Adjacent");
    selectInc = new QPushButton("Incidence");
    selectDragAndDrop = new QPushButton("Drag and Drop");
    selectGoBack = new QPushButton("Go Back");

    selectVLayout = new QVBoxLayout;

    selectVLayout->addWidget(selectLabel);
    selectVLayout->addWidget(selectAdj);
    selectVLayout->addWidget(selectInc);
    selectVLayout->addWidget(selectDragAndDrop);
    selectVLayout->addWidget(selectGoBack);
    
    setLayout(selectVLayout);
}