//
// Character.hpp for Character in /home/rebut_p/Programmation/CPP/cpp_indie_studio/ogre/include/elems/perso
// 
// Made by Pierre Rebut
// Login   <rebut_p@epitech.net>
// 
// Started on  Wed May 11 16:25:24 2016 Pierre Rebut
// Last update Sun Jun  5 18:08:48 2016 Pierre Rebut
//

#ifndef	MAGE_HPP__
#define MAGE_HPP__

# include <string>
# include "Collision.hpp"

# include "ACharacter.hpp"

class	Mage : public ACharacter
{
public:
  Mage(Ogre::SceneManager *,
       CollisionTools *, const bool = false);
  ~Mage();
};

#endif
