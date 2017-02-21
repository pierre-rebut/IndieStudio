//
// AEnemy.hpp for cpp_indie_studio in /home/pavot_m/cpp_indie_studio
//
// Made by Maxime Pavot
// Login   <pavot_m@epitech.net>
//
// Started on  Fri Apr 29 15:16:19 2016 Maxime Pavot
// Last update Sun Jun  5 16:15:12 2016 Pierre Rebut
//

#ifndef CPP_INDIE_STUDIO_AENEMY_HPP
#define CPP_INDIE_STUDIO_AENEMY_HPP

# include <vector>
# include "IEnemy.hpp"
# include "ACharacter.hpp"

class AEnemy : public IEnemy
{
protected:
  Ogre::SceneManager	*_sceneMgr;
  int			_frameId;
  std::vector<ACharacter*> *_lstPlayer;

public:
  virtual ~AEnemy(){}

  bool		move(const Ogre::Vector3 &, void * = NULL);
  void		spawnEnemy(const Ogre::Vector3 &);
  bool		docollide(ADrawable::type type);
  virtual bool	execOneFrame(const Ogre::FrameEvent &) = 0;
  virtual Ogre::Vector3        focusPlayer(void) = 0;
};

#endif //CPP_INDIE_STUDIO_AENEMY_HPP
