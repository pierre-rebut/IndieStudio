//
// Light.hpp for Light in /home/rebut_p/Programmation/CPP/cpp_indie_studio/tmp/ogre/include/object
// 
// Made by Pierre Rebut
// Login   <rebut_p@epitech.net>
// 
// Started on  Mon May  9 16:23:48 2016 Pierre Rebut
// Last update Wed Jun  1 20:04:46 2016 Pierre Rebut
//

#ifndef		CPP_INDIE_STUDIO_LIGHT_HPP
# define	CPP_INDIE_STUDIO_LIGHT_HPP
# include	<OgreLight.h>
# include	<string>
# include	<map>
# include	"AScenery.hpp"
# include	"Collision.hpp"

class				Light : public AScenery
{
  Ogre::Light			*_light;
  Ogre::ColourValue		_difuse;
  Ogre::ColourValue		_specular;
  Ogre::Light::LightTypes	_type;

public:
  Light(std::map<std::string, std::string> &);
  ~Light();

  void	createObject(Ogre::SceneManager *, CollisionTools *);
};

#endif
