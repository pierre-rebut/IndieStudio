//
// Created by jeanma_e on 03/05/2016.
//

#ifndef CPP_INDIE_STUDIO_PLAYER_HPP
# define CPP_INDIE_STUDIO_PLAYER_HPP

# include <string>
# include "ACharacter.hpp"

class Player
{
  std::string _name;
  ACharacter *_job;
  size_t _score;
  size_t _up;
  size_t _down;
  size_t _left;
  size_t _right;
  size_t _attack;
  size_t _pause;
public:
  Player(const std::string &name = "Player");
  ~Player();
  void setUp(size_t);
  void setDown(size_t);
  void setLeft(size_t);
  void setRight(size_t);
  void setAttack(size_t);
  void setPause(size_t);
};

#endif //CPP_INDIE_STUDIO_PLAYER_HPP
