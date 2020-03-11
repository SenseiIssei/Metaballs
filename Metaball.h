#ifndef METABALL_H
#define METABALL_H

#include <utility>
#include <QPoint>
#include <QPointF>
#include <QSize>

struct Metaball
{
    QPointF position, velocity;
    std::size_t size;

    inline void update(QSize size, float speed)
    {
        position += velocity * speed;

        if (position.x() < 0) { position.setX(0); velocity.setX(velocity.x() * -1); }
        if (position.y() < 0) { position.setY(0); velocity.setY(velocity.y() * -1); }

        if (position.x() >= size.width()) { position.setX(size.width() - 1); velocity.setX(velocity.x() * -1); }
        if (position.y() >= size.height()) { position.setY(size.height() - 1); velocity.setY(velocity.y() * -1); }
    }
};

#endif // METABALL_H
