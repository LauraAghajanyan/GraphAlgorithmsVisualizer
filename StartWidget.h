#ifndef STARTWIDGET_H
#define STARTWIDGET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QToolButton>
#include <QPushButton>
#include <QDateTime>
#include <QWidget>
#include <QCursor>
#include <QAction>
#include <QPixmap>
#include <QPalette>
#include <QString>
#include <QColor>
#include <QLabel>
#include <QMenu>



class StartWidget: public QWidget
{
    Q_OBJECT
public:
    QLabel* startLabel;
    QHBoxLayout* startHLayout1;
    QHBoxLayout* startHLayout2;
    QVBoxLayout* startVLayout;
    QToolButton* start;
public:
    StartWidget(QWidget *parent = nullptr);  
};


#endif // STARTWIDGET_H