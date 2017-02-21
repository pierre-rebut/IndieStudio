//
// MainMenu.cpp for Menu in /home/rebut_p/Programmation/CPP/cpp_indie_studio/ogre/src/cegui
// 
// Made by Pierre Rebut
// Login   <rebut_p@epitech.net>
// 
// Started on  Thu May 26 14:48:31 2016 Pierre Rebut
// Last update Sun Jun  5 23:28:51 2016 Pierre Rebut
//

#include	"MainMenu.hpp"
#include	<iostream>

MainMenu::MainMenu(CEGUI::WindowManager *winMgr,
		 CEGUI::Window *winRoot, Core *core)
{
  _root = CEGUI::WindowManager::getSingleton().loadLayoutFromFile("my_layout.layout");
  _root->getChild("StartOnePlayer")->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&Core::startGameOnePlayer, core));

  _root->getChild("StartTwoPlayer")->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&Core::startGameTwoPlayer, core));

  _root->getChild("QuitButton")->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&Core::exitGame, core));

  _root->getChild("difficulty")->subscribeEvent(CEGUI::ToggleButton::EventSelectStateChanged, CEGUI::Event::Subscriber(&Core::changeDifficulter, core));

  winRoot->addChild(_root);
  _root->hide();
}

MainMenu::~MainMenu()
{
}
