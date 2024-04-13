#define _USE_MATH_DEFINES
#include "VisualizeWidget.h"
#include "AdjInWidget.h"

#include <cmath>


VisualizeWidget::VisualizeWidget(QWidget *parent)
    : QWidget(parent)
{

    hvislay = new QHBoxLayout;
    vvislay = new QVBoxLayout;

    visualizeLabel = new QLabel("Graph Visualization");
    visualizeLayout = new QVBoxLayout;
    visualizeGoHome = new QPushButton("Home");
    visualizeGoSelect = new QPushButton("Go back");
    visualizeDijkstra = new QPushButton("Dijkstra's Algorithm");

    sourceDijk = new QLineEdit("Source");
    destinationDijk = new QLineEdit("Destination");

    sceneDijkstra = new QGraphicsScene(this);
    viewDijkstra = new QGraphicsView(sceneDijkstra,this);

    sceneOriginal = new QGraphicsScene(this);
    viewOriginal = new QGraphicsView(sceneOriginal, this);
    viewOriginal->installEventFilter(this);
    viewDijkstra->installEventFilter(this);
        
    viewOriginal->setMinimumSize(300,300);
    viewDijkstra->setMinimumSize(300,300);

    //matrixDijkstra =  dijkstraShortestPathMatrix(globMat, sourceDijk->text().toInt(), destinationDijk->text().toInt());
    //visualizeMatrixDijk(matrixDijkstra);

    hvislay->addWidget(viewOriginal);
    hvislay->addWidget(viewDijkstra);

    vvislay->addWidget(visualizeLabel);
    vvislay->addWidget(visualizeDijkstra);
    vvislay->addWidget(sourceDijk);
    vvislay->addWidget(destinationDijk);
    vvislay->addWidget(visualizeGoHome);
    vvislay->addWidget(visualizeGoSelect);

    visualizeLayout->addLayout(vvislay,1);
    visualizeLayout->addLayout(hvislay,2);

    setLayout(visualizeLayout);
}



bool VisualizeWidget::eventFilter(QObject* watched, QEvent* event) {
    if (watched == viewOriginal && event->type() == QEvent::Wheel) {
        QWheelEvent* wheelEvent = static_cast<QWheelEvent*>(event);
        if (wheelEvent->angleDelta().y() > 0) {
            viewOriginal->scale(1.25, 1.25); // Zoom in
        } else {
            viewOriginal->scale(0.8, 0.8);   // Zoom out
        }
        return true;
    }
    return QWidget::eventFilter(watched, event);
}

void VisualizeWidget::drawArrow(QGraphicsScene* scene, const QPointF& start, const QPointF& end, const QPen& pen, int lineThickness) {
    // Line
    scene->addLine(QLineF(start, end), pen);

    // Arrowhead
    double angle = std::atan2(-1 * (end.y() - start.y()), end.x() - start.x());
    double arrowHeadLength = 20; // Customize as needed based on your graph's scale
    QPointF arrowP1 = end + QPointF(sin(angle + M_PI / 3) * arrowHeadLength,
                                    cos(angle + M_PI / 3) * arrowHeadLength);
    QPointF arrowP2 = end + QPointF(sin(angle + M_PI - M_PI / 3) * arrowHeadLength,
                                    cos(angle + M_PI - M_PI / 3) * arrowHeadLength);

    QPolygonF arrowHead;
    arrowHead << end << arrowP1 << arrowP2;
    scene->addPolygon(arrowHead, pen, QBrush(pen.color())); // Fill arrowhead with the same color as the pen
}

void VisualizeWidget::drawArrowDijk(QGraphicsScene* scene, const QPointF& start, const QPointF& end, const QPen& pen, int lineThickness) {
    // Line
    scene->addLine(QLineF(start, end), pen);

    // Arrowhead
    double angle = std::atan2(-1 * (end.y() - start.y()), end.x() - start.x());
    double arrowHeadLength = 20; // Customize as needed based on your graph's scale
    QPointF arrowP1 = end + QPointF(sin(angle + M_PI / 3) * arrowHeadLength,
                                    cos(angle + M_PI / 3) * arrowHeadLength);
    QPointF arrowP2 = end + QPointF(sin(angle + M_PI - M_PI / 3) * arrowHeadLength,
                                    cos(angle + M_PI - M_PI / 3) * arrowHeadLength);

    QPolygonF arrowHead;
    arrowHead << end << arrowP1 << arrowP2;
    scene->addPolygon(arrowHead, pen, QBrush(pen.color())); // Fill arrowhead with the same color as the pen
}

