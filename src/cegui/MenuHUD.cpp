//
// MenuHUD.cpp for Menu in /home/rebut_p/Programmation/CPP/cpp_indie_studio/ogre/src/cegui
// 
// Made by Pierre Rebut
// Login   <rebut_p@epitech.net>
// 
// Started on  Thu May 26 14:48:31 2016 Pierre Rebut
// Last update Sun Jun  5 20:57:55 2016 Pierre Rebut
//

#include	"MenuHUD.hpp"
#include	<sstream>

MenuHUD::MenuHUD(CEGUI::WindowManager *winMgr,
		 CEGUI::Window *winRoot, Core *core)
{
  _root = CEGUI::WindowManager::getSingleton().loadLayoutFromFile("hud_layout.layout");
  _bar1 =  (CEGUI::ProgressBar*)_root->getChild("prog_play_1");
  _bar2 =  (CEGUI::ProgressBar*)_root->getChild("prog_play_2");
  _score = _root->getChild("text_score");
  _spawners = _root->getChild("text_spawners");
  winRoot->addChild(_root);
  _root->hide();
}

void	MenuHUD::hideP2(const bool tmp)
{
  _bar2->setVisible(!tmp);
}

MenuHUD::~MenuHUD()
{
}

void	MenuHUD::updatePV(const std::string &player, int pv)
{
  if (player == "Barbare")
    _bar2->setProgress(static_cast<float>(pv) / 100);
  else
    _bar1->setProgress(static_cast<float>(pv) / 100);
}

void	MenuHUD::updateScore(int score, int spawn)
{
  _score->setText("Score: " + CEGUI::PropertyHelper<int>::toString(score));
  _spawners->setText("Spawners restants: " + CEGUI::PropertyHelper<int>::toString(spawn));
}
