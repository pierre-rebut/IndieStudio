//
// Plane.hpp for Plane in /home/rebut_p/Programmation/CPP/cpp_indie_studio/tmp/ogre/include/object
// 
// Made by Pierre Rebut
// Login   <rebut_p@epitech.net>
// 
// Started on  Mon May  9 16:03:55 2016 Pierre Rebut
// Last update Wed Jun  1 20:02:38 2016 Pierre Rebut
//

#ifndef		CPP_INDIE_STUDIO_PLANE_HPP__
# define	CPP_INDIE_STUDIO_PLANE_HPP__
# include	<string>
# include	<map>
# include	"AScenery.hpp"
# include	"Collision.hpp"

class		Plane : public AScenery
{
  bool		_castShadows;
  double	_sizeX, _sizeY;
  std::string	_material;
  double	_textSizeX;
  double	_textSizeY;

public:
  Plane(std::map<std::string, std::string> &);
  ~Plane();

  void	createObject(Ogre::SceneManager *, CollisionTools *);
};

#endif
