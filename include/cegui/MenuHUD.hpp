//
// MenuHUD.hpp for HUD in /home/rebut_p/Programmation/CPP/cpp_indie_studio/ogre/include/cegui
// 
// Made by Pierre Rebut
// Login   <rebut_p@epitech.net>
// 
// Started on  Thu May 26 14:36:26 2016 Pierre Rebut
// Last update Sun Jun  5 20:42:33 2016 Pierre Rebut
//

#ifndef		CPP_INDIE_MENUHUD_HPP
# define	CPP_INDIE_MENUHUD_HPP
# include	<string>
# include	"CEGUI/CEGUI.h"
# include	"AMenu.hpp"

# include	"Core.hpp"

class		MenuHUD : public AMenu
{

  CEGUI::ProgressBar	*_bar1;
  CEGUI::ProgressBar	*_bar2;
  CEGUI::Window		*_score;
  CEGUI::Window		*_spawners;

public:
  MenuHUD(CEGUI::WindowManager *winMgr, CEGUI::Window *winRoot,
	  Core *);
  ~MenuHUD();

  void		updatePV(const std::string &, int);
  void		updateScore(int score, int spawn);
  void		hideP2(const bool);
};

#endif
