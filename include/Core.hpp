//
// Core.hpp for Core in /home/rebut_p/Programmation/CPP/cpp_indie_studio/tmp/ogre
//
// Made by Pierre Rebut
// Login   <rebut_p@epitech.net>
//
// Started on  Sun May  1 15:34:12 2016 Pierre Rebut
// Last update Sun Jun  5 23:06:59 2016 Pierre Rebut
//

#ifndef		CORE_HPP__
# define	CORE_HPP__

# include	<vector>
# include	"OIS/OIS.h"
#include	"OgreTimer.h"
# include	"OgreCore.hpp"
# include	"Collision.hpp"
# include	"SoundClass.hpp"
# include	"EnemySystem.hpp"
# include	"GUICore.hpp"
# include	"Spawner.hpp"
# include	"Camera.hpp"
# include	"ACharacter.hpp"

void		save(int);

class		Core :
  public Ogre::FrameListener, public Ogre::WindowEventListener, public OIS::KeyListener, public OIS::MouseListener
{
  bool			_doEndGame;
  int			_endGame;
  bool			_loopCore;
  bool			_startGame;

  OgreCore		*_core;
  Camera		*_camera;
  GUICore		*_guiCore;

  Ogre::RenderWindow	*_window;
  OIS::InputManager	*_inputMgr;
  OIS::Mouse		*_mouse;
  OIS::Keyboard		*_keyboard;
  OIS::JoyStick		*_joy;

  SoundClass			*_soundSystem;
  CollisionTools		*_colliders;

  std::vector<SoundObject>	_lstSound;

  std::vector<ACharacter *>	_lstPlayer;
  std::vector<Spawner*>		_lstSpawner;
  EnemySystem			*_enemySystem;

  bool				_intro;
  Ogre::Timer			*_timer;
  std::vector<ADrawable*>	_lstObj;
  bool				_diff;

  void			startOIS();
  void			windowResized(Ogre::RenderWindow *);
  void			windowClosed(Ogre::RenderWindow *);

  void			deleteScene();
  void			createScene(const std::string &, CollisionTools * = NULL);
  void			loadGame();
  void			destroyObject();

  void			endParty();

public:
  Core();
  ~Core();

  void		startOgre();
  void		exitGame();
  void		changeDifficulter();
  void		startGameOnePlayer();
  void		startGameTwoPlayer();

  bool		keyPressed(const OIS::KeyEvent &);
  bool		keyReleased(const OIS::KeyEvent &);
  bool		mouseMoved(const OIS::MouseEvent& arg);
  bool		mousePressed(const OIS::MouseEvent &arg,OIS::MouseButtonID id);
  bool		mouseReleased(const OIS::MouseEvent&, OIS::MouseButtonID);
  bool		frameRenderingQueued(const Ogre::FrameEvent &);
  bool		checkVictory();
};

#endif
