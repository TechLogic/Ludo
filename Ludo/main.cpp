#include "ludo.h"
#include <QApplication>
#include "map.h"
#include <QObject>

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
    w.setLayout(layout);

    w.show();
    
    return a.exec();
}
