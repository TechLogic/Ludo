#ifndef FIGURE_H
#define FIGURE_H

class Figure : public QGraphicsView
{
public:
    Figure(QObject *parent);
    move(int value);
private:
    const Player* player;
    Field* currentPos;
};

#endif // FIGURE_H
