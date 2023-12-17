// calculatorapp.cpp
#include "calculatorapp.h"
#include "./ui_calculatorapp.h"

CalculatorApp::CalculatorApp(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::CalculatorApp)
{
    ui->setupUi(this);

    // Connect digit buttons to the digitClicked slot
    connect(ui->btn_0, &QPushButton::clicked, this, &CalculatorApp::digitClicked);
    connect(ui->btn_1, &QPushButton::clicked, this, &CalculatorApp::digitClicked);
    connect(ui->btn_2, &QPushButton::clicked, this, &CalculatorApp::digitClicked);
    connect(ui->btn_3, &QPushButton::clicked, this, &CalculatorApp::digitClicked);
    connect(ui->btn_4, &QPushButton::clicked, this, &CalculatorApp::digitClicked);
    connect(ui->btn_5, &QPushButton::clicked, this, &CalculatorApp::digitClicked);
    connect(ui->btn_6, &QPushButton::clicked, this, &CalculatorApp::digitClicked);
    connect(ui->btn_7, &QPushButton::clicked, this, &CalculatorApp::digitClicked);
    connect(ui->btn_8, &QPushButton::clicked, this, &CalculatorApp::digitClicked);
    connect(ui->btn_9, &QPushButton::clicked, this, &CalculatorApp::digitClicked);

    // Connect operator buttons to the operatorClicked slot
    connect(ui->btn_plus, &QPushButton::clicked, this, &CalculatorApp::operatorClicked);
    connect(ui->btn_minus, &QPushButton::clicked, this, &CalculatorApp::operatorClicked);
    connect(ui->btn_multiply, &QPushButton::clicked, this, &CalculatorApp::operatorClicked);
    connect(ui->btn_divide, &QPushButton::clicked, this, &CalculatorApp::operatorClicked);

    // Connect equal button to the equalClicked slot
    connect(ui->btn_equal, &QPushButton::clicked, this, &CalculatorApp::equalClicked);

    // Connect clear button to the clearDisplay slot
    connect(ui->btn_clear, &QPushButton::clicked, this, &CalculatorApp::clearDisplay);

    // Initialize variables
    currentInput = "";
    pendingOperator = "";
    result = 0.0;

    // Update the display initially
    updateDisplay();
}

CalculatorApp::~CalculatorApp()
{
    delete ui;
}

void CalculatorApp::digitClicked()
{
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    if (clickedButton) {
        // Append the clicked digit to the current input
        currentInput += clickedButton->text();
        updateDisplay();
    }
}

void CalculatorApp::operatorClicked()
{
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    if (clickedButton) {
        // Save the pending operator and the current input as the first operand
        pendingOperator = clickedButton->text();
        result = currentInput.toDouble();
        currentInput = "";
    }
}

void CalculatorApp::equalClicked()
{
    // Calculate the result based on the pending operator and the second operand
    if (!pendingOperator.isEmpty()) {
        double secondOperand = currentInput.toDouble();
        if (pendingOperator == "+") {
            result += secondOperand;
        } else if (pendingOperator == "-") {
            result -= secondOperand;
        } else if (pendingOperator == "*") {
            result *= secondOperand;
        } else if (pendingOperator == "/") {
            // Check for division by zero
            if (secondOperand != 0.0) {
                result /= secondOperand;
            } else {
                // Handle division by zero error
                // For now, clear the display and reset the calculator
                clearDisplay();
                ui->label->setText("Syntax Error");
                return;
            }
        }

        // Clear the pending operator
        pendingOperator = "";

        // Update the current input with the result
        currentInput = QString::number(result);
        updateDisplay();
    }
}

void CalculatorApp::clearDisplay()
{
    // Clear all input and reset variables
    currentInput = "";
    pendingOperator = "";
    result = 0.0;
    updateDisplay();
}

void CalculatorApp::updateDisplay()
{
    // Update the display with the current input
    ui->label->setText(currentInput);
}
