//
// ADrawable.hpp for cpp_indie_studio in /home/pavot_m/cpp_indie_studio
//
// Made by Maxime Pavot
// Login   <pavot_m@epitech.net>
//
// Started on  Fri Apr 29 15:04:56 2016 Maxime Pavot
// Last update Sun Jun  5 21:20:12 2016 Pierre Rebut
//

#ifndef CPP_INDIE_STUDIO_ADRAWABLE_HPP
#define CPP_INDIE_STUDIO_ADRAWABLE_HPP

#include	<string>
#include	"Ogre.h"

class	CollisionTools;

class ADrawable
{
public:
  enum type
    {
      ENEMY,
      PLAYER,
      WALL,
      SHOT,
      BONUS,
      END
    };


protected:
  type			_type;
  bool			_enable;
  std::string		_name;
  std::string		_file;
  bool			_colliderBool;
  Ogre::Vector3		_scale;
  Ogre::Vector3		_position;
  Ogre::Vector3		_rotation;
  Ogre::SceneNode	*_node;
  Ogre::Entity		*_object;

public:
  virtual ~ADrawable(){}

  bool			getEnable() const;
  Ogre::Entity		*getEntity() const;
  Ogre::Vector3		getPosition() const;
  Ogre::Quaternion	getRotation() const;
  void			destroyObject(Ogre::SceneManager *);

  void			setPosition(const Ogre::Vector3 &);
  const std::string	&getName() const;
  virtual void		createObject(Ogre::SceneManager *, CollisionTools *);
  virtual bool		docollide(ADrawable::type type) = 0;
  type			gettype() const;
};

#endif //CPP_INDIE_STUDIO_ADRAWABLE_HPP
