//
// AEntity.cpp for Entity in /home/rebut_p/Programmation/CPP/cpp_indie_studio/ogre
//
// Made by Pierre Rebut
// Login   <rebut_p@epitech.net>
//
// Started on  Wed May 11 15:30:17 2016 Pierre Rebut
// Last update Sun Jun  5 18:51:40 2016 Pierre Rebut
//

#include	<iostream>
#include	"Collision.hpp"
#include	"AEntity.hpp"
#include	"AEnemy.hpp"
#include	"APickable.hpp"

void	AEntity::addCollider(CollisionTools *colliders)
{
  _collider = colliders;
  _collider->add_entity(this);
}

bool	AEntity::move(const Ogre::Vector3 &vec, void *ignore)
{
  Ogre::Vector3 tmp;

  tmp = _node->getOrientation() * vec;
  _node->translate(tmp);
  CheckCollision ret = _collider->check_if_collide(this);
  if (!ret.collided)
    {
      _position += tmp;
      return (true);
    }
  _node->setPosition(_position);
  if (ret.entity->gettype() == ADrawable::ENEMY)
    {
      AEnemy *en = static_cast<AEnemy*>(ret.entity);
      setDamage(en->getDmg());
    }
  if (ret.entity->gettype() == ADrawable::BONUS)
    {
      APickable *en = static_cast<APickable*>(ret.entity);
      en->catchitem(this);
    }
  return (false);
}

bool	AEntity::rotate(const Ogre::Radian &y)
{
  _node->yaw(y);
  return (true);
}

size_t	AEntity::getPV() const
{
  return _pv;
}

size_t	AEntity::getDmg() const
{
  return _dmg;
}

void	AEntity::setDamage(const size_t dmg)
{
  if (dmg >= _pv)
    _pv = 0;
  else
    _pv -= dmg;
}

Ogre::Real	AEntity::getVitesse() const
{
  return _vitesse;
}

Ogre::Real	AEntity::getVitesseRotation() const
{
  return _vitesseRotate;
}

void	AEntity::createAnimation(const std::string &name)
{
  _anim = _object->getAnimationState(name);
  _anim->setLoop(true);
}

void	AEntity::setAnimationEnable(const bool val)
{
  _anim->setEnabled(val);
}

void	AEntity::setAnimationFrame(const Ogre::Real &time)
{
  _anim->addTime(time);
}

void	AEntity::setPv(const size_t pv)
{
  _pv = pv;
}

void	AEntity::setVitesse(const size_t vitesse)
{
  _vitesse = vitesse;
}

void	AEntity::setDmg(const size_t dmg)
{
  _dmg = dmg;
}
