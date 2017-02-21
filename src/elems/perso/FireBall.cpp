//
// FireBall.cpp for Fire in /home/rebut_p/Programmation/CPP/cpp_indie_studio
//
// Made by Pierre Rebut
// Login   <rebut_p@epitech.net>
//
// Started on  Fri May 27 16:24:15 2016 Pierre Rebut
// Last update Sun Jun  5 22:22:55 2016 Lucas Parsy
//

#include	"FireBall.hpp"

FireBall::FireBall(void *player, Ogre::SceneManager *sceneMgr,
		   CollisionTools *colliders)
{
  _colliderBool = true;
  _player = player;
  _node = NULL;
  _name = "fireball";
  _file = "fire.mesh";
  _anim = NULL;
  _enable = false;
  _object = sceneMgr->createEntity(_name, _file);
  _node = sceneMgr->getRootSceneNode()->createChildSceneNode();
  _node->attachObject(_object);
  _node->setScale(30,30,30);
  _object->setVisible(false);
  _node->setPosition(Ogre::Vector3(-500, 0, 0));
  _collider = colliders;
  _sceneMgr = sceneMgr;
  if (colliders != NULL)
    colliders->add_entity(this);
  _dmg = 50;
  _vitesse = 800;
  _type = ADrawable::SHOT;
}

FireBall::~FireBall()
{
  _collider->delete_entity(this);
}
