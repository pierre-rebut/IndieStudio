//
// AScenery.cpp for AScenery in /home/rebut_p/Programmation/CPP/cpp_indie_studio/ogre
//
// Made by Pierre Rebut
// Login   <rebut_p@epitech.net>
//
// Started on  Wed May 11 17:19:01 2016 Pierre Rebut
// Last update Fri Jun  3 21:29:36 2016 Maxime Pavot
//

#include	"AScenery.hpp"

bool		AScenery::docollide(ADrawable::type type)
{
  switch (type)
    {
    case ADrawable::PLAYER:
      return (true);
    case ADrawable::ENEMY:
      return (true);
    case ADrawable::SHOT:
      return (true);
    case ADrawable::WALL:
      return (true);
    case ADrawable::BONUS:
      return (true);
    default:
      return (true);
    }
}
