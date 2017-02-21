//
// ACharacter.cpp for ACharacter in /home/rebut_p/Programmation/CPP/cpp_indie_studio/ogre/src/elems
//
// Made by Pierre Rebut
// Login   <rebut_p@epitech.net>
//
// Started on  Wed May 11 16:19:13 2016 Pierre Rebut
// Last update Sun Jun  5 20:11:17 2016 Pierre Rebut
//

#include	<iostream>
#include	"ACharacter.hpp"

bool	ACharacter::docollide(ADrawable::type type)
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
      return (true);
    default:
      return (true);
    }
}

bool	ACharacter::sendEvent(const Ogre::FrameEvent &evt,
			      const OIS::Keyboard *keyboard,
			      const OIS::JoyStickState *joy)
{
  if (_pv == 0)
    {
      _enable = false;
      _object->setVisible(false);
      _collider->delete_entity(this);
      return (false);
    }
  Ogre::Real mMouvement;
  Ogre::Radian mRotation;

  Ogre::Vector3 deplacement = Ogre::Vector3::ZERO;
  mMouvement = _vitesse * evt.timeSinceLastFrame;

  bool	walk = false;
  int slide_x = 0;
  int slide_y = 0;
  if (_manette == true && joy != NULL)
    {
      slide_x = joy->mAxes[0].abs;
      slide_y = joy->mAxes[1].abs;
    }
  if (_invu > 0)
    _invu--;
  if(keyboard->isKeyDown(_lstCmd["C_LEFT"]) || slide_x < -10000)
    mRotation = Ogre::Degree(_vitesseRotate);
  if(keyboard->isKeyDown(_lstCmd["C_RIGHT"]) || slide_x > 10000)
    mRotation = Ogre::Degree(-_vitesseRotate);
  if(keyboard->isKeyDown(_lstCmd["C_UP"]) || slide_y < -10000)
    {
      deplacement.z -= mMouvement;
      walk = true;
    }
  if(keyboard->isKeyDown(_lstCmd["C_DOWN"]) || slide_y > 10000)
    {
      deplacement.z += mMouvement;
      walk = true;
    }
  if(keyboard->isKeyDown(_lstCmd["C_STRATLEFT"]) || (joy != NULL &&_manette == true &&
						      joy->mButtons[4] == true))
    {
      deplacement.x -= mMouvement;
    }
  if(keyboard->isKeyDown(_lstCmd["C_STRATRIGHT"]) || (joy != NULL &&_manette == true &&
						      joy->mButtons[5] == true))
    {
      deplacement.x += mMouvement;
    }
  if (keyboard->isKeyDown(_lstCmd["C_FIGHT"]) || (joy != NULL && _manette == true &&
						  joy->mButtons[0] == true))
    _fight->createAttack(_position, _node->getOrientation());
  move(deplacement, _fight);
  _fight->sendEvent(evt);
  rotate(mRotation);
  setAnimationEnable(walk);
  setAnimationFrame(evt.timeSinceLastFrame);
  return (true);
}

size_t		ACharacter::getScore(void) const
{
  return (_score);
}

void		ACharacter::setScore(const size_t score)
{
  _score = score;
}

void		ACharacter::setDamage(const size_t dmg)
{
  if (_invu == 0)
    {
      if (dmg >= _pv)
	_pv = 0;
      else
	_pv -= dmg;
      _invu = 175;
    }
}
