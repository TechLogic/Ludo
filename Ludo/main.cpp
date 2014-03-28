#include "ludo.h"
#include <QApplication>
#include "map.h"
#include <QObject>
#include "player.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QObject parent;
    QApplication a(argc, argv);
    QWidget w;
    Map p(&parent);
    w.setMinimumSize(500,500);
    w.setWindowTitle(
    QApplication::translate("Ludo", "Ludo"));
    QGridLayout *layout=p.createMap();
    Player pl(&parent);
    Figure * f=p.getFigure(&pl);
    Field * fi=p.getStartField();
    std::cout<<"main::  "<<fi->text.toStdString()<<std::endl;

    fi->setFigure(f);
    w.setLayout(layout);
    std::cout<<"show::  "<<fi->text.toStdString()<<std::endl;
    w.show();
    f->setPosition(fi);

    f->move(5);
    
    return a.exec();
}
