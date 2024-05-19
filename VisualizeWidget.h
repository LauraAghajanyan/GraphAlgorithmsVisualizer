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
#include <QGraphicsTextItem>
#include <QPainterPath>
#include <QGraphicsPolygonItem>
#include <QPolygonF>
#include <QStack>
#include <QDebug>
#include <cmath>
#include <climits>
#include "AdjInWidget.h"

class VisualizeWidget: public QWidget
{
    Q_OBJECT
public:
    QLabel* visualizeLabel;
    QHBoxLayout* hvislay;
    QHBoxLayout* hvislay1;
    QVBoxLayout* vvislay;

    QVBoxLayout* vvislay1;
    QVBoxLayout* vvislay2;
    QVBoxLayout* vvislay3;
    QVBoxLayout* vvislay4;

    QVBoxLayout* visualizeLayout;
    QToolButton* visualizeGoHome;
    QToolButton* visualizeGoSelect;
    QToolButton* visualizeGoBack;

    QLabel* origLabel;
    QLabel* dijkLabel;
    QLabel* primLabel;
    QLabel* cycleLabel;

    QGraphicsScene* sceneOriginal; // Scene for the original graph
    QGraphicsScene* sceneDijkstra; // Future scene for Dijkstra's visualization
    QGraphicsView* viewOriginal; // View for displaying the original graph
    QGraphicsView* viewDijkstra; // Future view for displaying the Dijkstra result
    QGraphicsView* viewPrim;
    QGraphicsScene* scenePrim;
    QGraphicsScene* sceneCycle;
    QGraphicsView* viewCycle;
    QLabel* displayLabel;
    bool eventFilter(QObject* watched, QEvent* event);
    QPointF calculateControlPoint(const QPointF& start, const QPointF& end, bool reverse);
    qreal degreesToRadians(qreal degrees);
    void visualizeMatrix(const QVector<QVector<int>> &matrix); // original graph
    void visualizeMatrixDijk(const QVector<QVector<int>> &matrix); // Dijkstra graph
    void visualizeMatrixPrim(const QVector<QVector<int>> &matrix); // Prim graph
    void visualizeMatrixCycle(const QVector<QVector<int>>& matrix);
    void drawArrow(QGraphicsScene* scene, const QPointF& start, const QPointF& end, const QPen& pen, int lineThickness); //original graph
    QVector<QVector<int>> dijkstraShortestPathMatrix(const QVector<QVector<int>>& graph, int src, int dest);
    QVector<QVector<int>> matrixDijkstra;
    QVector<QVector<int>> matrixPrim;
    QVector<QVector<int>> primMST(const QVector<QVector<int>>& graph);
    int minKey(const QVector<int>& key, const QVector<bool>& mstSet, int V);

    QVector<int> color; // 0 = unvisited, 1 = visiting, 2 = visited
    QVector<int> parent; // To track the path of the cycle
    QStack<int> cycleStack; // Stack to store the cycle path
    QVector<QVector<int>> findCycle(const QVector<QVector<int>>& graph);
    bool dfs(int u, const QVector<QVector<int>>& graph);
    QVector<QVector<int>> matrixCycle;
    
public:
    VisualizeWidget(QWidget *parent = nullptr);  
};

#endif //VISUALIZEWIDGET_H