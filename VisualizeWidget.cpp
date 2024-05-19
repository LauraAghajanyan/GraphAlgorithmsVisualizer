#define _USE_MATH_DEFINES
#include "VisualizeWidget.h"
#include "AdjInWidget.h"

#include <cmath>


VisualizeWidget::VisualizeWidget(QWidget *parent)
    : QWidget(parent)
{
    setAutoFillBackground(true);

    QPalette palette = this->palette();
    palette.setColor(QPalette::Window, QColor("#1D4A59"));
    setPalette(palette);

    visualizeLayout = new QVBoxLayout;

    hvislay = new QHBoxLayout;
    vvislay = new QVBoxLayout;
    hvislay1 = new QHBoxLayout;

    vvislay1 = new QVBoxLayout;
    vvislay2 = new QVBoxLayout;
    vvislay3 = new QVBoxLayout;
    vvislay4 = new QVBoxLayout;

    visualizeLabel = new QLabel("Graph Visualization");

    visualizeLabel->setStyleSheet("QLabel {"
                            "  color: white;"
                            "  font-size: 25pt;"
                            "  font-weight: bold;"
                            "  font-family: 'Courier New';"
                            "  padding: 10px;"
                            "  background-color: #1D4A59;"  // Dark shade for contrast
                            "}");

    origLabel = new QLabel("Original Graph");

    origLabel->setStyleSheet("QLabel {"
                            "  color: white;"
                            "  font-size: 15pt;"
                            "  font-weight: bold;"
                            "  font-family: 'Courier New';"
                            "  padding: 10px;"
                            "  background-color: #1D4A59;"  // Dark shade for contrast
                            "}");

    dijkLabel = new QLabel("Dijkstra's Algorithm");

    dijkLabel->setStyleSheet("QLabel {"
                            "  color: white;"
                            "  font-size: 15pt;"
                            "  font-weight: bold;"
                            "  font-family: 'Courier New';"
                            "  padding: 10px;"
                            "  background-color: #1D4A59;"  // Dark shade for contrast
                            "}");

    primLabel = new QLabel("Prim's Algorithm");

    primLabel->setStyleSheet("QLabel {"
                            "  color: white;"
                            "  font-size: 15pt;"
                            "  font-weight: bold;"
                            "  font-family: 'Courier New';"
                            "  padding: 10px;"
                            "  background-color: #1D4A59;"  // Dark shade for contrast
                            "}");

    cycleLabel = new QLabel("Cycle In a Graph");

    cycleLabel->setStyleSheet("QLabel {"
                            "  color: white;"
                            "  font-size: 15pt;"
                            "  font-weight: bold;"
                            "  font-family: 'Courier New';"
                            "  padding: 10px;"
                            "  background-color: #1D4A59;"  // Dark shade for contrast
                            "}");

    visualizeGoHome = new QToolButton;

    visualizeGoHome->setIcon(QIcon("Icons/home.png"));
    visualizeGoHome->setIconSize(QSize(40, 40));
    visualizeGoHome->setAutoRaise(true);
    visualizeGoHome->setToolTip("Go Home Page");
    visualizeGoHome->setStyleSheet("QToolButton { border: none; }");

    visualizeGoSelect = new QToolButton;

    visualizeGoSelect->setIcon(QIcon("Icons/information.png"));
    visualizeGoSelect->setIconSize(QSize(50, 50));
    visualizeGoSelect->setAutoRaise(true);
    visualizeGoSelect->setToolTip("Go To Information Page");
    visualizeGoSelect->setStyleSheet("QToolButton { border: none; }");

    visualizeGoBack = new QToolButton;

    visualizeGoBack->setIcon(QIcon("Icons/left-arrow.png"));
    visualizeGoBack->setIconSize(QSize(40, 40));
    visualizeGoBack->setAutoRaise(true);
    visualizeGoBack->setToolTip("Go Back");
    visualizeGoBack->setStyleSheet("QToolButton { border: none; }");

    displayLabel = new QLabel;

    sceneOriginal = new QGraphicsScene(this);
    viewOriginal = new QGraphicsView(sceneOriginal, this);

    sceneDijkstra = new QGraphicsScene(this);
    viewDijkstra = new QGraphicsView(sceneDijkstra,this);

    scenePrim = new QGraphicsScene(this);
    viewPrim = new QGraphicsView(scenePrim,this);

    sceneCycle = new QGraphicsScene(this);
    viewCycle = new QGraphicsView(sceneCycle,this);

    viewOriginal->installEventFilter(this);
    viewDijkstra->installEventFilter(this);
    viewPrim->installEventFilter(this);
    viewCycle->installEventFilter(this);
        
    viewOriginal->setFixedSize(450,800);
    viewDijkstra->setFixedSize(450,800);
    viewPrim->setFixedSize(450,800);
    viewCycle->setFixedSize(450,800);

    hvislay1->addWidget(visualizeLabel);
    hvislay1->addWidget(visualizeGoHome);
    hvislay1->addWidget(visualizeGoSelect);
    hvislay1->addWidget(visualizeGoBack);

    vvislay1->addWidget(origLabel,1);
    vvislay1->addWidget(viewOriginal,2);
    //vvislay1->addWidget(displayLabel,2);

    vvislay2->addWidget(dijkLabel,1);
    vvislay2->addWidget(viewDijkstra,2);

    vvislay3->addWidget(primLabel,1);
    vvislay3->addWidget(viewPrim,2);

    vvislay4->addWidget(cycleLabel,1);
    vvislay4->addWidget(viewCycle,2);

    hvislay->addLayout(vvislay1);
    hvislay->addLayout(vvislay2);
    hvislay->addLayout(vvislay3);
    hvislay->addLayout(vvislay4);

    visualizeLayout->addLayout(hvislay1,1);
    visualizeLayout->addLayout(hvislay,2);

    setLayout(visualizeLayout);
}

