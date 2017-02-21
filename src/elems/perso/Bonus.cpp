//
// Bonus.cpp for  in /home/pavot_m/cpp_indie_studio/src/elems/perso
//
// Made by Maxime Pavot
// Login   <pavot_m@epitech.net>
//
// Started on  Sat Jun  4 13:20:46 2016 Maxime Pavot
// Last update Sun Jun  5 18:48:51 2016 Pierre Rebut
//

#include "Bonus.hpp"

void		APickable::popObject(const Ogre::Vector3 &pos)
{
  if (_enable == false)
    {
      _position = pos;
      _position.y = 10;
      _node->setPosition(_position);
      _enable = true;
      _object->setVisible(true);
    }
}

Bonus::Bonus(const int name, Ogre::SceneManager *scene, CollisionTools *col)
{
  _enable = false;
  _colliderBool = true;
  _name = "bonus_food_" + std::to_string(name);
  _file = "food_plate.mesh";
  _type = ADrawable::BONUS;
  _position = Ogre::Vector3(-500, 0, 0);
  _rotation = Ogre::Vector3::ZERO;
  _scale = Ogre::Vector3(100,100,100);
  createObject(scene, col);
  _object->setVisible(false);
}

Bonus::~Bonus()
{
}

bool		Bonus::docollide(ADrawable::type type)
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

void		Bonus::catchitem(AEntity *player)
{
  size_t new_pv = player->getPV() + 30;
  if (new_pv > 100)
    player->setPv(100);
  else
    player->setPv(new_pv);
  _node->setPosition(Ogre::Vector3(-500, 0, 0));
  _object->setVisible(false);
  _enable = false;
}
