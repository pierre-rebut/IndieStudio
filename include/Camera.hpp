//
// Camera.hpp for Camera in /home/rebut_p/Programmation/CPP/cpp_indie_studio
// 
// Made by Pierre Rebut
// Login   <rebut_p@epitech.net>
// 
// Started on  Mon May 30 16:52:03 2016 Pierre Rebut
// Last update Mon May 30 18:34:08 2016 Pierre Rebut
//

#ifndef		CPP_INDIE_CAMERA_HPP
# define	CPP_INDIE_CAMERA_HPP

# include	<vector>
# include	"Ogre.h"

# include	"ACharacter.hpp"

class		Camera
{
  Ogre::Camera	*_cam;
  Ogre::Viewport *_vp;

public:
  Camera(Ogre::SceneManager *, Ogre::RenderWindow *);
  ~Camera();

  void		move(const std::vector<ACharacter*> &);
};
#endif
