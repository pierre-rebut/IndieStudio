//
// Collision.hpp for Collision in /home/rebut_p/Programmation/CPP/cpp_indie_studio
// 
// Made by Pierre Rebut
// Login   <rebut_p@epitech.net>
// 
// Started on  Wed Jun  1 19:38:33 2016 Pierre Rebut
// Last update Thu Jun  2 13:30:35 2016 Pierre Rebut
//

#ifndef		CPP_INDIE_COLLIDER_HPP
# define	CPP_INDIE_COLLIDER_HPP

# include	<vector>
# include	"Ogre.h"

# include	"ADrawable.hpp"

struct		CheckCollision
{
  bool		collided;
  ADrawable	*entity;
};

class		CollisionTools
{
  std::vector<ADrawable*>  _lstObj;

public:
  CollisionTools();
  ~CollisionTools();

  void		add_entity(ADrawable *);
  void		delete_entity(ADrawable *);

  const CheckCollision check_if_collide(ADrawable *);
};
#endif
