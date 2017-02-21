//
// GUICore.cpp for GUI in /home/rebut_p/Programmation/CPP/cpp_indie_studio/ogre
// 
// Made by Pierre Rebut
// Login   <rebut_p@epitech.net>
// 
// Started on  Wed May 25 13:06:52 2016 Pierre Rebut
// Last update Sun Jun  5 22:48:04 2016 Pierre Rebut
//

#include	<iostream>
#include	"GUICore.hpp"
#include	"MenuHUD.hpp"
#include	"MainMenu.hpp"
#include	"MenuDEAD.hpp"

void CEGUINoLog::logEvent (const CEGUI::String &, CEGUI::LoggingLevel)
{
}

void CEGUINoLog::setLogFilename(const CEGUI::String&, bool)
{
}

GUICore::GUICore(Core *core)
{
  CEGUINoLog nL;
  _renderer = &CEGUI::OgreRenderer::bootstrapSystem();
  CEGUI::ImageManager::setImagesetDefaultResourceGroup("Imagesets");
  CEGUI::Font::setDefaultResourceGroup("Fonts");
  CEGUI::Scheme::setDefaultResourceGroup("Schemes");
  CEGUI::WidgetLookManager::setDefaultResourceGroup("LookNFeel");
  CEGUI::WindowManager::setDefaultResourceGroup("Layouts");
  CEGUI::SchemeManager::getSingleton().createFromFile("TaharezLook.scheme");
  CEGUI::SchemeManager::getSingleton().createFromFile("Generic.scheme");
  _winMgr = &CEGUI::WindowManager::getSingleton();
  _winRoot = _winMgr->createWindow("DefaultWindow", "CEGUIDemo/Sheet");
  CEGUI::System::getSingleton().getDefaultGUIContext().setDefaultFont("DejaVuSans-12");
  CEGUI::System::getSingleton().getDefaultGUIContext().getMouseCursor().setDefaultImage("TaharezLook/MouseArrow");
  _lstMenu.push_back(new MenuHUD(_winMgr, _winRoot, core));
  _lstMenu.push_back(new MainMenu(_winMgr, _winRoot, core));
  _lstMenu.push_back(new MenuDEAD(_winMgr, _winRoot, core));
  CEGUI::System::getSingleton().getDefaultGUIContext().setRootWindow(_winRoot);
}

GUICore::~GUICore()
{
  for (auto it = _lstMenu.begin(); it != _lstMenu.end(); ++it)
    delete *it;
}

AMenu		*GUICore::getMenu(const MenuType num)
{
  return _lstMenu.at(num);
}
