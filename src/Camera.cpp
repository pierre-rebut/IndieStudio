//
// Camera.cpp for Cam in /home/rebut_p/Programmation/CPP/cpp_indie_studio
// 
// Made by Pierre Rebut
// Login   <rebut_p@epitech.net>
// 
// Started on  Mon May 30 16:55:46 2016 Pierre Rebut
// Last update Sat Jun  4 20:49:18 2016 Pierre Rebut
//

#include	"Camera.hpp"

Camera::Camera(Ogre::SceneManager *sceneMgr,
	       Ogre::RenderWindow *win)
{
  _cam = sceneMgr->createCamera("cam");
  _cam->setNearClipDistance(5);
  _cam->setPosition(0, 0, 0);
  _cam->pitch(Ogre::Degree(-72));
  _vp = win->addViewport(_cam);
  _vp->setBackgroundColour(Ogre::ColourValue(0,0,0));
  _cam->setAspectRatio(Ogre::Real(_vp->getActualWidth()) /\
		       Ogre::Real(_vp->getActualHeight()));
}

Camera::~Camera()
{
}

void		Camera::move(const std::vector<ACharacter*> &lstPlayer)
{
  Ogre::Vector3	pos;
  Ogre::Vector3 tmp;
  int		x = 0;
  int		z = 0;
  int		min_x = 200000;
  int		min_z = 200000;
  int		max_x = -200000;
  int		max_z = -200000;
  int		i = 0;

  for (auto it = lstPlayer.begin(); it != lstPlayer.end(); ++it)
    {
      tmp = (*it)->getPosition();
      x += tmp.x;
      z += tmp.z;
      if (tmp.x < min_x)
      	min_x = tmp.x;
      if (tmp.z < min_z)
      	min_z = tmp.z;
      if (tmp.x > max_x)
      	max_x = tmp.x;
      if (tmp.z > max_z)
      	max_z = tmp.z;
      i++;
    }
  if (i > 1)
    {
      pos.x = (x - 75) / i;
      pos.z = (z + 600) / i;
    }
  else
    {
      pos.x = x;
      pos.z = z + 300;
    }
  pos.y = 1000;
  if ((max_x - min_x) > 500)
    {
      pos.x += ((max_x - min_x) - 500) / 5;
      pos.y += (max_x - min_x) - 500;
      pos.z += (max_x - min_x) - 500;
    }
  if ((max_z - min_z) > 300)
    {
      pos.y += (max_z - min_z) * 1.5 - 450;
      pos.z += 0.5 * (max_z - min_z) - 150;
    }
  _cam->setPosition(pos);
}
