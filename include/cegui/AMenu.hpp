//
// AMenu.hpp for AMenu in /home/rebut_p/Programmation/CPP/cpp_indie_studio/ogre/include/cegui
// 
// Made by Pierre Rebut
// Login   <rebut_p@epitech.net>
// 
// Started on  Thu May 26 14:00:43 2016 Pierre Rebut
// Last update Sun Jun  5 20:40:04 2016 Pierre Rebut
//

#ifndef		CPP_INDIE_AMENU_HPP
# define	CPP_INDIE_AMENU_HPP
# include	"CEGUI/CEGUI.h"

class		AMenu
{
protected:
  bool		_show;
  CEGUI::Window	*_root;

public:
  virtual ~AMenu() = 0;

  void		showMenu(const bool);
};

#endif
