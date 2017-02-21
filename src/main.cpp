//
// main.cpp for main in /home/rebut_p/Programmation/CPP/tmp
// 
// Made by Pierre Rebut
// Login   <rebut_p@epitech.net>
// 
// Started on  Wed Apr 27 09:32:09 2016 Pierre Rebut
// Last update Wed Jun  1 16:33:21 2016 Pierre Rebut
//

#include	<exception>
#include	<iostream>

#include	"Core.hpp"

int	main()
{
  try
    {
      Core *core = new Core;
      core->startOgre();
      delete core;
    }
  catch (std::exception const &e)
    {
      std::cerr << e.what() << std::endl;
    }
  return (0);
}
