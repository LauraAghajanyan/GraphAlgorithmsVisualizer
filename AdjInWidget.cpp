#include "AdjInWidget.h"
#include <QIntValidator>
#include <QRegExpValidator>
#include <QMessageBox>

AdjInWidget::AdjInWidget(QWidget *parent)
    : QWidget(parent)
{
    adjLabel = new QLabel("Adjacency Matrix Input widget");
    adjGoHome = new QPushButton("Home");
    adjGoSelect = new QPushButton("Go back");
    

    adjRowsInput = new QLineEdit(this);
    adjColumnsInput = new QLineEdit(this);

    adjRowsInput->setValidator(new QIntValidator(1, 100, this)); // Limits to positive integers
    adjColumnsInput->setValidator(new QIntValidator(1, 100, this));

    adjUpdateButton = new QPushButton("Update Matrix");
    enterAdjMat = new QPushButton("Enter");
    adjMatrixLayout = new QGridLayout();
    auto *adjLayout = new QVBoxLayout(this);

    adjLayout->addWidget(adjGoHome);
    adjLayout->addWidget(adjGoSelect);
    adjLayout->addWidget(adjLabel);
    adjLayout->addWidget(new QLabel("Rows:"));
    adjLayout->addWidget(adjRowsInput);
    adjLayout->addWidget(new QLabel("Columns:"));
    adjLayout->addWidget(adjColumnsInput);
    adjLayout->addWidget(adjUpdateButton);

    adjLayout->addLayout(adjMatrixLayout);
    adjLayout->addWidget(enterAdjMat);


    connect(adjUpdateButton, &QPushButton::clicked, this, &AdjInWidget::updateAdjMatrix);
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
    QRegExpValidator *validator = new QRegExpValidator(QRegExp("[01]"), this);

    for (int i = 0; i < adjRows; ++i) {
        adjMatrixLayout->addWidget(new QLabel(QString("V%1").arg(i + 1)), i + 1, 0);
        for (int j = 0; j < adjColumns; ++j) {
            if (i == 0) {
                adjMatrixLayout->addWidget(new QLabel(QString("V%1").arg(j + 1)), 0, j + 1);
            }
            QLineEdit *input = new QLineEdit(this);
            input->setValidator(validator);
            adjMatrixLayout->addWidget(input, i + 1, j + 1);
            adjMatrixInputs[i][j] = input;
            
        }
    }
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

void AdjInWidget::clearAdjMatrix()
{
    QLayoutItem *item;
    while ((item = adjMatrixLayout->takeAt(0)) != nullptr) {
        delete item->widget(); // Delete the widget
        delete item; // Delete the layout item
    }
}

