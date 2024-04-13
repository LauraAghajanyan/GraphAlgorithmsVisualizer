#include "IncInWidget.h"

IncInWidget::IncInWidget(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *incMainLayout = new QVBoxLayout(this);
    incNumVerticesInput = new QLineEdit(this);
    generateIncMatrixBut = new QPushButton("Generate Matrix", this);
    incMatrixLayout = new QGridLayout();

    incLabel = new QLabel("Incidence Matrix Input widget");
    incLayout = new QVBoxLayout;
    incGoHome = new QPushButton("Home");
    incGoSelect = new QPushButton("Go back");
    enterIncMatrix = new QPushButton("Enter");

    incLayout->addWidget(incLabel);
    incLayout->addWidget(incGoHome);
    incLayout->addWidget(incGoSelect);

    incMainLayout->addWidget(new QLabel("Number of vertices:"));
    incMainLayout->addWidget(incNumVerticesInput);
    incMainLayout->addWidget(generateIncMatrixBut);
    incMainLayout->addLayout(incMatrixLayout);
    incMainLayout->addWidget(enterIncMatrix);

    connect(generateIncMatrixBut, &QPushButton::clicked, this, &IncInWidget::generateIncMatrix);

    setLayout(incLayout);
}

void IncInWidget::clearIncMatrix() {
    // Delete and remove vertex labels
    for (auto *label : incVertexLabels) {
        incMatrixLayout->removeWidget(label);
        delete label;
    }
    incVertexLabels.clear();

    // Delete and remove edge labels
    for (auto *label : incEdgeLabels) {
        incMatrixLayout->removeWidget(label);
        delete label;
    }
    incEdgeLabels.clear();

    // Delete and remove matrix inputs
    for (auto &row : incMatrixInputs) {
        for (auto *input : row) {
            incMatrixLayout->removeWidget(input);
            delete input;
        }
    }
    incMatrixInputs.clear();

    // This extra step ensures that any leftover widgets are also removed
    QLayoutItem *item;
    while ((item = incMatrixLayout->takeAt(0)) != nullptr) {
        if (item->widget()) {
            delete item->widget();
        }
        delete item;
    }
}

void IncInWidget::generateIncMatrix() {
    clearIncMatrix(); // Assume implementation clears the existing matrix UI

    int vertices = incNumVerticesInput->text().toInt();
    int edges = vertices * (vertices - 1) / 2; // Calculate possible edges

    // Prepare validators for matrix inputs
    QRegExpValidator *validator = new QRegExpValidator(QRegExp("[01]"), this);

    // Generate labels and input fields
    for (int i = 0; i < vertices; i++) {
        incVertexLabels.push_back(new QLabel(QString("V%1").arg(i + 1)));
        incMatrixLayout->addWidget(incVertexLabels.back(), i + 1, 0);
    }

    for (int j = 0; j < edges; j++) {
        incEdgeLabels.push_back(new QLabel(QString("E%1").arg(j + 1)));
        incMatrixLayout->addWidget(incEdgeLabels.back(), vertices + 1, j + 1);
    }

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < edges; j++) {
            QLineEdit* input = new QLineEdit(this);
            input->setValidator(validator);
            connect(input, &QLineEdit::textEdited, this, &IncInWidget::validateInput);
            incMatrixLayout->addWidget(input, i + 1, j + 1);
            if (incMatrixInputs.size() <= i) {
                incMatrixInputs.push_back(QVector<QLineEdit*>());
            }
            incMatrixInputs[i].push_back(input);
        }
    }
}

void IncInWidget::validateInput(const QString &text) {
    if (text.isEmpty()) return; // Ignore empty strings, assuming deletion is taking place

    // Check if the text is not '0' or '1'
    if (text != "0" && text != "1") {
        QMessageBox::warning(this, "Invalid Input", "Invalid Input, only 1 and 0 are allowed");
        // Optionally, revert the input to a valid state or clear the invalid input
    }
}

/*void IncInWidget::storeMatrix() {
    incidenceMatrix.resize(incVertexLabels.size());
    for (int i = 0; i < incidenceMatrix.size(); ++i) {
        incidenceMatrix[i].resize(incEdgeLabels.size());
        for (int j = 0; j < incEdgeLabels.size(); ++j) {
            incidenceMatrix[i][j] = incMatrixInputs[i][j]->text().toInt();
        }
    }
}*/
