#include "rng.h"
#include "ui_rng.h"
#include <QRandomGenerator>

double value = 0.0;

RNG::RNG(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RNG)
{
    ui->setupUi(this);

    ui->Screen->setText(QString::number(value));

    connect(ui->Button, SIGNAL(released()), this,
                SLOT(ButtonPushed()));
}

RNG::~RNG()
{
    delete ui;
}

void RNG::ButtonPushed(){
    quint32 value = QRandomGenerator::global()-> bounded(1, 11);
    ui->Screen->setText(QString::number(value));
};