//this works
bool VisualizeWidget::eventFilter(QObject* watched, QEvent* event) {
    if (event->type() == QEvent::Wheel) {
        QWheelEvent* wheelEvent = static_cast<QWheelEvent*>(event);
        QGraphicsView* view = qobject_cast<QGraphicsView*>(watched);
        if (view) {
            if (wheelEvent->angleDelta().y() > 0) {
                view->scale(1.25, 1.25); // Zoom in
            } else {
                view->scale(0.8, 0.8);   // Zoom out
            }
            return true;
        }
    }
    return QWidget::eventFilter(watched, event);
}

//WoRKS
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


QPointF VisualizeWidget::calculateControlPoint(const QPointF& start, const QPointF& end, bool bidirectional) {
    // Calculate mid-point for the control point
    QPointF midPoint = (start + end) / 2.0;

    // The distance from the midpoint to the control point
    qreal controlDistance = (start - end).manhattanLength() / 4.0; // Adjust this value as needed for the curve

    // Calculate the angle from start to end
    qreal angle = std::atan2(end.y() - start.y(), end.x() - start.x());

    // If it's a bidirectional edge, we need to offset the control points
    // in opposite directions to avoid overlapping arrows
    qreal direction = bidirectional ? M_PI / 2.0 : -M_PI / 2.0;

    // Calculate the control point's offset
    QPointF offset(cos(angle + direction) * controlDistance, sin(angle + direction) * controlDistance);

    // Return the control point
    return midPoint + offset;
}

//helper
qreal pi = 3.14159265358979323846;
qreal VisualizeWidget::degreesToRadians(qreal degrees) {
    return degrees * (pi / 180.0);
}


//kind of works

