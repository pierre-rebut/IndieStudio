//
// Spawner.cpp for Spawner in /home/rebut_p/Programmation/CPP/cpp_indie_studio/ogre/src/elems/perso
//
// Made by Pierre Rebut
// Login   <rebut_p@epitech.net>
//
// Started on  Wed May 11 16:35:02 2016 Pierre Rebut
// Last update Sun Jun  5 22:41:56 2016 Maxime Pavot
//

#include	"Spawner.hpp"

std::string	verif_value(const std::string &);

Spawner::Spawner(std::map<std::string, std::string> &map)
{
  Ogre::Vector3	tmp;

  _colliderBool = true;
  _enable = true;
  _name = map["name"];
  _file = map["file"];

  tmp.x = std::stod(verif_value(map["x"]));
  tmp.y = std::stod(verif_value(map["y"]));
  tmp.z = std::stod(verif_value(map["z"]));
  _position = tmp;

  tmp.x = std::stod(verif_value(map["rot_x"]));
  tmp.y = std::stod(verif_value(map["rot_y"]));
  tmp.z = std::stod(verif_value(map["rot_z"]));
  _rotation = tmp;

  tmp.x = std::stod(verif_value(map["scale_x"]));
  tmp.y = std::stod(verif_value(map["scale_y"]));
  tmp.z = std::stod(verif_value(map["scale_z"]));
  _scale = tmp;
  _pv = 100;
  _type = ADrawable::ENEMY;
  _dmg = 0;
}

Spawner::~Spawner()
{
}

bool		Spawner::docollide(ADrawable::type type)
{
  switch (type)
    {
    case ADrawable::PLAYER:
      return (true);
    case ADrawable::ENEMY:
      return (false);
    case ADrawable::SHOT:
      return (true);
    case ADrawable::WALL:
      return (true);
    case ADrawable::BONUS:
      return (false);
    default:
      return (true);
    }
}
