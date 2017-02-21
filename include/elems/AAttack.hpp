//
// AAttack.hpp for cpp_indie_studio in /home/pavot_m/cpp_indie_studio
//
// Made by Maxime Pavot
// Login   <pavot_m@epitech.net>
//
// Started on  Fri Apr 29 15:22:36 2016 Maxime Pavot
// Last update Sat Jun  4 18:28:31 2016 Maxime Pavot
//

#ifndef		CPP_INDIE_STUDIO_AATTACK_HPP
# define	CPP_INDIE_STUDIO_AATTACK_HPP

# include	"Collision.hpp"
# include	"Ogre.h"

# include	"IAttack.hpp"

class AAttack : public IAttack
{
protected:
  int			_frameId;
  size_t		_dmg;
  size_t		_frame;
  Ogre::Real		_vitesse;

  void			*_player;
  Ogre::AnimationState	*_anim;
  Ogre::SceneManager	*_sceneMgr;
  CollisionTools	*_collider;

public:
  virtual	~AAttack(){}
  void		createAttack(const Ogre::Vector3 &, const Ogre::Quaternion &);
  void		sendEvent(const Ogre::FrameEvent &);
  bool		docollide(ADrawable::type type);
};

#endif //CPP_INDIE_STUDIO_AATTACK_HPP
