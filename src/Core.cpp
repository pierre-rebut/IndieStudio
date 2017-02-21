//
// Core.cpp for Core in /home/rebut_p/Programmation/CPP/cpp_indie_studio/tmp/ogre
//
// Made by Pierre Rebut
// Login   <rebut_p@epitech.net>
//
// Started on  Sun May  1 15:40:29 2016 Pierre Rebut
// Last update Tue Jun  7 16:34:57 2016 Maxime Pavot
//

#include	<iostream>
#include	"Core.hpp"
#include	"GUICore.hpp"
#include	"Barbare.hpp"
#include	"Mage.hpp"
#include	"parsing.hpp"
#include	"MenuHUD.hpp"
#include	"MenuDEAD.hpp"

Core::Core()
{
  _loopCore = true;
  _startGame = false;
  _core = new OgreCore;
  _soundSystem = new SoundClass;
  _guiCore = new GUICore(this);

  _window = _core->getRenderWindow();
  startOIS();
  _core->getRoot()->addFrameListener(this);
  _camera = new Camera(_core->getSceneManager(),
		       _window);
  _diff = true;
}

Core::~Core()
{
  Ogre::WindowEventUtilities::removeWindowEventListener(_window, this);
  windowClosed(_window);
  delete _guiCore;
  delete _camera;
  delete _core;
  delete _soundSystem;
}

void		Core::startOgre()
{
  _lstSound.push_back(_soundSystem->createSound("./config/sound/SSTheme.mp3"));
  _lstSound.push_back(_soundSystem->createSound("./config/sound/menuTheme.mp3"));
  _lstSound.push_back(_soundSystem->createSound("./config/sound/playTheme.mp3"));
  _lstSound.push_back(_soundSystem->createSound("./config/sound/victory.mp3"));
  _lstSound.push_back(_soundSystem->createSound("./config/sound/gameOver.mp3"));
  _soundSystem->playSound(_lstSound[0], true, 3);
  _soundSystem->playSound(_lstSound[1], true, 0.4);
  _soundSystem->playSound(_lstSound[2], true, 0.5);
  _soundSystem->pauseSound(_lstSound[1], true);
  _soundSystem->pauseSound(_lstSound[2], true);
  _soundSystem->pauseSound(_lstSound[3], true);
  _soundSystem->pauseSound(_lstSound[4], true);

  _intro =  true;
  _timer = NULL;
  _core->run();
}

void		Core::deleteScene()
{
  delete _enemySystem;
  for (auto it = _lstObj.begin(); it < _lstObj.end(); ++it)
    {
      delete *it;
    }
  for (auto it = _lstPlayer.begin(); it < _lstPlayer.end(); ++it)
    {
      delete *it;
    }
  delete _colliders;
  _core->getSceneManager()->clearScene();
  _lstObj.clear();
  _lstPlayer.clear();
  _lstSpawner.clear();
  _soundSystem->pauseSound(_lstSound[3], true);
  _soundSystem->pauseSound(_lstSound[4], true);
  _soundSystem->pauseSound(_lstSound[1], false);
  _soundSystem->pauseSound(_lstSound[2], true);
  std::cerr << "destroy scene => end" << std::endl;
  AMenu *tmp = _guiCore->getMenu(HUD);
  tmp->showMenu(false);
  tmp = _guiCore->getMenu(MAINMENU);
  tmp->showMenu(true);
  _startGame = false;
}

void		Core::loadGame()
{
  _endGame = 0;
  _doEndGame = false;
  _soundSystem->pauseSound(_lstSound[1], true);
  _soundSystem->pauseSound(_lstSound[2], false);
  AMenu	*tmp = _guiCore->getMenu(MAINMENU);
  tmp->showMenu(false);
  _startGame = true;
  _colliders = new CollisionTools;
  createScene("./config/terrain.cfg", _colliders);
  _enemySystem = new EnemySystem("./config/ia_script.lua", 150, &_lstSpawner,
				 _core->getSceneManager(), _colliders, &_lstPlayer);
}

