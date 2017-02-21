//
// ADrawable.cpp for cpp_indie_studio in /home/pavot_m/cpp_indie_studio
//
// Made by Maxime Pavot
// Login   <pavot_m@epitech.net>
//
// Started on  Fri Apr 29 15:32:22 2016 Maxime Pavot
// Last update Sun Jun  5 21:31:06 2016 Pierre Rebut
//

#include "Collision.hpp"
#include "ADrawable.hpp"

const std::string	&ADrawable::getName() const
{
  return _name;
}

void		ADrawable::setPosition(const Ogre::Vector3 &pos)
{
  _position = pos;
  _node->setPosition(pos);
}

bool		ADrawable::getEnable() const
{
  return _enable;
}

Ogre::Vector3	ADrawable::getPosition() const
{
  return _node->getPosition();
}

Ogre::Entity	*ADrawable::getEntity() const
{
  return _object;
}

Ogre::Quaternion ADrawable::getRotation() const
{
  return _node->getOrientation();
}

void	ADrawable::createObject(Ogre::SceneManager *sceneMgr,
				CollisionTools *colliders)
{
  Ogre::Entity *ent = sceneMgr->createEntity(_name, _file);
  Ogre::SceneNode *node = sceneMgr->getRootSceneNode()->createChildSceneNode();

  _object = ent;
  _node = node;
  _node->attachObject(ent);
  _node->pitch(Ogre::Degree(_rotation.z));
  _node->yaw(Ogre::Degree(_rotation.y));
  _node->roll(Ogre::Degree(_rotation.x));
  _node->setPosition(_position);
  _scale.x = (_scale.x == 0 ? 1 : _scale.x);
  _scale.y = (_scale.y == 0 ? 1 : _scale.y);
  _scale.z = (_scale.z == 0 ? 1 : _scale.z);
  _node->setScale(_scale.x, _scale.y, _scale.z);
  if (_colliderBool == true && colliders != NULL)
    {
      colliders->add_entity(this);
    }
}

ADrawable::type		ADrawable::gettype() const
{
  return _type;
}

void			ADrawable::destroyObject(Ogre::SceneManager *sceneMgr)
{
  sceneMgr->destroySceneNode(_node);
}