void VisualizeWidget::visualizeMatrix(const QVector<QVector<int>>& matrix) {
    sceneOriginal->clear(); // Clear the scene for new drawings
    int baseRadius = 400; // Base radius for layout
    double edgeLengthFactor = 2; // Factor to adjust edge lengths
    int radius = static_cast<int>(baseRadius * edgeLengthFactor); // Adjusted radius
    int N = matrix.size(); // Number of nodes
    QVector<QGraphicsEllipseItem*> nodes;
    int nodeDiameter = 250; // Node diameter for visibility
    int lineThickness = 17; // Line thickness

    // Draw nodes
    for (int i = 0; i < N; ++i) {
        qreal angle = 2 * M_PI * i / N;
        qreal x = radius * cos(angle) + baseRadius - nodeDiameter / 2; // Adjust position for larger nodes
        qreal y = radius * sin(angle) + baseRadius - nodeDiameter / 2;
        QGraphicsEllipseItem* node = sceneOriginal->addEllipse(x, y, nodeDiameter, nodeDiameter, QPen(Qt::black, 10), QBrush(Qt::blue));
        nodes.push_back(node);

       // Create a text item for the node label
        QGraphicsTextItem* textItem = sceneOriginal->addText("V" + QString::number(i + 1), QFont("Arial", 50)); // Using names like V1, V2
        textItem->setDefaultTextColor(Qt::black);
        QRectF textRect = textItem->boundingRect();
        QPointF centerPoint = nodes[i]->rect().center();
        textItem->setPos(centerPoint.x() - textRect.width() / 2, centerPoint.y() - textRect.height() / 2);
    }
    
    // Prepare to draw arrows with more distinctive features
    QPen pen(Qt::black, lineThickness); // You can adjust the color and thickness
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);

    // Constants for the adjustments
    qreal nodeRadius = nodeDiameter / 2.0;
    //qreal arrowSize = 30; // Increase the size of the arrow for better visibility
    //qreal loopRadius = nodeDiameter / 3; // Increase the loop size for self-loops
    qreal arrowSize = 30; // Increase the size of the arrow for better visibility
    qreal loopRadius = nodeDiameter / 3; // Increase the loop size for self-loops

     // Draw edges with curves and arrows
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (matrix[i][j] >= 1) {
                QPointF centerA = nodes[i]->rect().center();
                QPointF centerB = nodes[j]->rect().center();

                // Calculate the angle and offsets for the edge's start and end points
                qreal angle = std::atan2(centerB.y() - centerA.y(), centerB.x() - centerA.x());
                QPointF offset(cos(angle) * nodeRadius, sin(angle) * nodeRadius);
                QPointF startPoint = centerA + offset;
                QPointF endPoint = centerB - offset;

                // Create the path for the edge
                QPainterPath path(startPoint);

                if (i == j) {
                    // Draw self-loop with a more visible loop and arrow
                    path.arcMoveTo(centerA.x() - loopRadius, centerA.y() - loopRadius, loopRadius * 2, loopRadius * 2, 0);
                    path.arcTo(centerA.x() - loopRadius, centerA.y() - loopRadius, loopRadius * 2, loopRadius * 2, 0, 270);
                    QGraphicsTextItem* weightText = sceneOriginal->addText(QString::number(matrix[i][j]), QFont("Arial", 30));
                    weightText->setPos(centerA.x() - weightText->boundingRect().width() / 2, centerA.y() - nodeDiameter - weightText->boundingRect().height());
                } else {
                    // For bidirectional edges, make the curve more pronounced by adjusting the control points
                    QPointF controlPoint = calculateControlPoint(startPoint, endPoint, matrix[j][i] >= 1);
                    path.quadTo(controlPoint, endPoint);
                    QPointF midPoint = (startPoint + controlPoint + endPoint) / 3;
                    QGraphicsTextItem* weightText = sceneOriginal->addText(QString::number(matrix[i][j]), QFont("Arial", 30));
                    weightText->setPos(midPoint.x() - weightText->boundingRect().width() / 2, midPoint.y() - weightText->boundingRect().height() / 2);  
                }

                // Draw the path
                QGraphicsPathItem* pathItem = sceneOriginal->addPath(path, pen);

                // Draw the arrowhead at the end of the path
                qreal arrowAngle = path.angleAtPercent(1);
                QPointF arrowP1 = endPoint + QPointF(sin(degreesToRadians(arrowAngle - 90)) * arrowSize,
                                                      cos(degreesToRadians(arrowAngle - 90)) * arrowSize);
                QPointF arrowP2 = endPoint + QPointF(sin(degreesToRadians(arrowAngle + 90)) * arrowSize,
                                                      cos(degreesToRadians(arrowAngle + 90)) * arrowSize);
                QPolygonF arrowHead;
                arrowHead << endPoint << arrowP1 << arrowP2;
                sceneOriginal->addPolygon(arrowHead, pen, QBrush(Qt::red)); // Use a distinctive color for the arrow

                // Adding weight label near the center of the edge
                //QPointF midPoint = (startPoint + endPoint) * 0.5;
                //QGraphicsTextItem* weightText = sceneOriginal->addText(QString::number(matrix[i][j]), QFont("Arial", 20));
                //weightText->setPos(midPoint.x() - weightText->boundingRect().width() / 2, midPoint.y() - weightText->boundingRect().height() / 2);

                // Set the pen for the path to make it stand out
                pathItem->setPen(QPen(Qt::blue, lineThickness, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
            }
        }
    }
    viewOriginal->fitInView(sceneOriginal->sceneRect(), Qt::KeepAspectRatio);
    viewOriginal->setRenderHint(QPainter::Antialiasing);
}

