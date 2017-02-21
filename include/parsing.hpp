//
// parsing.hpp for parsing in /home/ikkar/CPP/cpp_indie_studio/parsing
// 
// Made by ikkar
// Login   <ikkar@epitech.net>
// 
// Started on  Tue May  3 16:52:54 2016 ikkar
// Last update Mon May  9 23:19:32 2016 Pierre Rebut
//

#include	<iostream>
#include	<string>
#include	<algorithm>
#include	<fstream>
#include	<sstream>
#include	<map>
#include	<utility>

#ifndef		_PARSING_HPP_
# define	_PARSING_HPP_
# include	<vector>
# include	"ADrawable.hpp"

class Parsing
{
  std::fstream	file;
  std::string	line;
  std::string	type;
  std::string	elem;
  size_t	nb_line = 0;
  std::map<std::string, std::string> obj_cara;

public:
  enum {OBJECT, LIGHT, PLANE};
  Parsing(const std::string &f);
  ~Parsing();

  void		aff_obj(void);
  std::string	&my_trim(std::string &)const;
  int		is_object(std::string &)const;
  size_t	value_exist();
  ADrawable	*getObjectParam();
  std::vector<ADrawable*>	parse();
};

#endif		/* !_PARSING_HPP_ */
