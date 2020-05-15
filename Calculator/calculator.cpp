#include "calculator.h"
#include "ui_calculator.h"

double value = 0.0;
bool divTrigger = false;
bool multTrigger = false;
bool addTrigger = false;
bool subTrigger = false;

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);

    ui->Screen->setText(QString::number(value));
    QPushButton *numButtons[10];
    for(int i = 0; i < 10; i++){
        QString butName = "Button" + QString::number(i);
        numButtons[i] = Calculator::findChild<QPushButton *>(butName);
        connect(numButtons[i], SIGNAL(released()), this,
                SLOT(NumPressed()));
    }
    connect(ui->Add, SIGNAL(released()), this,
                SLOT(MathButtonPressed()));
    connect(ui->Subtract, SIGNAL(released()), this,
                SLOT(MathButtonPressed()));
    connect(ui->Multiply, SIGNAL(released()), this,
                SLOT(MathButtonPressed()));
    connect(ui->Divide, SIGNAL(released()), this,
                SLOT(MathButtonPressed()));

    connect(ui->Equal, SIGNAL(released()), this,
                SLOT(EqualButtonPressed()));

    connect(ui->ChangeSign, SIGNAL(released()), this,
                SLOT(ChangeNumberSign()));

    connect(ui->Clear, SIGNAL(released()), this,
                SLOT(ClearNumberPressed()));
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::NumPressed(){
    QPushButton *button = (QPushButton *)sender();

    QString butVal = button->text();

    QString value = ui->Screen->text();

    if ((value.toDouble()== 0) || (value.toDouble()==0.0)){
        ui->Screen->setText(butVal);
    } else {
        QString NewVal = value + butVal;
        double dbNewVal = NewVal.toDouble();
        ui->Screen->setText(QString::number(dbNewVal, 'g', 16));
    }
}

void Calculator::MathButtonPressed(){
    divTrigger = false;
    multTrigger = false;
    addTrigger = false;
    subTrigger = false;

    QString displayVal = ui->Screen->text();
    value = displayVal.toDouble();

    QPushButton *button = (QPushButton *)sender();

    QString butVal = button->text();

    if(QString::compare(butVal, "/", Qt::CaseInsensitive) == 0){
        divTrigger = true;
    } else if(QString::compare(butVal, "*", Qt::CaseInsensitive) == 0){
        multTrigger = true;
    } else if(QString::compare(butVal, "+", Qt::CaseInsensitive) == 0){
        addTrigger = true;
    } else {
        subTrigger = true;
    }

    ui->Screen->setText("");
}

void Calculator::EqualButton(){

    double solution = 0.0;

    QString displayVal = ui->Screen->text();
    double dbDisplayVal = displayVal.toDouble();

    if(addTrigger || subTrigger || multTrigger || divTrigger ){
        if(addTrigger){
            solution = value + dbDisplayVal;
        } else if(subTrigger){
            solution = value - dbDisplayVal;
        } else if(multTrigger){
            solution = value * dbDisplayVal;
        } else {
            solution = value / dbDisplayVal;
        }
    }

    ui->Screen->setText(QString::number(solution));

}

void Calculator::ChangeNumberSign(){

    QString displayVal = ui->Screen->text();

    QRegExp reg("[-+]?[0-9.]*");

    if(reg.exactMatch(displayVal)){
        double dblDisplayVal = displayVal.toDouble();
        double dblDisplayValSign = -1 * dblDisplayVal;

        ui->Screen->setText(QString::number(dblDisplayValSign));
    }

}


void Calculator::ClearButtonPressed(){
     ui->Screen->setText(QString::number(0.0));
     QString dispayVal = ui->Screen->text();
}
