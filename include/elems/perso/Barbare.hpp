//
// Barabare.hpp for Barabare in /home/rebut_p/Programmation/CPP/cpp_indie_studio/ogre/include/elems/perso
// 
// Made by Pierre Rebut
// Login   <rebut_p@epitech.net>
// 
// Started on  Wed May 11 16:25:24 2016 Pierre Rebut
// Last update Sun Jun  5 18:08:05 2016 Pierre Rebut
//

#ifndef	CPP_INDIE_BARBARE_HPP__
#define CPP_INDIE_BARBARE_HPP__

# include <string>
# include "Collision.hpp"

# include "ACharacter.hpp"

class	Barbare : public ACharacter
{
public:
  Barbare(Ogre::SceneManager *,
	  CollisionTools *, const bool = false);
  ~Barbare();
};

#endif