void VisualizeWidget::visualizeMatrixDijk(const QVector<QVector<int>>& matrix) {
    sceneDijkstra->clear(); // Clear the scene for new drawings
    int baseRadius = 400; // Base radius for layout
    double edgeLengthFactor = 2; // Factor to adjust edge lengths
    int radius = static_cast<int>(baseRadius * edgeLengthFactor); // Adjusted radius
    int N = matrix.size(); // Number of nodes
    QVector<QGraphicsEllipseItem*> nodes;
    int nodeDiameter = 250; // Node diameter for visibility
    int lineThickness = 17; // Line thickness

    // Draw nodes
    for (int i = 0; i < N; ++i) {
        qreal angle = 2 * M_PI * i / N;
        qreal x = radius * cos(angle) + baseRadius - nodeDiameter / 2; // Adjust position for larger nodes
        qreal y = radius * sin(angle) + baseRadius - nodeDiameter / 2;
        QGraphicsEllipseItem* node = sceneDijkstra->addEllipse(x, y, nodeDiameter, nodeDiameter, QPen(Qt::black, 10), QBrush(Qt::green));
        nodes.push_back(node);

       // Create a text item for the node label
        QGraphicsTextItem* textItem = sceneDijkstra->addText("V" + QString::number(i + 1), QFont("Arial", 50)); // Using names like V1, V2
        textItem->setDefaultTextColor(Qt::black);
        QRectF textRect = textItem->boundingRect();
        QPointF centerPoint = nodes[i]->rect().center();
        textItem->setPos(centerPoint.x() - textRect.width() / 2, centerPoint.y() - textRect.height() / 2);
    }
    
    // Prepare to draw arrows with more distinctive features
    QPen pen(Qt::black, lineThickness); // You can adjust the color and thickness
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);

    // Constants for the adjustments
    qreal nodeRadius = nodeDiameter / 2.0;
    qreal arrowSize = 30; // Increase the size of the arrow for better visibility
    qreal loopRadius = nodeDiameter / 3; // Increase the loop size for self-loops

     // Draw edges with curves and arrows
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (matrix[i][j] >= 1) {
                QPointF centerA = nodes[i]->rect().center();
                QPointF centerB = nodes[j]->rect().center();

                // Calculate the angle and offsets for the edge's start and end points
                qreal angle = std::atan2(centerB.y() - centerA.y(), centerB.x() - centerA.x());
                QPointF offset(cos(angle) * nodeRadius, sin(angle) * nodeRadius);
                QPointF startPoint = centerA + offset;
                QPointF endPoint = centerB - offset;

                // Create the path for the edge
                QPainterPath path(startPoint);

                if (i == j) {
                    // Draw self-loop with a more visible loop and arrow
                    path.arcMoveTo(centerA.x() - loopRadius, centerA.y() - loopRadius, loopRadius * 2, loopRadius * 2, 0);
                    path.arcTo(centerA.x() - loopRadius, centerA.y() - loopRadius, loopRadius * 2, loopRadius * 2, 0, 270);
                    QGraphicsTextItem* weightText = sceneDijkstra->addText(QString::number(matrix[i][j]), QFont("Arial", 30));
                    weightText->setPos(centerA.x() - weightText->boundingRect().width() / 2, centerA.y() - nodeDiameter - weightText->boundingRect().height());
                } else {
                    // For bidirectional edges, make the curve more pronounced by adjusting the control points
                    QPointF controlPoint = calculateControlPoint(startPoint, endPoint, matrix[j][i] >= 1);
                    path.quadTo(controlPoint, endPoint);
                    QPointF midPoint = (startPoint + controlPoint + endPoint) / 3;
                    QGraphicsTextItem* weightText = sceneDijkstra->addText(QString::number(matrix[i][j]), QFont("Arial", 30));
                    weightText->setPos(midPoint.x() - weightText->boundingRect().width() / 2, midPoint.y() - weightText->boundingRect().height() / 2);  
                }

                // Draw the path
                QGraphicsPathItem* pathItem = sceneDijkstra->addPath(path, pen);

                // Draw the arrowhead at the end of the path
                qreal arrowAngle = path.angleAtPercent(1);
                QPointF arrowP1 = endPoint + QPointF(sin(degreesToRadians(arrowAngle - 90)) * arrowSize,
                                                      cos(degreesToRadians(arrowAngle - 90)) * arrowSize);
                QPointF arrowP2 = endPoint + QPointF(sin(degreesToRadians(arrowAngle + 90)) * arrowSize,
                                                      cos(degreesToRadians(arrowAngle + 90)) * arrowSize);
                QPolygonF arrowHead;
                arrowHead << endPoint << arrowP1 << arrowP2;
                sceneDijkstra->addPolygon(arrowHead, pen, QBrush(Qt::black)); // Use a distinctive color for the arrow

                // Set the pen for the path to make it stand out
                pathItem->setPen(QPen(Qt::green, lineThickness, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
            }
        }
    }
    viewDijkstra->fitInView(sceneDijkstra->sceneRect(), Qt::KeepAspectRatio);
    viewDijkstra->setRenderHint(QPainter::Antialiasing);
}


