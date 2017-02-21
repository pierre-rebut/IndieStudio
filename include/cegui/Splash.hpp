//
// Splash.hpp for HUD in /home/rebut_p/Programmation/CPP/cpp_indie_studio/ogre/include/cegui
// 
// Made by Pierre Rebut
// Login   <rebut_p@epitech.net>
// 
// Started on  Thu May 26 14:36:26 2016 Pierre Rebut
// Last update Sat Jun  4 12:39:47 2016 Pierre Rebut
//

#ifndef		CPP_INDIE_SPLASH_HPP
# define	CPP_INDIE_SPLASH_HPP
# include	"CEGUI/CEGUI.h"
# include	"AMenu.hpp"

class		Splash : public AMenu
{

public:
  Splash(CEGUI::WindowManager *winMgr, CEGUI::Window *winRoot,
	  CEGUI::MouseCursor *);
  ~Splash();

  void		update();
};

#endif
