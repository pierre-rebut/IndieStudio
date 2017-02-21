//
// APickable.hpp for cpp_indie_studio in /home/pavot_m/cpp_indie_studio
//
// Made by Maxime Pavot
// Login   <pavot_m@epitech.net>
//
// Started on  Fri Apr 29 15:06:59 2016 Maxime Pavot
// Last update Sun Jun  5 18:44:19 2016 Pierre Rebut
//

#ifndef CPP_INDIE_STUDIO_APICKABLE_HPP
#define CPP_INDIE_STUDIO_APICKABLE_HPP

#include	"Ogre.h"

#include	"ADrawable.hpp"
#include	"AEntity.hpp"
#include	"Collision.hpp"

class APickable : public ADrawable
{
public:
  virtual ~APickable() {}

  void			popObject(const Ogre::Vector3 &);
  virtual void		catchitem(AEntity *player) = 0;
};

#endif //CPP_INDIE_STUDIO_APICKABLE_HPP
