//
// Light.cpp for Light in /home/rebut_p/Programmation/CPP/cpp_indie_studio/tmp/ogre/include/object/game
//
// Made by Pierre Rebut
// Login   <rebut_p@epitech.net>
//
// Started on  Mon May  9 17:08:02 2016 Pierre Rebut
// Last update Fri Jun  3 19:24:38 2016 Maxime Pavot
//

#include	<map>
#include	<sstream>
#include	"Light.hpp"

std::string	verif_value(const std::string&);

Light::Light(std::map<std::string, std::string> &map)
{
  std::stringstream	ss;
  char			param;
  Ogre::Vector3		tmp;
  Ogre::ColourValue	color;

  _name = map["name"];
  _file = "";

  tmp.x = std::stod(verif_value(map["x"]));
  tmp.y = std::stod(verif_value(map["y"]));
  tmp.z = std::stod(verif_value(map["z"]));
  _position = tmp;

  tmp.x = std::stod(verif_value(map["rot_x"]));
  tmp.y = std::stod(verif_value(map["rot_y"]));
  tmp.z = std::stod(verif_value(map["rot_z"]));
  _rotation = tmp;

  if (map["type"] == "spotlight")
    _type = Ogre::Light::LT_SPOTLIGHT;
  else if (map["type"] == "directional")
    _type = Ogre::Light::LT_DIRECTIONAL;
  else
    _type = Ogre::Light::LT_POINT;
  ss.str(map["difuse"]);
  ss >> color.r >> param >> color.g >> param >> color.b;
  _difuse = color;
  ss.str(map["specular"]);
  ss >> color.r >> param >> color.g >> param >> color.b;
  _specular = color;
}

Light::~Light()
{
}

void	Light::createObject(Ogre::SceneManager *sceneMgr, CollisionTools *)
{
  Ogre::Light* light = sceneMgr->createLight(_name);

  _light = light;
  light->setPosition(_position);
  light->setDiffuseColour(_difuse);
  light->setSpecularColour(_specular);
  light->setType(_type);
  light->setDirection(_rotation);
}
