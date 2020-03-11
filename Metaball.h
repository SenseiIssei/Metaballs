#ifndef METABALL_H
#define METABALL_H

#include <utility>
#include <QPoint>
#include <QSize>

struct Metaball
{
  std::size_t size = 0;

  QPoint
  position = {0,0},
  velocity = {0,0};

  inline void update(QSize border)
  {
      position += velocity;

      if(position.x() < 0) { position.setX(0); velocity.setX(velocity.x() * -1); }
      if(position.y() < 0) { position.setY(0); velocity.setY(velocity.y() * -1); }

      if(position.x() >= border.width()) { position.setX(border.width() - 1); velocity.setX(velocity.x() * -1); }
      if(position.y() >= border.width()) { position.setY(border.width() - 1); velocity.setY(velocity.y() * -1); }
  }
};

#endif // METABALL_H
