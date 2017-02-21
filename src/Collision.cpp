//
// Collider.cpp for Collider in /home/rebut_p/Programmation/CPP/cpp_indie_studio
//
// Made by Pierre Rebut
// Login   <rebut_p@epitech.net>
//
// Started on  Wed Jun  1 19:42:35 2016 Pierre Rebut
// Last update Sun Jun  5 21:17:32 2016 Pierre Rebut
//

#include	"Collision.hpp"

CollisionTools::CollisionTools()
{
}

CollisionTools::~CollisionTools()
{
  _lstObj.clear();
}

void	CollisionTools::add_entity(ADrawable *elem)
{
  _lstObj.push_back(elem);
}

void	CollisionTools::delete_entity(ADrawable *elem)
{
  auto it = _lstObj.begin();

  while (it != _lstObj.end())
    {
      if (*it == elem)
	{
	  _lstObj.erase(it);
	  return ;
	}
      ++it;
    }
}

const CheckCollision	CollisionTools::check_if_collide(ADrawable *elem)
{
  CheckCollision	ret;
  Ogre::AxisAlignedBox	tmp;
  Ogre::AxisAlignedBox	tmp2;

  ret.collided = false;
  ret.entity = NULL;
  if (elem->getEnable() == false)
    return (ret);
  tmp = elem->getEntity()->getWorldBoundingBox(false);
  for (auto it = _lstObj.begin(); it != _lstObj.end();
       ++it)
    {
      if (*it != elem && (*it)->getEnable() == true &&
	  (*it)->docollide(elem->gettype()))
	{
	  tmp2 = (*it)->getEntity()->getWorldBoundingBox(false);
	  if (tmp.intersects(tmp2) == true)
	    {
	      ret.collided = true;
	      ret.entity = *it;
	      return (ret);
	    }
	}
    }
  return (ret);
}
