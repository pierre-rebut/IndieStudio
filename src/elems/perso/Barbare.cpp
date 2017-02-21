//"
// Barbare.cpp for Barbare in /home/rebut_p/Programmation/CPP/cpp_indie_studio/ogre/src/elems/perso
//
// Made by Pierre Rebut
// Login   <rebut_p@epitech.net>
//
// Started on  Wed May 11 16:35:02 2016 Pierre Rebut
// Last update Thu Jun  9 13:01:21 2016 Pierre Rebut
//

#include	"Marteau.hpp"
#include	"Barbare.hpp"

Barbare::Barbare(Ogre::SceneManager *sceneMgr,
		 CollisionTools *colliders, const bool man)
{
  _manette = man;
  _enable = true;
  _colliderBool = true;
  _sceneMgr = sceneMgr;
  _name = "Barbare";
  _file = "ninja.mesh";
  _position = Ogre::Vector3(100,0,0);
  _rotation = Ogre::Vector3(0,0,0);
  _vitesse = 300;
  _vitesseRotate = 1;
  _pv = 100;
  _scale = Ogre::Vector3(0.6,0.6,0.6);
  createObject(sceneMgr, NULL);
  _object->setMaterialName("Perso2");
  _lightNode = _node->createChildSceneNode();
  _lightNode->setPosition(0, 250, 0);
  _light = sceneMgr->createLight(_name + "_light");
  _lightNode->attachObject(_light);
  _light->setType(Ogre::Light::LT_POINT);
  _light->setDirection(0,-90,0);
  _light->setSpotlightRange(Ogre::Degree(90), Ogre::Degree(180), 1);

  addCollider(colliders);
  createAnimation("Walk");
  _lstCmd["C_LEFT"] = OIS::KC_K;
  _lstCmd["C_RIGHT"] = OIS::KC_M;
  _lstCmd["C_UP"] = OIS::KC_O;
  _lstCmd["C_DOWN"] = OIS::KC_L;
  _lstCmd["C_STRATLEFT"] = OIS::KC_I;
  _lstCmd["C_STRATRIGHT"] = OIS::KC_P;
  _lstCmd["C_FIGHT"] = OIS::KC_U;
  _fight = new Marteau(this, sceneMgr, colliders);
  _score = 0;
  _type = ADrawable::PLAYER;
  _invu = 0;
}

Barbare::~Barbare()
{
  delete _fight;
}
