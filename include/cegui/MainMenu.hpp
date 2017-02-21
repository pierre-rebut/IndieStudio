//
// MainMenu.hpp for HUD in /home/rebut_p/Programmation/CPP/cpp_indie_studio/ogre/include/cegui
// 
// Made by Pierre Rebut
// Login   <rebut_p@epitech.net>
// 
// Started on  Thu May 26 14:36:26 2016 Pierre Rebut
// Last update Sun Jun  5 20:40:13 2016 Pierre Rebut
//

#ifndef		CPP_INDIE_MAINMENU_HPP
# define	CPP_INDIE_MAINMENU_HPP
# include	"CEGUI/CEGUI.h"
# include	"AMenu.hpp"

# include	"Core.hpp"

class		MainMenu : public AMenu
{

public:
  MainMenu(CEGUI::WindowManager *winMgr, CEGUI::Window *winRoot, Core *);
  ~MainMenu();

};

#endif
