//
// EnemySystem.hpp for EnemySystem in /home/rebut_p/Programmation/CPP/cpp_indie_studio/ogre/include/elems
// 
// Made by Pierre Rebut
// Login   <rebut_p@epitech.net>
// 
// Started on  Mon May 16 14:31:40 2016 Pierre Rebut
// Last update Sun Jun  5 18:27:28 2016 Pierre Rebut
//

#ifndef		CPP_INDIE_STUDIO_ENEMYSYSTEM_HPP
# define	CPP_INDIE_STUDIO_ENEMYSYSTEM_HPP

# include	<vector>
# include	<string>
# include	<thread>

# include	"Ogre.h"
# include	"Collision.hpp"
# include	"AEnemy.hpp"
# include	"Spawner.hpp"
# include	"ACharacter.hpp"
# include	"APickable.hpp"

class		EnemySystem
{
  std::vector<AEnemy *>		_lstEnemy;
  std::vector<APickable *>	_lstBonus;
  std::vector<Spawner*> *	_lstSpawner;

  long				_time;
  std::vector<ACharacter*>	*_player;
  Ogre::SceneManager		*_sceneMgr;
  int				index_spawner;

  void			createNewEnemy(AEnemy *);

public:
  EnemySystem(const std::string &file, size_t,
	      std::vector<Spawner *> *lstSpawner,
	      Ogre::SceneManager *, CollisionTools *, std::vector<ACharacter*>*);
  ~EnemySystem();

  void		notifyReady(const Ogre::FrameEvent &evt);
};

#endif
