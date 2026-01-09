
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Number buttons
    connect(ui->pushButton,   &QPushButton::clicked, this, [=]() { appendNumber("1"); });
    connect(ui->pushButton_2, &QPushButton::clicked, this, [=]() { appendNumber("2"); });
    connect(ui->pushButton_3, &QPushButton::clicked, this, [=]() { appendNumber("3"); });
    connect(ui->pushButton_4, &QPushButton::clicked, this, [=]() { appendNumber("4"); });
    connect(ui->pushButton_5, &QPushButton::clicked, this, [=]() { appendNumber("5"); });
    connect(ui->pushButton_6, &QPushButton::clicked, this, [=]() { appendNumber("6"); });
    connect(ui->pushButton_7, &QPushButton::clicked, this, [=]() { appendNumber("7"); });
    connect(ui->pushButton_8, &QPushButton::clicked, this, [=]() { appendNumber("8"); });
    connect(ui->pushButton_9, &QPushButton::clicked, this, [=]() { appendNumber("9"); });
    connect(ui->pushButton_0, &QPushButton::clicked, this, [=]() { appendNumber("0"); });

    // Operator buttons
    connect(ui->pushButton_plus,     &QPushButton::clicked, this, [=]() { setOperator('+'); });
    connect(ui->pushButton_minus,    &QPushButton::clicked, this, [=]() { setOperator('-'); });
    connect(ui->pushButton_multiply, &QPushButton::clicked, this, [=]() { setOperator('*'); });
    connect(ui->pushButton_divide,   &QPushButton::clicked, this, [=]() { setOperator('/'); });

    // Equals & Clear
    connect(ui->pushButton_equal, &QPushButton::clicked, this, &MainWindow::calculateResult);
    connect(ui->pushButton_clear, &QPushButton::clicked, this, &MainWindow::clearAll);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::appendNumber(const QString &number)
{
    currentInput += number;
    ui->lineEdit->setText(currentInput);
}

void MainWindow::setOperator(QChar op)
{
    firstNumber = currentInput.toDouble();
    currentOperator = op;
    currentInput.clear();
}

void MainWindow::calculateResult()
{
    double secondNumber = currentInput.toDouble();
    double result = 0;

    switch (currentOperator.unicode()) {
    case '+': result = firstNumber + secondNumber; break;
    case '-': result = firstNumber - secondNumber; break;
    case '*': result = firstNumber * secondNumber; break;
    case '/':
        if (secondNumber != 0)
            result = firstNumber / secondNumber;
        else {
            ui->lineEdit->setText("Error");
            return;
        }
        break;
    }

    currentInput = QString::number(result);
    ui->lineEdit->setText(currentInput);
}

void MainWindow::clearAll()
{
    currentInput.clear();
    ui->lineEdit->clear();
    firstNumber = 0;
}