void VisualizeWidget::visualizeMatrixPrim(const QVector<QVector<int>>& matrix) {
    scenePrim->clear(); // Clear the scene for new drawings
    int baseRadius = 400; // Base radius for layout
    double edgeLengthFactor = 2; // Factor to adjust edge lengths
    int radius = static_cast<int>(baseRadius * edgeLengthFactor); // Adjusted radius
    int N = matrix.size(); // Number of nodes
    QVector<QGraphicsEllipseItem*> nodes;
    int nodeDiameter = 250; // Node diameter for visibility
    int lineThickness = 17; // Line thickness

    // Draw nodes
    for (int i = 0; i < N; ++i) {
        qreal angle = 2 * M_PI * i / N;
        qreal x = radius * cos(angle) + baseRadius - nodeDiameter / 2; // Adjust position for larger nodes
        qreal y = radius * sin(angle) + baseRadius - nodeDiameter / 2;
        QGraphicsEllipseItem* node = scenePrim->addEllipse(x, y, nodeDiameter, nodeDiameter, QPen(Qt::black, 10), QBrush(Qt::magenta));
        nodes.push_back(node);

       // Create a text item for the node label
        QGraphicsTextItem* textItem = scenePrim->addText("V" + QString::number(i + 1), QFont("Arial", 50)); // Using names like V1, V2
        textItem->setDefaultTextColor(Qt::black);
        QRectF textRect = textItem->boundingRect();
        QPointF centerPoint = nodes[i]->rect().center();
        textItem->setPos(centerPoint.x() - textRect.width() / 2, centerPoint.y() - textRect.height() / 2);
    }
    
    // Prepare to draw arrows with more distinctive features
    QPen pen(Qt::black, lineThickness); // You can adjust the color and thickness
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);

    // Constants for the adjustments
    qreal nodeRadius = nodeDiameter / 2.0;
    qreal arrowSize = 30; // Increase the size of the arrow for better visibility
    qreal loopRadius = nodeDiameter / 3; // Increase the loop size for self-loops

     // Draw edges with curves and arrows
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (matrix[i][j] >= 1) {
                QPointF centerA = nodes[i]->rect().center();
                QPointF centerB = nodes[j]->rect().center();

                // Calculate the angle and offsets for the edge's start and end points
                qreal angle = std::atan2(centerB.y() - centerA.y(), centerB.x() - centerA.x());
                QPointF offset(cos(angle) * nodeRadius, sin(angle) * nodeRadius);
                QPointF startPoint = centerA + offset;
                QPointF endPoint = centerB - offset;

                // Create the path for the edge
                QPainterPath path(startPoint);

                if (i == j) {
                    // Draw self-loop with a more visible loop and arrow
                    path.arcMoveTo(centerA.x() - loopRadius, centerA.y() - loopRadius, loopRadius * 2, loopRadius * 2, 0);
                    path.arcTo(centerA.x() - loopRadius, centerA.y() - loopRadius, loopRadius * 2, loopRadius * 2, 0, 270);
                    QGraphicsTextItem* weightText = scenePrim->addText(QString::number(matrix[i][j]), QFont("Arial", 30));
                    weightText->setPos(centerA.x() - weightText->boundingRect().width() / 2, centerA.y() - nodeDiameter - weightText->boundingRect().height());
                } else {
                    // For bidirectional edges, make the curve more pronounced by adjusting the control points
                    QPointF controlPoint = calculateControlPoint(startPoint, endPoint, matrix[j][i] >= 1);
                    path.quadTo(controlPoint, endPoint);
                    QPointF midPoint = (startPoint + controlPoint + endPoint) / 3;
                    QGraphicsTextItem* weightText = scenePrim->addText(QString::number(matrix[i][j]), QFont("Arial", 30));
                    weightText->setPos(midPoint.x() - weightText->boundingRect().width() / 2, midPoint.y() - weightText->boundingRect().height() / 2);  
                }

                // Draw the path
                QGraphicsPathItem* pathItem = scenePrim->addPath(path, pen);

                // Draw the arrowhead at the end of the path
                qreal arrowAngle = path.angleAtPercent(1);
                QPointF arrowP1 = endPoint + QPointF(sin(degreesToRadians(arrowAngle - 90)) * arrowSize,
                                                      cos(degreesToRadians(arrowAngle - 90)) * arrowSize);
                QPointF arrowP2 = endPoint + QPointF(sin(degreesToRadians(arrowAngle + 90)) * arrowSize,
                                                      cos(degreesToRadians(arrowAngle + 90)) * arrowSize);
                QPolygonF arrowHead;
                arrowHead << endPoint << arrowP1 << arrowP2;
                scenePrim->addPolygon(arrowHead, pen, QBrush(Qt::black)); // Use a distinctive color for the arrow

                // Set the pen for the path to make it stand out
                pathItem->setPen(QPen(Qt::magenta, lineThickness, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
            }
        }
    }
    viewPrim->fitInView(scenePrim->sceneRect(), Qt::KeepAspectRatio);
    viewPrim->setRenderHint(QPainter::Antialiasing);
}

