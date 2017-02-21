//
// MenuDEAD.cpp for Menu in /home/rebut_p/Programmation/CPP/cpp_indie_studio/ogre/src/cegui
// 
// Made by Pierre Rebut
// Login   <rebut_p@epitech.net>
// 
// Started on  Thu May 26 14:48:31 2016 Pierre Rebut
// Last update Sun Jun  5 23:10:26 2016 Pierre Rebut
//

#include	"MenuDEAD.hpp"
#include	<sstream>

MenuDEAD::MenuDEAD(CEGUI::WindowManager *winMgr,
		 CEGUI::Window *winRoot, Core *core)
{
  _root = CEGUI::WindowManager::getSingleton().loadLayoutFromFile("victory.layout");
  _dead = _root->getChild("defeat");
  _vic =  _root->getChild("victory");
  winRoot->addChild(_root);
  hideAll();
}

void	MenuDEAD::hideAll()
{
  _root->hide();
  _dead->hide();
  _vic->hide();
}

void	MenuDEAD::showDead()
{
  _root->show();
  _dead->show();
}

void	MenuDEAD::showVic()
{
  _root->show();
  _vic->show();
}

MenuDEAD::~MenuDEAD()
{
}
