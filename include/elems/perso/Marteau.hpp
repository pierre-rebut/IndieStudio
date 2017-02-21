//
// Marteau.hpp for Marteau in /home/rebut_p/Programmation/CPP/cpp_indie_studio
// 
// Made by Pierre Rebut
// Login   <rebut_p@epitech.net>
// 
// Started on  Fri May 27 16:49:57 2016 Pierre Rebut
// Last update Wed Jun  1 20:02:12 2016 Pierre Rebut
//

#ifndef		CPP_INDIE_MARTEAU_HPP
# define	CPP_INDIE_MARTEAU_HPP

# include	"Ogre.h"
# include	"Collision.hpp"

# include	"AAttack.hpp"

class		Marteau : public AAttack
{
public:
  Marteau(void *, Ogre::SceneManager *, CollisionTools *);
  ~Marteau();
};

#endif
