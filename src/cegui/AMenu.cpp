//
// AMenu.cpp for AMenu in /home/rebut_p/Programmation/CPP/cpp_indie_studio/ogre/src/cegui
// 
// Made by Pierre Rebut
// Login   <rebut_p@epitech.net>
// 
// Started on  Thu May 26 14:47:18 2016 Pierre Rebut
// Last update Thu Jun  2 16:51:23 2016 Pierre Rebut
//

#include	"CEGUI/CEGUI.h"
#include	"AMenu.hpp"

AMenu::~AMenu()
{
}

void	AMenu::showMenu(const bool tmp)
{
  _root->setVisible(tmp);
  _show = tmp;
}
