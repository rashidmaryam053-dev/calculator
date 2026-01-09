
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QChar>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString currentInput;
    double firstNumber = 0;
    QChar currentOperator;

private slots:
    void appendNumber(const QString &number);
    void setOperator(QChar op);
    void calculateResult();
    void clearAll();
};

#endif // MAINWINDOW_H
