//
// OgreCore.cpp for Ogre in /home/rebut_p/Programmation/CPP/tmp
// 
// Made by Pierre Rebut
// Login   <rebut_p@epitech.net>
// 
// Started on  Wed Apr 27 10:09:35 2016 Pierre Rebut
// Last update Sun Jun  5 17:25:12 2016 Pierre Rebut
//

#include	<stdexcept>
#include	"OgreCore.hpp"

OgreCore::OgreCore()
{
  _log = new Ogre::LogManager();
  _log->createLog("./config/ogre.log", true, false, false);
  _root = new Ogre::Root("./config/plugins.cfg", "./config/ogre.cfg");
  if (_root == NULL)
    throw std::runtime_error("Error: OgreCore: can't init root var");
  getConfigResources("./config/resources.cfg");
  if (!(_root->restoreConfig() || _root->showConfigDialog()))
    throw std::runtime_error("Error: Root Ogre: can't init root");
  _window = _root->initialise(true, "Gauntlet");

  Ogre::TextureManager::getSingleton().setDefaultNumMipmaps(5);
  Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();

  _sceneMgr = _root->createSceneManager(Ogre::ST_GENERIC);
  _sceneMgr->setAmbientLight(Ogre::ColourValue(0.1, 0.1, 0.1));
}

Ogre::RenderWindow	*OgreCore::getRenderWindow() const
{
  return (_window);
}

Ogre::Root		*OgreCore::getRoot() const
{
  return _root;
}

void		OgreCore::getConfigResources(const std::string &file)
{
  Ogre::ConfigFile	configFile;
  Ogre::String		secName, typeName, archName;

  configFile.load(file);
  Ogre::ConfigFile::SectionIterator it = configFile.getSectionIterator();
  while (it.hasMoreElements())
    {
      secName = it.peekNextKey();
      Ogre::ConfigFile::SettingsMultiMap *settings = it.getNext();
      Ogre::ConfigFile::SettingsMultiMap::iterator i;
      for (i = settings->begin(); i != settings->end(); ++i)
	{
	  typeName = i->first;
	  archName = i->second;
	  Ogre::ResourceGroupManager::getSingleton().addResourceLocation(
	      archName, typeName, secName);
	}
    }
}

void	OgreCore::run()
{
  _root->startRendering();
}

OgreCore::~OgreCore()
{
  delete _root;
  delete _log;
}

Ogre::SceneManager	*OgreCore::getSceneManager() const
{
  return _sceneMgr;
}
