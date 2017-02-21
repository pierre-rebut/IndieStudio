//
// SoundClass.hpp for SoundClass in /home/rebut_p/Programmation/CPP/cpp_indie_studio/ogre
// 
// Made by Pierre Rebut
// Login   <rebut_p@epitech.net>
// 
// Started on  Sun May 15 16:07:02 2016 Pierre Rebut
// Last update Sun Jun  5 00:50:16 2016 Pierre Rebut
//

#ifndef		CPP_INDIE_STUDIO_SOUNDCLASS_HPP
# define	CPP_INDIE_STUDIO_SOUNDCLASS_HPP
# include	<string>
# include	"fmod.hpp"
# include	"fmod_errors.h"

struct		SoundObject
{
  FMOD::Sound	*_sound;
  FMOD::Channel	*_channel;
};

class		SoundClass
{
  FMOD::System	*_system;

public:
  SoundClass();

  SoundObject	createSound(const std::string &);
  void		playSound(SoundObject &Sound, bool bLoop = false, const float = 1);
  void		releaseSound(SoundObject &Sound);
  void		pauseSound(SoundObject &sound, const bool);
};

#endif
