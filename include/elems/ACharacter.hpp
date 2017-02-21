//
// AEntity.hpp for cpp_indie_studio in /home/pavot_m/cpp_indie_studio
//
// Made by Maxime Pavot
// Login   <pavot_m@epitech.net>
//
// Started on  Fri Apr 29 15:10:27 2016 Maxime Pavot
// Last update Sun Jun  5 18:24:38 2016 Pierre Rebut
//

#ifndef CPP_INDIE_STUDIO_ACHARACTER_HPP
#define CPP_INDIE_STUDIO_ACHARACTER_HPP

# include <map>
# include "Ogre.h"
# include "OIS/OIS.h"

# include "ICharacter.hpp"
# include "AAttack.hpp"

class ACharacter : public ICharacter
{
protected:
  bool			_manette;
  Ogre::Light		*_light;
  Ogre::SceneNode	*_lightNode;
  Ogre::SceneManager	*_sceneMgr;
  std::map<std::string, OIS::KeyCode>	_lstCmd;
  size_t		_score;
  AAttack		*_fight;
  size_t		_invu;

public:
  virtual ~ACharacter(){}

  bool	sendEvent(const Ogre::FrameEvent &evt,
		  const OIS::Keyboard*, const OIS::JoyStickState *);
  size_t	getScore(void) const;
  void		setScore(const size_t score);
  bool		docollide(ADrawable::type type);
  void		setDamage(const size_t dmg);
};

#endif //CPP_INDIE_STUDIO_AENTITY_HPP