//vis cycle
void VisualizeWidget::visualizeMatrixCycle(const QVector<QVector<int>>& matrix) {
    sceneCycle->clear(); // Clear the scene for new drawings
    int baseRadius = 400; // Base radius for layout
    double edgeLengthFactor = 2; // Factor to adjust edge lengths
    int radius = static_cast<int>(baseRadius * edgeLengthFactor); // Adjusted radius
    int N = matrix.size(); // Number of nodes
    QVector<QGraphicsEllipseItem*> nodes;
    int nodeDiameter = 250; // Node diameter for visibility
    int lineThickness = 17; // Line thickness

    // Draw nodes
    for (int i = 0; i < N; ++i) {
        qreal angle = 2 * M_PI * i / N;
        qreal x = radius * cos(angle) + baseRadius - nodeDiameter / 2; // Adjust position for larger nodes
        qreal y = radius * sin(angle) + baseRadius - nodeDiameter / 2;
        QGraphicsEllipseItem* node = sceneCycle->addEllipse(x, y, nodeDiameter, nodeDiameter, QPen(Qt::black, 10), QBrush(Qt::red));
        nodes.push_back(node);

       // Create a text item for the node label
        QGraphicsTextItem* textItem = sceneCycle->addText("V" + QString::number(i + 1), QFont("Arial", 50)); // Using names like V1, V2
        textItem->setDefaultTextColor(Qt::black);
        QRectF textRect = textItem->boundingRect();
        QPointF centerPoint = nodes[i]->rect().center();
        textItem->setPos(centerPoint.x() - textRect.width() / 2, centerPoint.y() - textRect.height() / 2);
    }
    
    // Prepare to draw arrows with more distinctive features
    QPen pen(Qt::black, lineThickness); // You can adjust the color and thickness
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);

    // Constants for the adjustments
    qreal nodeRadius = nodeDiameter / 2.0;
    qreal arrowSize = 30; // Increase the size of the arrow for better visibility
    qreal loopRadius = nodeDiameter / 3; // Increase the loop size for self-loops

     // Draw edges with curves and arrows
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (matrix[i][j] >= 1) {
                QPointF centerA = nodes[i]->rect().center();
                QPointF centerB = nodes[j]->rect().center();

                // Calculate the angle and offsets for the edge's start and end points
                qreal angle = std::atan2(centerB.y() - centerA.y(), centerB.x() - centerA.x());
                QPointF offset(cos(angle) * nodeRadius, sin(angle) * nodeRadius);
                QPointF startPoint = centerA + offset;
                QPointF endPoint = centerB - offset;

                // Create the path for the edge
                QPainterPath path(startPoint);

                if (i == j) {
                    // Draw self-loop with a more visible loop and arrow
                    path.arcMoveTo(centerA.x() - loopRadius, centerA.y() - loopRadius, loopRadius * 2, loopRadius * 2, 0);
                    path.arcTo(centerA.x() - loopRadius, centerA.y() - loopRadius, loopRadius * 2, loopRadius * 2, 0, 270);
                    //QGraphicsTextItem* weightText = sceneCycle->addText(QString::number(matrix[i][j]), QFont("Arial", 30));
                    //weightText->setPos(centerA.x() - weightText->boundingRect().width() / 2, centerA.y() - nodeDiameter - weightText->boundingRect().height());
                } else {
                    // For bidirectional edges, make the curve more pronounced by adjusting the control points
                    QPointF controlPoint = calculateControlPoint(startPoint, endPoint, matrix[j][i] >= 1);
                    path.quadTo(controlPoint, endPoint);
                    //QPointF midPoint = (startPoint + controlPoint + endPoint) / 3;
                    //QGraphicsTextItem* weightText = sceneCycle->addText(QString::number(matrix[i][j]), QFont("Arial", 30));
                    //weightText->setPos(midPoint.x() - weightText->boundingRect().width() / 2, midPoint.y() - weightText->boundingRect().height() / 2);  
                }

                // Draw the path
                QGraphicsPathItem* pathItem = sceneCycle->addPath(path, pen);

                // Draw the arrowhead at the end of the path
                qreal arrowAngle = path.angleAtPercent(1);
                QPointF arrowP1 = endPoint + QPointF(sin(degreesToRadians(arrowAngle - 90)) * arrowSize,
                                                      cos(degreesToRadians(arrowAngle - 90)) * arrowSize);
                QPointF arrowP2 = endPoint + QPointF(sin(degreesToRadians(arrowAngle + 90)) * arrowSize,
                                                      cos(degreesToRadians(arrowAngle + 90)) * arrowSize);
                QPolygonF arrowHead;
                arrowHead << endPoint << arrowP1 << arrowP2;
                sceneCycle->addPolygon(arrowHead, pen, QBrush(Qt::black)); // Use a distinctive color for the arrow

                // Set the pen for the path to make it stand out
                pathItem->setPen(QPen(Qt::red, lineThickness, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
            }
        }
    }
    viewCycle->fitInView(sceneCycle->sceneRect(), Qt::KeepAspectRatio);
    viewCycle->setRenderHint(QPainter::Antialiasing);
}


