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
    QLabel* selectLabel;
    QVBoxLayout* selectVLayout;
    QPushButton* selectAdj;
    QPushButton* selectInc;
    QPushButton* selectDragAndDrop;
    QPushButton* selectGoBack;
public:
    
    SelectWidget(QWidget *parent = nullptr);  
};


#endif // SELECTWIDGET_H