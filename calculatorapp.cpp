#include "calculatorapp.h"
#include "./ui_calculatorapp.h"

CalculatorApp::CalculatorApp(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CalculatorApp)
{
    ui->setupUi(this);
}

CalculatorApp::~CalculatorApp()
{
    delete ui;
}
