//
// SoundClass.cpp for Sound in /home/rebut_p/Programmation/CPP/cpp_indie_studio/ogre
// 
// Made by Pierre Rebut
// Login   <rebut_p@epitech.net>
// 
// Started on  Sun May 15 16:08:59 2016 Pierre Rebut
// Last update Sun Jun  5 01:01:58 2016 Pierre Rebut
//

#include	<stdexcept>
#include	"SoundClass.hpp"

SoundClass::SoundClass()
{
  int	driverCount = 0;

  if (FMOD::System_Create(&_system) != FMOD_OK)
    throw std::runtime_error("Error: SOUND: can't init system FMOD");
  _system->getNumDrivers(&driverCount);
  if (driverCount == 0)
    throw std::runtime_error("Error: SOUND: no sound driver found");
  _system->init(10, FMOD_INIT_NORMAL, NULL);
}

SoundObject	SoundClass::createSound(const std::string &file)
{
  SoundObject	sound;

  _system->createSound(file.c_str(), FMOD_DEFAULT, 0, &sound._sound);
  sound._channel = NULL;
  return (sound);
}

void		SoundClass::playSound(SoundObject &sound, const bool bLoop,
				      const float volume)
{
  if (!bLoop)
    sound._sound->setMode(FMOD_LOOP_OFF);
  else
    {
      sound._sound->setMode(FMOD_LOOP_NORMAL);
      sound._sound->setLoopCount(-1);
    }
  _system->playSound(sound._sound, NULL, false, &sound._channel);
  sound._channel->setVolume(volume);
}

void		SoundClass::pauseSound(SoundObject &sound, const bool val)
{
  if (val == true)
    sound._channel->stop();
  else
    _system->playSound(sound._sound, NULL, false, &sound._channel);
}

void		SoundClass::releaseSound(SoundObject &sound)
{
  sound._sound->release();
}