QVector<QVector<int>> VisualizeWidget::dijkstraShortestPathMatrix(const QVector<QVector<int>>& graph, int src, int dest) {
    int n = graph.size();
    QVector<int> dist(n, INT_MAX);  // Distance from src to all vertices
    QVector<int> prev(n, -1);  // To store the path information
    QVector<bool> visited(n, false);  // Visitation state of each vertex

    QVector<QVector<int>> pathMatrix(n, QVector<int>(n, 0));  // Resultant path matrix

    dist[src] = 0;  // Distance from source to itself is always 0
   int u = -1; // Initialize u to an invalid vertex index
    for (int count = 0; count < n - 1; count++) {
        int minDistance = INT_MAX; // Track the minimum distance

        for (int i = 0; i < n; i++) {
            if (!visited[i] && (u == -1 || dist[i] < minDistance)) {
                minDistance = dist[i];
                u = i;
            }
        }

        if (u == -1) break; // No valid vertex found (all remaining vertices are unreachable)

        visited[u] = true; // Mark the vertex as visited

        // Update dist and prev for each adjacent vertex
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] > 0 && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                prev[v] = u;
            }
        }
    }

    // Backtrack from the destination to the source and build the path matrix
    u = dest;
    while (prev[u] != -1) {
        int v = prev[u];
        pathMatrix[v][u] = graph[v][u];  // Use the original weight
        u = v;
    }
    return pathMatrix;  // This matrix has edges only along the shortest path from src to dest
}


