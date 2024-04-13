#ifndef ADJINWIDGET_H
#define ADJINWIDGET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QToolButton>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QDateTime>
#include <QWidget>
#include <QCursor>
#include <QAction>
#include <QPixmap>
#include <QString>
#include <QColor>
#include <QLabel>
#include <QMenu>
#include <vector>

extern QVector<QVector<int>> globMat;

class AdjInWidget: public QWidget
{
    Q_OBJECT
public:

    QLabel* adjLabel; // name of the widget
    QPushButton* adjGoHome; // go start widget button
    QPushButton* adjGoSelect; // go back to select widget

    QLineEdit *adjRowsInput; // needs changes
    QLineEdit *adjColumnsInput; // needs changes

    QPushButton *adjUpdateButton; // update matrix
    QPushButton *enterAdjMat; // when this button is pressed, the matrix should be stored and shown on another widget
    QGridLayout *adjMatrixLayout; // matrix layout

    std::vector<std::vector<QLineEdit*>> adjMatrixInputs; // To store dynamically created inputs
    void createAdjMatrix(int adjRows, int adjColumns);
    void clearAdjMatrix();
    QVector<QVector<int>> getAdjMatrix() const; //method to get the matrix
    
private slots:
    void updateAdjMatrix();
public:
    AdjInWidget(QWidget *parent = nullptr);  
};


#endif // ADJINWIDGET