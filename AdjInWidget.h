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
#include <QDebug>
#include <vector>
#include <QCheckBox>
#include <QSpacerItem>

extern QVector<QVector<int>> globMat;

class AdjInWidget: public QWidget
{
    Q_OBJECT
public:

    QLabel* adjLabel; // name of the widget
    QToolButton* adjGoHome; // go start widget button
    QToolButton* adjGoSelect; // go back to select widget
    QLabel* rowsLabel;
    QLabel* colLabel;

    QCheckBox* checkPrim;

    QLineEdit *adjRowsInput; // needs changes
    QLineEdit *adjColumnsInput; // needs changes

    QLineEdit *adjSource; // needs changes
    QLineEdit *adjDest; // needs changes

    QToolButton *adjUpdateButton; // update matrix
    QToolButton *enterAdjMat; // when this button is pressed, the matrix should be stored and shown on another widget
    QGridLayout *adjMatrixLayout; // matrix layout
    QHBoxLayout* hlay1; //go home, go select
    QHBoxLayout* hlay2; //source destination
    QVBoxLayout* vlay1; //rows label lineedit
    QVBoxLayout* vlay2; //columns label lineedit
    QHBoxLayout* hlay3; //rows columns
    QHBoxLayout* hlay4;
    QLabel* enablePrim;
    QLabel* srcDestLabel;
    QLabel* adjInput;
    QLabel* infoAdj;
    int adjRows;
    int adjColumns;

    std::vector<std::vector<QLineEdit*>> adjMatrixInputs; // To store dynamically created inputs
    void createAdjMatrix(int adjRows, int adjColumns);
    void updateMatrixSymmetry();
    void clearAdjMatrix();
    bool isMatrixSymmetric(const QVector<QVector<int>>& matrix);
    QVector<QVector<int>> getAdjMatrix() const; //method to get the matrix

    bool isCheckboxChecked();
    
private slots:
    void updateAdjMatrix();
public:
    AdjInWidget(QWidget *parent = nullptr);  
};


#endif // ADJINWIDGET