//works
//prim's algo
// Function to find the vertex with minimum key value
int VisualizeWidget::minKey(const QVector<int>& key, const QVector<bool>& mstSet, int V) {
    int min = std::numeric_limits<int>::max(), min_index = 0;

    for (int v = 0; v < V; ++v) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

//works
// Function to construct and print MST for a graph represented using adjacency matrix representation
QVector<QVector<int>> VisualizeWidget::primMST(const QVector<QVector<int>>& graph) {

    int V = graph.size();

    // Array to store constructed MST
    QVector<int> parent(V);

    // Key values used to pick minimum weight edge in cut
    QVector<int> key(V);

    // To represent set of vertices included in MST
    QVector<bool> mstSet(V, false);

    // Initialize all keys as INFINITE
    for (int i = 0; i < V; ++i) {
        key[i] = std::numeric_limits<int>::max();
    }

    // Always include first 1st vertex in MST
    key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
    parent[0] = -1; // First node is always root of MST

    // The MST will have V vertices
    for (int count = 0; count < V - 1; ++count) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet, V);

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update key value and parent index of the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not yet included in MST
        for (int v = 0; v < V; ++v) {
            // graph[u][v] is non zero only for adjacent vertices of m
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Return the constructed MST
    QVector<QVector<int>> mst(V, QVector<int>(V, 0));
    for (int i = 1; i < V; ++i) {
        mst[parent[i]][i] = graph[i][parent[i]];
        mst[i][parent[i]] = graph[i][parent[i]];
    }

    return mst;
}

bool VisualizeWidget::dfs(int u, const QVector<QVector<int>>& graph) {
        color[u] = 1; // Mark as visiting

        for (int v = 0; v < graph[u].size(); v++) {
            if (graph[u][v] != 0) { // There's a directed edge from u to v
                if (color[v] == 1) { // Found a back edge
                    // Push the cycle vertices into stack
                    for (int x = u; x != v; x = parent[x]) {
                        cycleStack.push_back(x);
                    }
                    cycleStack.push_back(v);
                    cycleStack.push_back(u);
                    return true;
                } else if (color[v] == 0) { // If not visited
                    parent[v] = u;
                    if (dfs(v, graph)) return true;
                }
            }
        }

        color[u] = 2; // Mark as visited (fully processed)
        return false;
}


QVector<QVector<int>> VisualizeWidget::findCycle(const QVector<QVector<int>>& graph) {
        int n = graph.size();
        color = QVector<int>(n, 0);
        parent = QVector<int>(n, -1);
        cycleStack.clear();

        for (int i = 0; i < n; i++) {
            if (color[i] == 0 && dfs(i, graph)) {
                QVector<QVector<int>> cycleMatrix(n, QVector<int>(n, 0));
                int prev = cycleStack.back();
                cycleStack.pop_back();
                while (!cycleStack.isEmpty()) {
                    int curr = cycleStack.back();
                    cycleStack.pop_back();
                    cycleMatrix[prev][curr] = 1;
                    prev = curr;
                }
                return cycleMatrix;
            }
        }

        return QVector<QVector<int>>(); // Return an empty matrix if no cycle is found
}