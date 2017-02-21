//
// AEnemy.cpp for AEnemy in /home/rebut_p/Programmation/CPP/cpp_indie_studio/ogre
//
// Made by Pierre Rebut
// Login   <rebut_p@epitech.net>
//
// Started on  Mon May 16 15:27:14 2016 Pierre Rebut
// Last update Sat Jun  4 13:44:02 2016 Pierre Rebut
//

#include	"AEnemy.hpp"
#include	"ACharacter.hpp"

bool	AEnemy::docollide(ADrawable::type type)
{
  switch (type)
    {
    case ADrawable::PLAYER:
      return (true);
    case ADrawable::ENEMY:
      return (false);
    case ADrawable::SHOT:
      return (true);
    case ADrawable::WALL:
      return (true);
    case ADrawable::BONUS:
      return (false);
    default:
      return (true);
    }
}

void	AEnemy::spawnEnemy(const Ogre::Vector3 &pos)
{
  if (_enable == false)
    {
      _enable = true;
      _object->setVisible(true);
      _position = pos;
      _node->setPosition(pos);
      _node->yaw(Ogre::Degree(0));
      _node->pitch(Ogre::Degree(0));
      _node->roll(Ogre::Degree(0));
      _pv = 100;
    }
}

bool	AEnemy::move(const Ogre::Vector3 &vec, void*)
{
  Ogre::Vector3	tmp;

  tmp = _node->getOrientation() * vec;
  _node->translate(tmp);
  CheckCollision ret = _collider->check_if_collide(this);
  if (!ret.collided)
    {
      _position += tmp;
      return (true);
    }
  _node->setPosition(_position);
  ACharacter *perso = dynamic_cast<ACharacter*>(ret.entity);
  if (perso != NULL)
    {
      perso->setDamage(_dmg);
      return (true);
    }
  return (false);
}
