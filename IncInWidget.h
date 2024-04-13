#ifndef INCINWIDGET_H
#define INCINWIDGET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QToolButton>
#include <QPushButton>
#include <QMessageBox>
#include <QRegExp>
#include <QRegExpValidator>
#include <QLineEdit>
#include <QDateTime>
#include <QWidget>
#include <QCursor>
#include <QAction>
#include <QVector>
#include <QPixmap>
#include <QString>
#include <QColor>
#include <QLabel>
#include <QMenu>
#include <vector>



class IncInWidget: public QWidget
{
    Q_OBJECT
public:
    QLabel* incLabel;
    QVBoxLayout* incLayout;
    QPushButton* incGoHome;
    QPushButton* incGoSelect;
    QLineEdit *incNumVerticesInput;
    QPushButton *generateIncMatrixBut;
    QPushButton *enterIncMatrix;
    QGridLayout *incMatrixLayout;
    QVector<QLabel*> incVertexLabels;
    QVector<QLabel*> incEdgeLabels;
    QVector<QVector<QLineEdit*>> incMatrixInputs;
    QVector<QVector<int>> incidenceMatrix;
public:
    IncInWidget(QWidget *parent = nullptr);  
private slots:
    void generateIncMatrix();
    void validateInput(const QString &text);
    void clearIncMatrix();
    //void storeMatrix();
};

#endif //INCWIDGET_H