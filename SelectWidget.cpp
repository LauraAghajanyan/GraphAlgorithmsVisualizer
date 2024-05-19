#include "SelectWidget.h"

SelectWidget::SelectWidget(QWidget *parent)
    : QWidget(parent)
{
    setAutoFillBackground(true);

    QPalette palette = this->palette();
    palette.setColor(QPalette::Window, QColor("#1D4A59"));
    setPalette(palette);

    introText = new QLabel("Introduction to Graphs");

    introText->setStyleSheet("QLabel {"
                            "  color: white;"
                            "  font-size: 20pt;"
                            "  font-weight: bold;"
                            "  font-family: 'Courier New';"
                            "  padding: 10px;"
                            "  background-color: #1D4A59;"  
                            "}");

    graphText = new QLabel("Graphs are fundamental structures in computer science and mathematics, used to model relationships between objects."
                            "A graph consists of a set of vertices (or nodes) and edges connecting pairs of vertices." 
                            "<br>Graphs can be either directed (where edges have direction) or undirected (with no direction specified)." 
                            "They can also be weighted (where edges have values) or unweighted." 
                            "<br>Graphs are utilized in various applications, such as social network analysis, computer networks, and transportation networks.");

    graphText->setStyleSheet("QLabel {"
                            "  color: white;"
                            "  font-size: 8pt;"
                            "  font-weight: bold;"
                            "  font-family: 'Courier New';"
                            "  padding: 10px;"
                            "  background-color: #1D4A59;"  
                            "}");

    introCycle = new QLabel("Cycle in a Graph");

    introCycle->setStyleSheet("QLabel {"
                            "  color: white;"
                            "  font-size: 20pt;"
                            "  font-weight: bold;"
                            "  font-family: 'Courier New';"
                            "  padding: 10px;"
                            "  background-color: #1D4A59;"  
                            "}");

    cycleText = new QLabel("A cycle in a graph is a sequence of edges and vertices wherein a vertex is reachable from itself, following a closed path. "
                            "<br>Specifically, a cycle must contain at least one edge and must start and end at the same vertex.");

    cycleText->setStyleSheet("QLabel {"
                            "  color: white;"
                            "  font-size: 8pt;"
                            "  font-weight: bold;"
                            "  font-family: 'Courier New';"
                            "  padding: 10px;"
                            "  background-color: #1D4A59;"  
                            "}");

    introMST = new QLabel("Minimal Spanning Tree(MST)");

    introMST->setStyleSheet("QLabel {"
                            "  color: white;"
                            "  font-size: 20pt;"
                            "  font-weight: bold;"
                            "  font-family: 'Courier New';"
                            "  padding: 10px;"
                            "  background-color: #1D4A59;"  
                            "}");

    mstText = new QLabel("A Minimal Spanning Tree (MST) is a subset of the edges of a connected, edge-weighted (usually undirected) graph that connects all the vertices together, without any cycles, and with the minimum possible total edge weight. "
                        "<br>The goal of an MST is to minimize the cost of connecting all points in the graph."
                        "<br>MSTs are used in various practical applications, such as designing least-cost networks (like computer networks, electrical grids), clustering data, and constructing roads among cities.");

    mstText->setStyleSheet("QLabel {"
                            "  color: white;"
                            "  font-size: 8pt;"
                            "  font-weight: bold;"
                            "  font-family: 'Courier New';"
                            "  padding: 10px;"
                            "  background-color: #1D4A59;"  
                            "}");

    introDijk = new QLabel("Dijkstra's Algorithm");

    introDijk->setStyleSheet("QLabel {"
                            "  color: white;"
                            "  font-size: 20pt;"
                            "  font-weight: bold;"
                            "  font-family: 'Courier New';"
                            "  padding: 10px;"
                            "  background-color: #1D4A59;"  
                            "}");

    dijkText = new QLabel("Dijkstra's Algorithm is a famous graph-searching method used to find the shortest path from a single source vertex to all other vertices in a weighted graph with non-negative edge weights."
                        "<br>Developed by Edsger W. Dijkstra in 1956, the algorithm works by iteratively selecting the vertex with the minimum distance estimate, updating the distance of its adjacent vertices, and then marking it as 'visited'."
                        "<br>The process repeats until all vertices are visited.");

    dijkText->setStyleSheet("QLabel {"
                            "  color: white;"
                            "  font-size: 8pt;"
                            "  font-weight: bold;"
                            "  font-family: 'Courier New';"
                            "  padding: 10px;"
                            "  background-color: #1D4A59;"  
                            "}");

    introPrim = new QLabel("Prim's Algorithm");

    introPrim->setStyleSheet("QLabel {"
                            "  color: white;"
                            "  font-size: 20pt;"
                            "  font-weight: bold;"
                            "  font-family: 'Courier New';"
                            "  padding: 10px;"
                            "  background-color: #1D4A59;"  
                            "}");

    primText = new QLabel("Prim's Algorithm is used to find a minimum spanning tree (MST) for a connected weighted graph, enabling the graph to be traversed at the minimum possible cost without any cycles."
                        "<br>Like Dijkstra's, Prim's also begins with a single vertex and expands the MST by adding the nearest vertex that is not already included.");

    primText->setStyleSheet("QLabel {"
                            "  color: white;"
                            "  font-size: 8pt;"
                            "  font-weight: bold;"
                            "  font-family: 'Courier New';"
                            "  padding: 10px;"
                            "  background-color: #1D4A59;"  
                            "}");

    introFindCycle = new QLabel("Find a Cycle In a Graph");

    introFindCycle->setStyleSheet("QLabel {"
                            "  color: white;"
                            "  font-size: 20pt;"
                            "  font-weight: bold;"
                            "  font-family: 'Courier New';"
                            "  padding: 10px;"
                            "  background-color: #1D4A59;"  
                            "}");

    findCycleText = new QLabel("This algorithm checks whether there is a cycle in the given graph or not. If yes, it shows one of the cycle. "
                                "<br>Detecting cycles in a graph can be accomplished using various methods, depending on whether the graph is directed or undirected."
                                "<br>For Undirected Graphs:"
                                "<br>Depth-First Search (DFS): This technique uses a recursive method to traverse through the graph. If during traversal, the graph revisits a node that is not the immediate parent of the current node, a cycle is detected."
                                "<br>For Directed Graphs:"
                                "<br>DFS for Directed Graphs: Similar to undirected graphs, but care must be taken to differentiate between back edges (which contribute to cycles) and cross edges (which do not).");

    findCycleText->setStyleSheet("QLabel {"
                            "  color: white;"
                            "  font-size: 8pt;"
                            "  font-weight: bold;"
                            "  font-family: 'Courier New';"
                            "  padding: 10px;"
                            "  background-color: #1D4A59;"  
                            "}");

    selectAdj = new QToolButton;

    selectAdj->setIcon(QIcon("Icons/matrix.png"));
    selectAdj->setIconSize(QSize(100, 100));
    selectAdj->setAutoRaise(true);
    selectAdj->setToolTip("Adjacency Matrix");
    selectAdj->setStyleSheet("QToolButton { border: none; }");

    selectGoBack = new QToolButton;

    selectGoBack->setIcon(QIcon("Icons/left-arrow.png"));
    selectGoBack->setIconSize(QSize(100, 100));
    selectGoBack->setAutoRaise(true);
    selectGoBack->setToolTip("Go Home Page");
    selectGoBack->setStyleSheet("QToolButton { border: none; }");

    selectHLayout = new QHBoxLayout;
    selectVLayout = new QVBoxLayout;

    selectHLayout->addSpacerItem(new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum)); // Add spacer at the beginning
    selectHLayout->addWidget(selectAdj);
    selectHLayout->addWidget(selectGoBack);

    selectVLayout->addWidget(introText,1);
    selectVLayout->addWidget(graphText,2);
    selectVLayout->addWidget(introCycle,3);
    selectVLayout->addWidget(cycleText,4);
    selectVLayout->addWidget(introMST,5);
    selectVLayout->addWidget(mstText,6);
    selectVLayout->addWidget(introDijk,7);
    selectVLayout->addWidget(dijkText,8);
    selectVLayout->addWidget(introPrim,9);
    selectVLayout->addWidget(primText,10);
    selectVLayout->addWidget(introFindCycle,11);
    selectVLayout->addWidget(findCycleText,12);

    selectVLayout->addLayout(selectHLayout,13);
    
    setLayout(selectVLayout);
}