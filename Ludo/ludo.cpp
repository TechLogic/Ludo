#include "ludo.h"
#include "ui_ludo.h"

Ludo::Ludo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Ludo)
{
    ui->setupUi(this);
}

Ludo::~Ludo()
{
    delete ui;
}
