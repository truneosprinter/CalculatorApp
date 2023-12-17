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

private:
    Ui::CalculatorApp *ui;
};
#endif // CALCULATORAPP_H
