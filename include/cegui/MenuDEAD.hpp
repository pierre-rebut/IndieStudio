//
// MenuDEAD.hpp for HUD in /home/rebut_p/Programmation/CPP/cpp_indie_studio/ogre/include/cegui
// 
// Made by Pierre Rebut
// Login   <rebut_p@epitech.net>
// 
// Started on  Thu May 26 14:36:26 2016 Pierre Rebut
// Last update Sun Jun  5 22:29:27 2016 Pierre Rebut
//

#ifndef		CPP_INDIE_MENUDEAD_HPP
# define	CPP_INDIE_MENUDEAD_HPP
# include	"CEGUI/CEGUI.h"
# include	"AMenu.hpp"

# include	"Core.hpp"

class		MenuDEAD : public AMenu
{
  CEGUI::Window	*_dead;
  CEGUI::Window	*_vic;

public:
  MenuDEAD(CEGUI::WindowManager *winMgr, CEGUI::Window *winRoot, Core *);
  ~MenuDEAD();

  void		hideAll();
  void		showDead();
  void		showVic();

};

#endif
