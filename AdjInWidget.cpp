#include "AdjInWidget.h"
#include <QIntValidator>
#include <QRegExpValidator>
#include <QMessageBox>
#include <QPalette>

AdjInWidget::AdjInWidget(QWidget *parent)
    : QWidget(parent)
{
    setAutoFillBackground(true);

    QPalette palette = this->palette();
    palette.setColor(QPalette::Window, QColor("#1D4A59"));
    setPalette(palette);

    hlay1 = new QHBoxLayout;
    hlay2 = new QHBoxLayout;
    hlay3 = new QHBoxLayout;
    hlay4 = new QHBoxLayout;

    //dnel center
    adjLabel = new QLabel("                 Input your adjacency matrix in this widget! ");

    adjLabel->setStyleSheet("QLabel {"
                            "  color: white;"
                            "  font-size: 25pt;"
                            "  font-weight: bold;"
                            "  font-family: 'Courier New';"
                            "  padding: 10px;"
                            "  background-color: #1D4A59;"
                            "  text-align: center;"  // Dark shade for contrast
                            "}");

    rowsLabel = new QLabel("Rows: ");

    rowsLabel->setStyleSheet("QLabel {"
                            "  color: white;"
                            "  font-size: 10pt;"
                            "  font-weight: bold;"
                            "  font-family: 'Courier New';"
                            "  padding: 10px;"
                            "  background-color: #1D4A59;"  // Dark shade for contrast
                            "}"); 

    colLabel = new QLabel("Columns: ");

    colLabel->setStyleSheet("QLabel {"
                            "  color: white;"
                            "  font-size: 10pt;"
                            "  font-weight: bold;"
                            "  font-family: 'Courier New';"
                            "  padding: 10px;"
                            "  background-color: #1D4A59;"  // Dark shade for contrast
                            "}"); 

    enablePrim = new QLabel("Prim's Algorithm ");

    enablePrim->setStyleSheet("QLabel {"
                            "  color: white;"
                            "  font-size: 10pt;"
                            "  font-weight: bold;"
                            "  font-family: 'Courier New';"
                            "  padding: 10px;"
                            "  background-color: #1D4A59;"  // Dark shade for contrast
                            "}");

    srcDestLabel = new QLabel("<br>Dijkstra's Algorithm ");

    srcDestLabel->setStyleSheet("QLabel {"
                            "  color: white;"
                            "  font-size: 10pt;"
                            "  font-weight: bold;"
                            "  font-family: 'Courier New';"
                            "  padding: 10px;"
                            "  background-color: #1D4A59;"  // Dark shade for contrast
                            "}");

    adjInput = new QLabel("Adjacency Matrix"
                        "<br><br>An adjacency matrix is a square matrix used to represent a finite graph."
                        "<br>The elements of the matrix indicate whether pairs of vertices are adjacent or not in the graph. ");

    adjInput->setStyleSheet("QLabel {"
                            "  color: white;"
                            "  font-size: 10pt;"
                            "  font-weight: bold;"
                            "  font-family: 'Courier New';"
                            "  padding: 10px;"
                            "  background-color: #1D4A59;"  // Dark shade for contrast
                            "}");

    adjGoHome = new QToolButton;
    adjGoSelect = new QToolButton;

    checkPrim = new QCheckBox("Prim's Algorithm",this);
    checkPrim->setStyleSheet("QCheckBox {"
                            "  color: white;"
                            "  font-size: 10pt;"
                            "  font-weight: bold;"
                            "  font-family: 'Courier New';"
                            "  padding: 10px;"
                            "  background-color: #1D4A59;"  // Dark shade for contrast
                            "}");
    checkPrim->setChecked(false);

    adjRowsInput = new QLineEdit(this);
    adjColumnsInput = new QLineEdit(this);

    adjSource = new QLineEdit("Source");
    adjSource->setFixedSize(100, 30);
    adjDest = new QLineEdit("Destination");
    adjDest->setFixedSize(100, 30);

    adjRowsInput->setValidator(new QIntValidator(1, 100, this)); // Limits to positive integers
    adjRowsInput->setFixedSize(100, 20);
    adjColumnsInput->setValidator(new QIntValidator(1, 100, this));
    adjColumnsInput->setFixedSize(100, 20);

    adjUpdateButton = new QToolButton;
    enterAdjMat = new QToolButton;
    adjMatrixLayout = new QGridLayout();
    auto *adjLayout = new QVBoxLayout(this);

    adjGoHome->setIcon(QIcon("Icons/home.png"));
    adjGoHome->setIconSize(QSize(40, 40));
    adjGoHome->setAutoRaise(true);
    adjGoHome->setToolTip("Go Home Page");
    adjGoHome->setStyleSheet("QToolButton { border: none; }");
    
    adjGoSelect->setIcon(QIcon("Icons/information.png"));
    adjGoSelect->setIconSize(QSize(50, 50));
    adjGoSelect->setAutoRaise(true);
    adjGoSelect->setToolTip("Go To Information Page");
    adjGoSelect->setStyleSheet("QToolButton { border: none; }");

    adjUpdateButton->setIcon(QIcon("Icons/refresh.png"));
    adjUpdateButton->setIconSize(QSize(60, 60));
    adjUpdateButton->setAutoRaise(true);
    adjUpdateButton->setToolTip("Create Matrix");
    adjUpdateButton->setStyleSheet("QToolButton { border: none; }");

    enterAdjMat->setIcon(QIcon("Icons/data-flow.png"));
    enterAdjMat->setIconSize(QSize(60, 60));
    enterAdjMat->setAutoRaise(true);
    enterAdjMat->setToolTip("Visualize Matrix");
    enterAdjMat->setStyleSheet("QToolButton { border: none; }");

    hlay1->addWidget(adjLabel,1);
    hlay1->addWidget(adjGoHome,2);
    hlay1->addWidget(adjGoSelect,3);

    hlay2->addWidget(adjSource);
    hlay2->addWidget(adjDest);
    hlay2->addWidget(srcDestLabel);
    QSpacerItem *spacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    hlay2->addSpacerItem(spacer); // Add spacer to the end to push everything to the left

    
    hlay3->addWidget(checkPrim);
    //hlay3->addWidget(enablePrim);
    QSpacerItem *spacerCheck = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    hlay3->addSpacerItem(spacerCheck); // Add spacer to the end to push everything to the left

    hlay4->addSpacerItem(new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum)); // Add spacer at the beginning
    hlay4->addWidget(adjUpdateButton, 1);
    hlay4->addWidget(enterAdjMat, 2);


    adjLayout->addLayout(hlay1,1);
    adjLayout->addLayout(hlay3,2);
    adjLayout->addLayout(hlay2,3);
    adjLayout->addWidget(rowsLabel,5);
    adjLayout->addWidget(adjRowsInput,6);
    adjLayout->addWidget(colLabel,7);
    adjLayout->addWidget(adjColumnsInput,8);
    adjLayout->addLayout(adjMatrixLayout,9);
    adjLayout->addLayout(hlay4,10);


    connect(adjUpdateButton, &QPushButton::clicked, this, &AdjInWidget::updateAdjMatrix);
    //connect(checkPrim, SIGNAL(isChecked()), this, SLOT(updateMatrixSymmetry));
    setLayout(adjLayout);
}