void		Core::startGameOnePlayer()
{
  loadGame();
  MenuHUD *tmp = dynamic_cast<MenuHUD*>(_guiCore->getMenu(HUD));
  tmp->showMenu(true);
  tmp->hideP2(true);
  _lstPlayer.push_back(new Mage(_core->getSceneManager(), _colliders, true));
}

void		Core::startGameTwoPlayer()
{
  loadGame();
  MenuHUD *tmp = dynamic_cast<MenuHUD*>(_guiCore->getMenu(HUD));
  tmp->showMenu(true);
  tmp->hideP2(false);
  _lstPlayer.push_back(new Mage(_core->getSceneManager(), _colliders, true));
  _lstPlayer.push_back(new Barbare(_core->getSceneManager(), _colliders));
}

void		Core::createScene(const std::string &file, CollisionTools *col)
{
  Spawner	*tmp;
  Parsing	parsefile(file);

  _lstObj.clear();
  try
    {
      _lstObj = parsefile.parse();
    }
  catch (std::exception &e)
    {
      std::cerr << e.what() << std::endl;
      throw "error";
    }
  if (_lstObj.empty())
    throw std::runtime_error("No object in scene");
  for (auto it = _lstObj.begin(); it != _lstObj.end(); ++it)
    {
      tmp = dynamic_cast<Spawner*>(*it);
      if (tmp != NULL)
	_lstSpawner.push_back(tmp);
      (*it)->createObject(_core->getSceneManager(), col);
    }
}

void		Core::startOIS()
{
  OIS::ParamList	pl;
  size_t		windowHnd = 0;

  _window->getCustomAttribute("WINDOW", &windowHnd);
  pl.insert(std::make_pair("WINDOW", Ogre::StringConverter::toString(windowHnd)));
  _inputMgr = OIS::InputManager::createInputSystem(pl);
  _mouse = static_cast<OIS::Mouse*>(_inputMgr->createInputObject(OIS::OISMouse,
								 true));
  _keyboard = static_cast<OIS::Keyboard*>(_inputMgr->createInputObject(OIS::OISKeyboard, true));
  try
    {
      _joy = static_cast<OIS::JoyStick*>(_inputMgr->createInputObject(OIS::OISJoyStick, false));
    }
  catch (std::exception const &e)
    {
      std::cerr << "Warning: " << e.what() << std::endl;
      _joy = NULL;
    }
  windowResized(_window);
  Ogre::WindowEventUtilities::addWindowEventListener(_window, this);
  _mouse->setEventCallback(this);
  _keyboard->setEventCallback(this);
  CEGUI::Vector2f mousePos = CEGUI::System::getSingleton().getDefaultGUIContext().getMouseCursor().getPosition();
  CEGUI::System::getSingleton().getDefaultGUIContext().injectMouseMove(-mousePos.d_x,-mousePos.d_y);
}

void		Core::windowResized(Ogre::RenderWindow *wnd)
{
  unsigned int	width, height, depth;
  int		left, top;

  wnd->getMetrics(width, height, depth, left, top);
  const OIS::MouseState &ms = _mouse->getMouseState();
  ms.width = width;
  ms.height = height;
}

void		Core::windowClosed(Ogre::RenderWindow *wnd)
{
  if (wnd == _window)
    {
      if (_inputMgr)
	{
	  _inputMgr->destroyInputObject(_mouse);
	  _inputMgr->destroyInputObject(_keyboard);
	  if (_joy != NULL)
	    _inputMgr->destroyInputObject(_joy);
	  OIS::InputManager::destroyInputSystem(_inputMgr);
	  _inputMgr = 0;
	}
    }
}

