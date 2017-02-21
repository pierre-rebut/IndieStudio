//
// EnemySystem.cpp for EnemySystem in /home/rebut_p/Programmation/CPP/cpp_indie_studio/ogre
//
// Made by Pierre Rebut
// Login   <rebut_p@epitech.net>
//
// Started on  Mon May 16 14:49:07 2016 Pierre Rebut
// Last update Sun Jun  5 23:34:21 2016 Pierre Rebut
//

#include	<ctime>
#include	<iostream>
#include	<stdexcept>
#include	"Spawner.hpp"
#include	"Enemy.hpp"
#include	"EnemySystem.hpp"
#include	"Bonus.hpp"
#include	"Malus.hpp"

EnemySystem::EnemySystem(const std::string &file, size_t limit, std::vector<Spawner *> *lstSpawner,
			 Ogre::SceneManager *sceneMgr, CollisionTools *colliders, std::vector<ACharacter*> *player)
{
  std::srand(std::time(0));
  _time = 0;
  _sceneMgr = sceneMgr;
  for (size_t i = 0; i < limit; i++)
    {
      _lstEnemy.push_back(new Enemy("enemy_" + std::to_string(i), "ninja.mesh",
				    file, sceneMgr, colliders, player));
    }
  for (int i = 0; i < 50; i++)
    {
      _lstBonus.push_back(new Bonus(i, sceneMgr, colliders));
      _lstBonus.push_back(new Malus(i, sceneMgr, colliders));
    }
  _lstSpawner = lstSpawner;
  _player = player;
  index_spawner = 0;
}

EnemySystem::~EnemySystem()
{
  for (auto it = _lstEnemy.begin(); it != _lstEnemy.end(); ++it)
    {
      delete *it;
    }
  for (auto it = _lstBonus.begin(); it != _lstBonus.end(); ++it)
    {
      delete *it;
    }
}

void		EnemySystem::notifyReady(const Ogre::FrameEvent &evt)
{
  for (auto it = _lstEnemy.begin(); it != _lstEnemy.end(); ++it)
    {
      if ((*it)->getEnable() == true)
	{
	  if ((*it)->execOneFrame(evt) == false && std::rand() % 3 != 0)
	    {
	      auto i2 = std::rand() % _lstBonus.size();
	      if (_lstBonus.at(i2)->getEnable() == false)
		{
		  _lstBonus.at(i2)->popObject((*it)->getPosition());
		  (*it)->setPosition(Ogre::Vector3(-500, 0, 0));
		  break;
		}
	    }
	}
    }
  if (_time + 1 < std::time(NULL))
    {
      for (auto it = _lstEnemy.begin(); it != _lstEnemy.end(); ++it)
	{
	  if ((*it)->getEnable() == false)
	    {
	      createNewEnemy(*it);
	      break;
	    }
	}
      _time = std::time(NULL);
    }
}

void		EnemySystem::createNewEnemy(AEnemy *id)
{
  if (_lstSpawner->size() == 0)
    return;
  auto player = _player->at(0)->getPosition();
  std::sort (_lstSpawner->begin(), _lstSpawner->end(),[player](Spawner *first, Spawner *second){
      Ogre::Vector3	pos_1;
      Ogre::Vector3	pos_2;
      Ogre::Vector3	pos_P;
      int		x;
      int		z;
      int		x1;
      int		z1;

      pos_1 = first->getPosition();
      pos_2 = second->getPosition();
      x = pos_1.x;
      z = pos_1.z;
      x1 = pos_2.x;
      z1 = pos_2.z;
      return ((abs(player.x - x) + abs(player.z - z)) <= (abs(player.x - x1) + abs(player.z - z1)));
    });
  if (index_spawner == 4 || index_spawner >= (int)_lstSpawner->size())
    index_spawner = 0;
  id->spawnEnemy(_lstSpawner->at(index_spawner)->getPosition());
  index_spawner++;
}