void VisualizeWidget::visualizeMatrix(const QVector<QVector<int>>& matrix) {
    sceneOriginal->clear(); // Clear the scene for new drawings
    int baseRadius = 400; // Base radius for layout
    double edgeLengthFactor = 1.5; // Factor to adjust edge lengths
    int radius = static_cast<int>(baseRadius * edgeLengthFactor); // Adjusted radius
    int N = matrix.size(); // Number of nodes
    QVector<QGraphicsEllipseItem*> nodes;
    int nodeDiameter = 250; // Node diameter for visibility
    int lineThickness = 27; // Line thickness

    // Draw nodes
    for (int i = 0; i < N; ++i) {
        qreal angle = 2 * M_PI * i / N;
        qreal x = radius * cos(angle) + baseRadius - nodeDiameter / 2; // Adjust position for larger nodes
        qreal y = radius * sin(angle) + baseRadius - nodeDiameter / 2;
        QGraphicsEllipseItem* node = sceneOriginal->addEllipse(x, y, nodeDiameter, nodeDiameter, QPen(Qt::black, lineThickness), QBrush(Qt::blue));
        nodes.push_back(node);
    }

    QPen pen(Qt::black, lineThickness);
    // Draw edges
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j && matrix[i][j] == 1) {
                // Self-loop
                QPointF center = nodes[i]->rect().center();
                qreal loopRadius = nodeDiameter / 4; // Customize as needed
                sceneOriginal->addEllipse(center.x() - loopRadius, center.y() - nodeDiameter / 2 - loopRadius * 2, loopRadius * 2, loopRadius * 2, pen, QBrush(Qt::black));
            } else if (matrix[i][j] == 1) {
                // Directed edge
                QPointF start = nodes[i]->rect().center();
                QPointF end = nodes[j]->rect().center();
                drawArrow(sceneOriginal, start, end, pen, lineThickness);
            }
        }
    }

    viewOriginal->fitInView(sceneOriginal->sceneRect(), Qt::KeepAspectRatio);
    viewOriginal->setRenderHint(QPainter::Antialiasing);
}

void VisualizeWidget::visualizeMatrixDijk(const QVector<QVector<int>>& matrix) {
    sceneDijkstra->clear(); // Clear the scene for new drawings
    int baseRadius = 400; // Base radius for layout
    double edgeLengthFactor = 1.5; // Factor to adjust edge lengths
    int radius = static_cast<int>(baseRadius * edgeLengthFactor); // Adjusted radius
    int N = matrix.size(); // Number of nodes
    QVector<QGraphicsEllipseItem*> nodes;
    int nodeDiameter = 250; // Node diameter for visibility
    int lineThickness = 27; // Line thickness

    // Draw nodes
    for (int i = 0; i < N; ++i) {
        qreal angle = 2 * M_PI * i / N;
        qreal x = radius * cos(angle) + baseRadius - nodeDiameter / 2; // Adjust position for larger nodes
        qreal y = radius * sin(angle) + baseRadius - nodeDiameter / 2;
        QGraphicsEllipseItem* node = sceneDijkstra->addEllipse(x, y, nodeDiameter, nodeDiameter, QPen(Qt::black, lineThickness), QBrush(Qt::blue));
        nodes.push_back(node);
    }

    QPen pen(Qt::black, lineThickness);
    // Draw edges
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j && matrix[i][j] == 1) {
                // Self-loop
                QPointF center = nodes[i]->rect().center();
                qreal loopRadius = nodeDiameter / 4; // Customize as needed
                sceneDijkstra->addEllipse(center.x() - loopRadius, center.y() - nodeDiameter / 2 - loopRadius * 2, loopRadius * 2, loopRadius * 2, pen, QBrush(Qt::black));
            } else if (matrix[i][j] == 1) {
                // Directed edge
                QPointF start = nodes[i]->rect().center();
                QPointF end = nodes[j]->rect().center();
                drawArrow(sceneDijkstra, start, end, pen, lineThickness);
            }
        }
    }

    viewDijkstra->fitInView(sceneDijkstra->sceneRect(), Qt::KeepAspectRatio);
    viewDijkstra->setRenderHint(QPainter::Antialiasing);
}

QVector<QVector<int>> VisualizeWidget::dijkstraShortestPathMatrix(const QVector<QVector<int>>& graph, int src, int dest) {
    int n = graph.size();
    QVector<int> dist(n, INT_MAX);  // Distance from src to all vertices
    QVector<int> prev(n, -1);  // To store the path information
    QVector<bool> visited(n, false);  // Visitation state of each vertex

    QVector<QVector<int>> pathMatrix(n, QVector<int>(n, 0));  // Resultant path matrix

    dist[src] = 0;  // Distance from source to itself is always 0

    for (int count = 0; count < n - 1; count++) {
        // Find the vertex with the minimum distance from the set of unvisited vertices.
        int u = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u])) {
                u = i;
            }
        }

        visited[u] = true;  // Mark the vertex as visited

        // Update dist and prev for each adjacent vertex
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] > 0 && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                prev[v] = u;
            }
        }
    }

    // Backtrack from the destination to the source and build the path matrix
    int u = dest;
    while (prev[u] != -1) {
        int v = prev[u];
        pathMatrix[v][u] = graph[v][u];  // Use the original weight
        u = v;
    }

    return pathMatrix;  // This matrix has edges only along the shortest path from src to dest
}