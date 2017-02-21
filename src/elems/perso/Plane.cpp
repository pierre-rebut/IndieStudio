//
// Plane.cpp for Obejc in /home/rebut_p/Programmation/CPP/cpp_indie_studio/tmp/ogre
// 
// Made by Pierre Rebut
// Login   <rebut_p@epitech.net>
// 
// Started on  Mon May  9 17:27:57 2016 Pierre Rebut
// Last update Sat Jun  4 10:27:07 2016 Pierre Rebut
//

#include	"Plane.hpp"

std::string	verif_value(const std::string &);

Plane::Plane(std::map<std::string, std::string > &map)
{
  Ogre::Vector3		tmp;

  _colliderBool = true;
  _enable = true;
  _name = map["name"];
  _file = "";
  if (map["collide"] == "false")
    _colliderBool = false;

  tmp.x = std::stod(verif_value(map["x"]));
  tmp.z = std::stod(verif_value(map["z"]));
  tmp.y = std::stod(verif_value(map["y"]));
  _position = tmp;

  tmp.x = std::stod(verif_value(map["rot_x"]));
  tmp.z = std::stod(verif_value(map["rot_z"]));
  tmp.y = std::stod(verif_value(map["rot_y"]));
  _rotation = tmp;

  _sizeX = std::stod(verif_value(map["sizeX"]));
  _sizeY = std::stod(verif_value(map["sizeY"]));

  if (map["shadows"] == "true")
    _castShadows = true;
  else
    _castShadows = false;
  _material = map["material"];
  _textSizeX = std::stod(verif_value(map["texSizeX"]));
  _textSizeY = std::stod(verif_value(map["texSizeY"]));
  _textSizeX = _textSizeX == 0 ? 1 : _textSizeX;
  _textSizeY = _textSizeY == 0 ? 1 : _textSizeY;
}

void	Plane::createObject(Ogre::SceneManager *sceneMgr, CollisionTools *colliders)
{
  Ogre::Plane plane(Ogre::Vector3::UNIT_Y, -10);
  Ogre::MeshManager::getSingleton().createPlane(_name,
		Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, plane,
		_sizeX,_sizeY,1,1,true,1,_textSizeX,_textSizeY,Ogre::Vector3::UNIT_Z);
  Ogre::Entity* ent = sceneMgr->createEntity(_name + "_node",_name);
  Ogre::SceneNode *node = sceneMgr->getRootSceneNode()->createChildSceneNode();

  _object = ent;
  _node = node;
  node->attachObject(ent);
  ent->setMaterialName(_material);
  ent->setCastShadows(_castShadows);
  node->setPosition(_position);
  node->pitch(Ogre::Degree(_rotation.z));
  node->yaw(Ogre::Degree(_rotation.y));
  node->roll(Ogre::Degree(_rotation.x));
  if (colliders != NULL)
    colliders->add_entity(this);
}

Plane::~Plane()
{
}
