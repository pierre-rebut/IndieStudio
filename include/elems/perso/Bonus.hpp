//
// Bonus.hpp for  in /home/pavot_m/cpp_indie_studio/include/elems/perso
//
// Made by Maxime Pavot
// Login   <pavot_m@epitech.net>
//
// Started on  Sat Jun  4 13:21:26 2016 Maxime Pavot
// Last update Sun Jun  5 18:41:48 2016 Pierre Rebut
//

#ifndef CPP_INDIE_STUDIO_BONUS_HPP
#define CPP_INDIE_STUDIO_BONUS_HPP

#include        "APickable.hpp"

class Bonus : public APickable
{
public:
  Bonus(const int, Ogre::SceneManager *, CollisionTools *);
  ~Bonus();

  bool		docollide(ADrawable::type);
  void		catchitem(AEntity *player);
};

#endif
