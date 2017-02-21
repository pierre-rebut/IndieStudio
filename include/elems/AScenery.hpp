//
// AScenery.hpp for cpp_indie_studio in /home/pavot_m/cpp_indie_studio
//
// Made by Maxime Pavot
// Login   <pavot_m@epitech.net>
//
// Started on  Fri Apr 29 15:06:59 2016 Maxime Pavot
// Last update Fri Jun  3 21:12:57 2016 Maxime Pavot
//

#ifndef CPP_INDIE_STUDIO_ASCENERY_HPP
#define CPP_INDIE_STUDIO_ASCENERY_HPP
#include	"ADrawable.hpp"

class AScenery : public ADrawable
{
public:
  virtual ~AScenery(){}
  bool	docollide(ADrawable::type type);
};

#endif //CPP_INDIE_STUDIO_ASCENERY_HPP
