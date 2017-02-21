//
// GUICore.hpp for GUI in /home/rebut_p/Programmation/CPP/cpp_indie_studio/ogre
// 
// Made by Pierre Rebut
// Login   <rebut_p@epitech.net>
// 
// Started on  Wed May 25 13:02:29 2016 Pierre Rebut
// Last update Sun Jun  5 22:46:34 2016 Pierre Rebut
//

#ifndef		CPP_INDIE_GUICORE_HPP
# define	CPP_INDIE_GUICORE_HPP

# include	<vector>
# include	"CEGUI/CEGUI.h"
# include	"CEGUI/RendererModules/Ogre/Renderer.h"

# include	"AMenu.hpp"

class		Core;

enum		MenuType
  {
    HUD = 0,
    MAINMENU = 1,
    MENUDEAD = 2
  };

class		GUICore
{
  CEGUI::OgreRenderer	*_renderer;
  CEGUI::WindowManager	*_winMgr;
  CEGUI::Window		*_winRoot;
  std::vector<AMenu*>	_lstMenu;

public:
  GUICore(Core *);
  ~GUICore();

  AMenu			*getMenu(const MenuType);
};

class		CEGUINoLog : public CEGUI::Logger
{
  void		logEvent(const CEGUI::String &, CEGUI::LoggingLevel);
  void		setLogFilename(const CEGUI::String &, bool);
};

#endif
