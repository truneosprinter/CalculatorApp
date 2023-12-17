// calculatorapp.h
#ifndef CALCULATORAPP_H
#define CALCULATORAPP_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class CalculatorApp;
}
QT_END_NAMESPACE

class CalculatorApp : public QMainWindow
{
    Q_OBJECT

public:
    CalculatorApp(QWidget *parent = nullptr);
    ~CalculatorApp();

private slots:
    // Function to handle digit button clicks
    void digitClicked();

    // Function to handle operator button clicks
    void operatorClicked();

    // Function to handle equal button click
    void equalClicked();

    // Function to clear the display
    void clearDisplay();

private:
    Ui::CalculatorApp *ui;

    QString currentInput;
    QString pendingOperator;
    double result;

    // Function to update the display with the current input
    void updateDisplay();
};

#endif // CALCULATORAPP_H