bool		Core::keyPressed(const OIS::KeyEvent &e)
{
  switch(e.key)
    {
    case OIS::KC_ESCAPE:
      {
	if (_startGame == true)
	  {
	    if (_endGame != 0)
	      {
		MenuDEAD *tmp = dynamic_cast<MenuDEAD*>(_guiCore->getMenu(MENUDEAD));
		tmp->hideAll();
	      }
	    AMenu	*menu_pause = _guiCore->getMenu(MAINMENU);
	    if (menu_pause == NULL)
	      throw std::runtime_error("Error: hud not found");
	    deleteScene();
	    menu_pause->showMenu(true);
	    _startGame = false;
	  }
	break;
      }
    default:
      {
	CEGUI::System::getSingleton().getDefaultGUIContext().injectKeyDown((CEGUI::Key::Scan)e.key);
	CEGUI::System::getSingleton().getDefaultGUIContext().injectChar(e.text);
      }
    }
  return true;
}

bool		Core::keyReleased(const OIS::KeyEvent &e)
{
  return true;
}

bool Core::mousePressed(const OIS::MouseEvent &arg,OIS::MouseButtonID id)
{
  std::cout << "clicked!" << std::endl;
  switch (id)
    {
    case OIS::MB_Left:
      CEGUI::System::getSingleton().getDefaultGUIContext().injectMouseButtonDown(CEGUI::LeftButton);
      break;
    case OIS::MB_Middle:
      CEGUI::System::getSingleton().getDefaultGUIContext().injectMouseButtonDown(CEGUI::MiddleButton);
      break;
    case OIS::MB_Right:
      CEGUI::System::getSingleton().getDefaultGUIContext().injectMouseButtonDown(CEGUI::RightButton);
      break;
    case OIS::MB_Button3:
      CEGUI::System::getSingleton().getDefaultGUIContext().injectMouseButtonDown(CEGUI::X1Button);
      break;
    case OIS::MB_Button4:
      CEGUI::System::getSingleton().getDefaultGUIContext().injectMouseButtonDown(CEGUI::X2Button);
      break;
    default:
      break;
    }

  return true;
}

bool Core::mouseReleased(const OIS::MouseEvent &arg,OIS::MouseButtonID id)
{
  switch (id)
    {
    case OIS::MB_Left:
      CEGUI::System::getSingleton().getDefaultGUIContext().injectMouseButtonUp(CEGUI::LeftButton);
      break;
    case OIS::MB_Middle:
      CEGUI::System::getSingleton().getDefaultGUIContext().injectMouseButtonUp(CEGUI::MiddleButton);
      break;
    case OIS::MB_Right:
      CEGUI::System::getSingleton().getDefaultGUIContext().injectMouseButtonUp(CEGUI::RightButton);
      break;
    case OIS::MB_Button3:
      CEGUI::System::getSingleton().getDefaultGUIContext().injectMouseButtonUp(CEGUI::X1Button);
      break;
    case OIS::MB_Button4:
      CEGUI::System::getSingleton().getDefaultGUIContext().injectMouseButtonUp(CEGUI::X2Button);
      break;
    default:
      break;
    }
  return true;
}

bool Core::mouseMoved(const OIS::MouseEvent& arg)
{
  CEGUI::System::getSingleton().getDefaultGUIContext().injectMouseMove(arg.state.X.rel, arg.state.Y.rel);
  return true;
}

void		Core::changeDifficulter()
{
  _diff = !_diff;
}

void		Core::destroyObject()
{
  auto it2 = _lstSpawner.begin();
  while (it2 < _lstSpawner.end())
    {
      if ((*it2)->getPV() == 0)
	{
	  (*it2)->destroyObject(_core->getSceneManager());
	  _colliders->delete_entity(*it2);
	  it2 = _lstSpawner.erase(it2);
	}
      else
	++it2;
    }
  auto it = _lstPlayer.begin();
  while (it < _lstPlayer.end())
    {
      if ((*it)->getEnable() == false)
	{
	  delete *it;
	  it = _lstPlayer.erase(it);
	}
      else
	++it;
    }
}

void		Core::exitGame()
{
  _loopCore = false;
}

