//
// AAttack.cpp for AAttack in /home/rebut_p/Programmation/CPP/cpp_indie_studio
//
// Made by Pierre Rebut
// Login   <rebut_p@epitech.net>
//
// Started on  Fri May 27 15:27:47 2016 Pierre Rebut
// Last update Sun Jun  5 21:25:06 2016 Pierre Rebut
//

#include	<exception>
#include	<stdexcept>
#include	<iostream>
#include	"AAttack.hpp"
#include	"ACharacter.hpp"
#include	"AEntity.hpp"

bool	AAttack::docollide(ADrawable::type type)
{
  switch (type)
    {
    case ADrawable::PLAYER:
      return (false);
    case ADrawable::ENEMY:
      return (true);
    case ADrawable::SHOT:
      return (false);
    case ADrawable::WALL:
      return (true);
    case ADrawable::BONUS:
      return (false);
    default:
      return (true);
    }
}

void	AAttack::createAttack(const Ogre::Vector3 &pos,
			      const Ogre::Quaternion &rot)
{
  if (_enable == false)
    {
      _position = pos;
      _position.y = 100;
      _frame = 0;
      _node->setPosition(_position);
      _node->setOrientation(rot);
      _enable = true;
      _object->setVisible(true);
    }
}

void	AAttack::sendEvent(const Ogre::FrameEvent &evt)
{
  if (_enable == true)
    {
      Ogre::Vector3 deplacement(0,0,0);
      Ogre::Vector3 tmp = _position;

      _frame++;
      deplacement.z -= _vitesse * evt.timeSinceLastFrame;
      _node->translate(_node->getOrientation() * deplacement);
      tmp +=  _node->getOrientation() * deplacement;
      if (_anim != NULL)
	_anim->addTime(evt.timeSinceLastFrame);
      CheckCollision ret = _collider->check_if_collide(this);
      _position = tmp;
      if (ret.collided || _frame == 1000)
	{
	  _node->setPosition(Ogre::Vector3(-500,0,0));
	  _object->setVisible(false);
	  _enable = false;
	  if (ret.entity != NULL && ret.entity->gettype() == ADrawable::ENEMY)
	    {
	      AEntity *tmp = dynamic_cast<AEntity*>(ret.entity);
	      if (tmp != NULL)
		{
		  ACharacter *charac = static_cast<ACharacter*>(_player);
		  charac->setScore(charac->getScore() + 10);
		  tmp->setDamage(_dmg);
		}
	    }
	}
      _frameId = 1;
    }
}