void AdjInWidget::updateAdjMatrix()
{
    bool rowsOk, colsOk;
    int rows = adjRowsInput->text().toInt(&rowsOk);
    int columns = adjColumnsInput->text().toInt(&colsOk);

    if (rowsOk && colsOk) {
        clearAdjMatrix();
        createAdjMatrix(rows, columns); 
    } 
}


void AdjInWidget::createAdjMatrix(int adjRows, int adjColumns)
{
    adjMatrixInputs.resize(adjRows, std::vector<QLineEdit*>(adjColumns, nullptr));


    for (int i = 0; i < adjRows; ++i) {
        QLabel* vertexRow = new QLabel(QString("V%1").arg(i+1));

        vertexRow->setStyleSheet("QLabel {"
                            "  color: white;"
                            "  font-size: 10pt;"
                            "  font-weight: bold;"
                            "  font-family: 'Courier New';"
                            "  padding: 10px;"
                            "  background-color: #1D4A59;"  // Dark shade for contrast
                            "}");
        adjMatrixLayout->addWidget(vertexRow, i + 1, 0);
        for (int j = 0; j < adjColumns; ++j) {
            if (i == 0) {
                QLabel* vertexCol = new QLabel(QString("V%1").arg(j+1));

                vertexCol->setStyleSheet("QLabel {"
                            "  color: white;"
                            "  font-size: 10pt;"
                            "  font-weight: bold;"
                            "  font-family: 'Courier New';"
                            "  padding: 10px;"
                            "  background-color: #1D4A59;"  // Dark shade for contrast
                            "}");
                
                adjMatrixLayout->addWidget(vertexCol, 0, j + 1);
            }
            QLineEdit *input = new QLineEdit(this);
            input->setFixedSize(40,40);
            
            adjMatrixLayout->addWidget(input, i + 1, j + 1);
            adjMatrixInputs[i][j] = input;
        }
    }
    adjMatrixLayout->setColumnStretch(adjColumns + 1, 1);
    adjMatrixLayout->setRowStretch(adjRows + 1, 1);
}

QVector<QVector<int>> AdjInWidget::getAdjMatrix() const {
    QVector<QVector<int>> matrix;
    for (const auto &row : adjMatrixInputs) {
        QVector<int> matrixRow;
        for (const auto &input : row) {
            matrixRow.push_back(input->text().toInt());
        }
        matrix.push_back(matrixRow);
    }
    return matrix;
}

//WRONG
void AdjInWidget::clearAdjMatrix()
{
    QLayoutItem *item;
    while ((item = adjMatrixLayout->takeAt(0)) != nullptr) {
        delete item->widget(); // Delete the widget
        delete item; // Delete the layout item
    }
}

bool AdjInWidget::isMatrixSymmetric(const QVector<QVector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = i + 1; j < matrix.size(); ++j) {  // Only need to check entries above the diagonal
            if (matrix[i][j] != matrix[j][i]) {
                return false;  // If any asymmetric pair is found, the matrix is not symmetric
            }
        }
    }
    return true;  // If no asymmetric pairs are found, the matrix is symmetric
}

bool AdjInWidget::isCheckboxChecked() {
    QCheckBox *checkbox = findChild<QCheckBox*>("checkPrim");
    if (checkbox) {
        return checkbox->isChecked();
    }
    return false; // Return false if checkbox is not found
}
