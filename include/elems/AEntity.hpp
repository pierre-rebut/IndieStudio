//
// AEntity.hpp for cpp_indie_studio in /home/pavot_m/cpp_indie_studio
//
// Made by Maxime Pavot
// Login   <pavot_m@epitech.net>
//
// Started on  Fri Apr 29 15:19:34 2016 Maxime Pavot
// Last update Sun Jun  5 02:10:37 2016 Maxime Pavot
//

#ifndef CPP_INDIE_STUDIO_AENTITY_HPP
#define CPP_INDIE_STUDIO_AENTITY_HPP

# include "ADrawable.hpp"

class AEntity : public ADrawable
{
protected:
  size_t		_pv;
  size_t		_dmg;
  Ogre::Real		_vitesse;
  Ogre::Real		_vitesseRotate;
  Ogre::AnimationState	*_anim;
  CollisionTools	*_collider;

public:
  virtual ~AEntity() {}

  virtual bool	move(const Ogre::Vector3 &, void * = NULL);
  bool		rotate(const Ogre::Radian &);

  void		createAnimation(const std::string &);
  void		setAnimationEnable(const bool);
  void		setAnimationFrame(const Ogre::Real &);
  void		addCollider(CollisionTools *);

  size_t	getPV() const;
  size_t	getDmg() const;
  Ogre::Real	getVitesse() const;
  Ogre::Real	getVitesseRotation() const;

  virtual void		setDamage(const size_t dmg);
  void		setPv(const size_t pv);
  void		setVitesse(const size_t vitesse);
  void		setDmg(const size_t dmg);
};

#endif //CPP_INDIE_STUDIO_AENTITY_HPP
