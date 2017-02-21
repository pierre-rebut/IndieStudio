//
// Enemy.hpp for Enemy in /home/rebut_p/Programmation/CPP/cpp_indie_studio/ogre/include/elems/perso
//
// Made by Pierre Rebut
// Login   <rebut_p@epitech.net>
//
// Started on  Mon May 16 15:25:08 2016 Pierre Rebut
// Last update Sun Jun  5 16:15:30 2016 Pierre Rebut
//

#ifndef		CPP_INDIE_STUDIO_ENEMY_HPP
# define	CPP_INDIE_STUDIO_ENEMY_HPP

# include	<string>
# include	"AEnemy.hpp"
# include	"Collision.hpp"

class		Enemy : public AEnemy
{
public:
  Enemy(const std::string &, const std::string &,
	const std::string &, Ogre::SceneManager *,
	CollisionTools *, std::vector<ACharacter*> *);
  ~Enemy();

  bool			execOneFrame(const Ogre::FrameEvent &);
  Ogre::Vector3		focusPlayer(void);
};

#endif
