//
// Malus.cpp for  in /home/pavot_m/cpp_indie_studio/src/elems/perso
//
// Made by Maxime Pavot
// Login   <pavot_m@epitech.net>
//
// Started on  Sat Jun  4 13:20:46 2016 Maxime Pavot
// Last update Sun Jun  5 18:49:05 2016 Pierre Rebut
//

#include "Malus.hpp"

Malus::Malus(const int name, Ogre::SceneManager *scene, CollisionTools *col)
{
  _enable = false;
  _colliderBool = true;
  _name = "Malus_food_" + std::to_string(name);
  _file = "food_pot.mesh";
  _type = ADrawable::BONUS;
  _position = Ogre::Vector3(-500, 0, 0);
  _rotation = Ogre::Vector3::ZERO;
  _scale = Ogre::Vector3(100,100,100);
  createObject(scene, col);
  _object->setVisible(false);
}

Malus::~Malus()
{
}

bool		Malus::docollide(ADrawable::type type)
{
  switch (type)
    {
    case ADrawable::SHOT:
    case ADrawable::WALL:
    case ADrawable::ENEMY:
    case ADrawable::BONUS:
      return (false);
    default:
      return (true);
    }
}

void		Malus::catchitem(AEntity *player)
{
  if (player->getPV() <= 30)
    player->setPv(0);
  else
    player->setPv(player->getPV() - 30);
  _node->setPosition(Ogre::Vector3(-500, 0, 0));
  _object->setVisible(false);
  _enable = false;
}
