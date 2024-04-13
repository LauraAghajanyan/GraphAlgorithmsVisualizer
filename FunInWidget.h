#ifndef FUNINWIDGET_H
#define FUNINWIDGET_H

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



class FunInWidget: public QWidget
{
    Q_OBJECT
public:
    QLabel* dragDropLabel;
    QVBoxLayout* dragDropLayout;
    QPushButton* dragDropGoHome;
    QPushButton* dragDropGoSelect;
public:
    FunInWidget(QWidget *parent = nullptr);  
};

#endif //FUNINWIDGET_H