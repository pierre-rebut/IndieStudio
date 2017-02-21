//
// Object.cpp for Obejct in /home/rebut_p/Programmation/CPP/cpp_indie_studio/tmp/ogre
//
// Made by Pierre Rebut
// Login   <rebut_p@epitech.net>
//
// Started on  Mon May  9 17:32:22 2016 Pierre Rebut
// Last update Sat Jun  4 10:27:16 2016 Pierre Rebut
//

#include	"Object.hpp"

std::string	verif_value(const std::string &in)
{
  return (in != "" ? in : "0");
}

Object::Object(std::map<std::string, std::string> &map)
{
  Ogre::Vector3		tmp;

  _enable = true;
  _name = map["name"];
  _file = map["file"];
  _colliderBool = true;
  if (map["collide"] == "false")
    _colliderBool = false;

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
  _type = ADrawable::WALL;
}

Object::~Object()
{
}
