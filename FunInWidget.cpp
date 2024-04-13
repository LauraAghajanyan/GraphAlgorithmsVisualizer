#include "FunInWidget.h"

FunInWidget::FunInWidget(QWidget *parent)
    : QWidget(parent)
{
    dragDropLabel = new QLabel("Drag and Drop vertices");
    dragDropLayout = new QVBoxLayout;
    dragDropGoHome = new QPushButton("Home");
    dragDropGoSelect = new QPushButton("Go back");
    dragDropLayout->addWidget(dragDropLabel);
    dragDropLayout->addWidget(dragDropGoHome);
    dragDropLayout->addWidget(dragDropGoSelect);
    setLayout(dragDropLayout);
}