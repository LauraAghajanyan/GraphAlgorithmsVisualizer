#ifndef VISUALIZEWIDGET_H
#define VISUALIZEWIDGET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QToolButton>
#include <QPushButton>
#include <QWheelEvent>
#include <QDateTime>
#include <QGraphicsLineItem>
#include <QPolygonF>
#include <QPointF>
#include <QVector>
#include <QPen>
#include <QWidget>
#include <QCursor>
#include <QAction>
#include <QPixmap>
#include <QString>
#include <QColor>
#include <QLabel>
#include <QEvent>
#include <QMenu>
#include <QGraphicsEllipseItem>
#include <cmath>
#include <climits>
#include "AdjInWidget.h"

class VisualizeWidget: public QWidget
{
    Q_OBJECT
public:
    QLabel* visualizeLabel;
    QHBoxLayout* hvislay;
    QVBoxLayout* vvislay;
    QVBoxLayout* visualizeLayout;
    QPushButton* visualizeGoHome;
    QPushButton* visualizeGoSelect;
    QPushButton* visualizeDijkstra;
    QLineEdit* sourceDijk;
    QLineEdit* destinationDijk;

    QGraphicsScene* sceneOriginal; // Scene for the original graph
    QGraphicsScene* sceneDijkstra; // Future scene for Dijkstra's visualization
    QGraphicsView* viewOriginal; // View for displaying the original graph
    QGraphicsView* viewDijkstra; // Future view for displaying the Dijkstra result
    QPushButton* visualizeDijkstraButton; // Triggers the Dijkstra visualization

    bool eventFilter(QObject* watched, QEvent* event);
    void visualizeMatrix(const QVector<QVector<int>> &matrix); // original graph
    void visualizeMatrixDijk(const QVector<QVector<int>> &matrix); // Dijkstra graph
    void drawArrow(QGraphicsScene* scene, const QPointF& start, const QPointF& end, const QPen& pen, int lineThickness); //original graph
    void drawArrowDijk(QGraphicsScene* scene, const QPointF& start, const QPointF& end, const QPen& pen, int lineThickness); //original graph
    QVector<QVector<int>> dijkstraShortestPathMatrix(const QVector<QVector<int>>& graph, int src, int dest);
    QVector<QVector<int>> matrixDijkstra;
public:
    VisualizeWidget(QWidget *parent = nullptr);  
};

#endif //VISUALIZEWIDGET_H