//
// OgreCore.hpp for OgreCore in /home/rebut_p/Programmation/CPP/tmp
// 
// Made by Pierre Rebut
// Login   <rebut_p@epitech.net>
// 
// Started on  Wed Apr 27 09:59:26 2016 Pierre Rebut
// Last update Wed Jun  1 16:28:22 2016 Pierre Rebut
//

#ifndef		__OGRECORE_HPP__
# define	__OGRECORE_HPP__

# include	<string>
# include	"Ogre.h"
# include	"ADrawable.hpp"
# include	"Plane.hpp"
# include	"Light.hpp"

class		OgreCore
{
  Ogre::Root		*_root;
  Ogre::LogManager	*_log;
  Ogre::RenderWindow	*_window;
  Ogre::SceneManager	*_sceneMgr;

  void			getConfigResources(const std::string &);

public:
  OgreCore();
  virtual ~OgreCore();

  void			run();
  Ogre::Root		*getRoot() const;
  Ogre::RenderWindow	*getRenderWindow() const;
  Ogre::SceneManager	*getSceneManager() const;
};

#endif
