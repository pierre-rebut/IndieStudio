//
// Enemy.cpp for Enemy in /home/rebut_p/Programmation/CPP/cpp_indie_studio/ogre/src/elems/perso
//
// Made by Pierre Rebut
// Login   <rebut_p@epitech.net>
//
// Started on  Wed May 11 16:35:02 2016 Pierre Rebut
// Last update Sun Jun  5 23:38:55 2016 Pierre Rebut
//

#include	<cmath>

#include	"Enemy.hpp"

Enemy::Enemy(const std::string &name, const std::string &file, const std::string &script,
	     Ogre::SceneManager *sceneMgr, CollisionTools *colliders, std::vector<ACharacter*> *lstPlayer)
{
  _lstPlayer = lstPlayer;
  _colliderBool = true;
  _name = name;
  _file = file;
  _frameId = 0;
  _rotation = Ogre::Vector3(0,0,0);
  _vitesse = 250;
  _vitesseRotate = 0.8;
  _enable = false;
  _object = sceneMgr->createEntity(_name, _file);
  _node = sceneMgr->getRootSceneNode()->createChildSceneNode(_name + "_node");
  _node->attachObject(_object);
  _node->setScale(0.7,0.7,0.7);
  _node->setPosition(Ogre::Vector3(-500, 0, 0));
  _object->setVisible(false);
  _collider = colliders;
  if (colliders != NULL)
    colliders->add_entity(this);
  _dmg = 20;
  _sceneMgr = sceneMgr;
  _pv = 0;
  createAnimation("Walk");
  _type = ADrawable::ENEMY;
}

Enemy::~Enemy()
{
  _collider->delete_entity(this);
}

Ogre::Vector3	Enemy::focusPlayer(void)
{
  int				prox_P;
  int				prox_IA;
  Ogre::Vector3			pos;
  int				i = 0;
  int				result = 0;
  int				index_player;

  for (auto it = _lstPlayer->begin(); it != _lstPlayer->end(); ++it)
    {
      pos = (*it)->getPosition();
      prox_P = abs(pos.x + pos.z);
      prox_IA = abs(_position.x + _position.z);
      if (result == 0 or result > abs(prox_P + prox_IA))
	{
	  result = abs(prox_P + prox_IA);
	  index_player = i;
	}
      i++;
    }
  return (_lstPlayer->at(index_player)->getPosition());
}

bool		Enemy::execOneFrame(const Ogre::FrameEvent &evt)
{
  if (_pv == 0)
    {
      _object->setVisible(false);
      _enable = false;
      return false;
    }
  Ogre::Real	mMouv = _vitesse * evt.timeSinceLastFrame;
  Ogre::Vector3 deplacement = Ogre::Vector3::ZERO;

  deplacement.z -= mMouv;
  if (_frameId == 10)
    {
      _node->lookAt(focusPlayer(), Ogre::Node::TS_PARENT, Ogre::Vector3::NEGATIVE_UNIT_Z);
      _frameId = 0;
    }
  if (move(deplacement) == true && _anim != NULL)
    {
      setAnimationFrame(evt.timeSinceLastFrame);
      setAnimationEnable(true);
    }
  else if (_anim != NULL)
    setAnimationEnable(false);
  _frameId ++;
  return (true);
}