bool		Core::frameRenderingQueued(const Ogre::FrameEvent &evt)
{
  _keyboard->capture();
  _mouse->capture();
  if (_window->isClosed())
    return false;
  OIS::JoyStickState tmp;
  if (_joy != NULL)
    {
      _joy->capture();
      tmp = _joy->getJoyStickState();
    }

  if (_intro == true)
    {
      _intro = false;
      _timer = new Ogre::Timer;
      createScene("./config/intro.cfg");
      return true;
    }
  if (_timer != NULL && !_keyboard->isKeyDown(OIS::KC_RETURN) &&
      _timer->getMilliseconds() < 9400)
    {
      return true;
    }
  if (_timer != NULL)
      {
	for (auto it = _lstObj.begin(); it < _lstObj.end(); ++it)
	  delete *it;
	_core->getSceneManager()->clearScene();
	_lstObj.clear();
	delete _timer;
	_timer = NULL;
	_soundSystem->releaseSound(_lstSound[0]);
	_soundSystem->pauseSound(_lstSound[1], false);
	AMenu	*menu_pause = _guiCore->getMenu(MAINMENU);
	menu_pause->showMenu(true);
	_startGame = false;
	return true;
      }

  if (_startGame == true)
    {
      if (_endGame == 0)
	{
	  _enemySystem->notifyReady(evt);
	  MenuHUD *tmpHUD = dynamic_cast<MenuHUD*>(_guiCore->getMenu(HUD));
	  int score = 0;
	  for (auto it = _lstPlayer.begin(); it < _lstPlayer.end(); ++it)
	    {
	      (*it)->sendEvent(evt, _keyboard, (_joy == NULL ? NULL : &tmp));
	      tmpHUD->updatePV((*it)->getName(), (*it)->getPV());
	      score += (*it)->getScore();
	    }
	  tmpHUD->updateScore(score, _lstSpawner.size());
	  destroyObject();
	  if (checkVictory())
	    _endGame = 1;
	  else if (_lstPlayer.size() == 0)
	    _endGame = 2;
	  else
	    _camera->move(_lstPlayer);
	}
      else
	endParty();
    }
  return _loopCore;
}

void		Core::endParty()
{
  if (_doEndGame == false)
    {
      MenuDEAD *tmpHUD = dynamic_cast<MenuDEAD*>(_guiCore->getMenu(MENUDEAD));
      int score = 0;
      _soundSystem->pauseSound(_lstSound[2], true);
      if (_endGame == 1)
	{
	  _soundSystem->pauseSound(_lstSound[3], false);
	  for (auto it = _lstPlayer.begin(); it != _lstPlayer.end(); ++it)
	    score += (*it)->getScore();
	  save(score);
	  tmpHUD->showVic();
	}
      else
	{
	  tmpHUD->showDead();
	  _soundSystem->pauseSound(_lstSound[4], false);
	}
      _doEndGame = true;
    }
}

bool		Core::checkVictory()
{
  CheckCollision col = _colliders->check_if_collide(*_lstPlayer.begin());

  if (_diff)
    {
      if (col.entity)
	{
	  if (col.entity->getName() == std::string("sortie"))
	    return (true);
	}
      if (_lstPlayer.begin() + 1 != _lstPlayer.end())
	{
	  col = _colliders->check_if_collide(*_lstPlayer.begin() + 1);
	  if (col.entity)
	    if (col.entity->getName() == std::string("sortie"))
	      return (true);
	}
    }
  else
    {
      if (col.entity)
	{
	  if (col.entity->getName() == std::string("sortie") &&_lstSpawner.size() == 0)
	    return (true);
	}
      if (_lstPlayer.begin() + 1 != _lstPlayer.end())
	{
	  col = _colliders->check_if_collide(*_lstPlayer.begin() + 1);
	  if (col.entity)
	    if (col.entity->getName() == std::string("sortie") &&_lstSpawner.size() == 0)
	      return (true);
	}
    }
  return (false);
}
