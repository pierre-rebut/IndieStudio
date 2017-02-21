//
// Spawner.hpp for Spawner in /home/rebut_p/Programmation/CPP/cpp_indie_studio/ogre/include/elems/perso
//
// Made by Pierre Rebut
// Login   <rebut_p@epitech.net>
//
// Started on  Mon May 16 15:25:08 2016 Pierre Rebut
// Last update Fri Jun  3 21:26:44 2016 Maxime Pavot
//

#ifndef		CPP_INDIE_STUDIO_SPAWNER_HPP
# define	CPP_INDIE_STUDIO_SPAWNER_HPP

# include	<map>
# include	<string>
# include	"AEntity.hpp"

class		Spawner : public AEntity
{
public:
  Spawner(std::map<std::string, std::string> &);
  ~Spawner();
  bool          docollide(ADrawable::type type);
};

#endif
