#ifndef SELECTWIDGET_H
#define SELECTWIDGET_H

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
#include <QPalette>
#include <QAction>
#include <QPixmap>
#include <QString>
#include <QColor>
#include <QLabel>
#include <QMenu>



class SelectWidget: public QWidget
{
    Q_OBJECT
public:
    QHBoxLayout* selectHLayout;
    QVBoxLayout* selectVLayout;
    QToolButton* selectAdj;
    QToolButton* selectGoBack;
    QLabel* introText;
    QLabel* graphText;
    QLabel* introDijk;
    QLabel* dijkText;
    QLabel* introPrim;
    QLabel* primText;
    QLabel* introMST;
    QLabel* mstText;
    QLabel* introCycle;
    QLabel* cycleText;
    QLabel* introFindCycle;
    QLabel* findCycleText;
public:
    
    SelectWidget(QWidget *parent = nullptr);  
};


#endif // SELECTWIDGET_H