//
// Object.hpp for Obejct in /home/rebut_p/Programmation/CPP/cpp_indie_studio/tmp/ogre/include/object
// 
// Made by Pierre Rebut
// Login   <rebut_p@epitech.net>
// 
// Started on  Mon May  9 16:18:24 2016 Pierre Rebut
// Last update Wed Jun  1 17:19:33 2016 Pierre Rebut
//

#ifndef		CPP_INDIE_STUDIO_OBJECT_HPP
# define	CPP_INDIE_STUDIO_OBJECT_HPP
# include	<map>
# include	<string>
# include	"AScenery.hpp"

class		Object : public AScenery
{
public:
  Object(std::map<std::string, std::string> &);
  ~Object();
};

#endif
