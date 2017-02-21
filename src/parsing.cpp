//
// parsing.cpp for parsing in /home/ikkar/CPP/cpp_indie_studio/parsing
// 
// Made by ikkar
// Login   <ikkar@epitech.net>
// 
// Started on  Tue May  3 17:24:19 2016 ikkar
// Last update Sat Jun  4 17:31:32 2016 Pierre Rebut
//

#include	<vector>
#include	<iterator>
#include	<ctype.h>

#include	"parsing.hpp"
#include	"Object.hpp"
#include	"Light.hpp"
#include	"Plane.hpp"
#include	"Spawner.hpp"

const static char *list_obj[] = { "OBJECT", "SPAWN", "LIGHT", "PLANE", NULL };

Parsing::Parsing(const std::string &str)
{
  file.open(str, std::fstream::in);
}

Parsing::~Parsing()
{
}

void	Parsing::aff_obj(void)
{
  for (std::map<std::string, std::string>::const_iterator it = obj_cara.begin() ; it != obj_cara.end() ; it++)
    std::cout << obj_cara[(*it).first] << std::endl;
}

std::string &Parsing::my_trim(std::string &s)const
{
  s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
  s.erase(std::remove(s.begin(), s.end(), '\t'), s.end());
  return s;
}

int	Parsing::is_object(std::string &s)const
{
  int	i = 0;

  while (list_obj[i])
    {
      if (std::string (list_obj[i]) == s)
	return i;
      i++;
    }
  return -1;
}

size_t	Parsing::value_exist()
{
  for (std::map<std::string, std::string>::iterator it = obj_cara.begin() ; it != obj_cara.end() ; it++)
    {
      if (obj_cara[(*it).first] == "")
	{
	  std::cerr << "ERROR : VALUE CAN'T BE EMPTY" << std::endl;
	  return 1;
	}
    }
  return 0;
}

ADrawable			*Parsing::getObjectParam()
{
  ADrawable			*tmp;

  getline(file, line);
  nb_line++;
  std::stringstream buf;
  while (line != ("/" + type))
    {
      line = my_trim(line);
      if (line[0] != '#')
	buf << line << "\n";
      getline(file, line);
      nb_line++;
      if (file.eof())
	throw std::runtime_error("bad object");
    }
  buf >> elem;
  while (!buf.eof())
    {
      if (obj_cara[elem.substr(0, elem.find("="))] != "")
	std::cerr << "Warning : redefinition variable : " << elem.substr(0, elem.find("="))  <<
	  ", type : " << type << "(line " << nb_line - 1  <<"), older value : " << obj_cara[elem.substr(0, elem.find("="))] <<
	  ", new value : " << elem.substr(elem.find("=") + 1, elem.size()) << std::endl;
      obj_cara[elem.substr(0, elem.find("="))] = elem.substr(elem.find("=") + 1, elem.size());
      buf >> elem;
    }
  value_exist();
  if (type == "LIGHT")
    tmp = new Light(obj_cara);
  else if (type == "PLANE")
    tmp = new Plane(obj_cara);
  else if (type == "SPAWN")
    tmp = new Spawner(obj_cara);
  else
    tmp = new Object(obj_cara);
  obj_cara.clear();
  return tmp;
}

std::vector<ADrawable *>	Parsing::parse()
{
  std::vector<ADrawable *>	lstObject;

  if (file.is_open())
    {
      while (getline (file, type))
	{
	  nb_line++;
	  type = my_trim(type);
	  if (is_object(type) != -1)
	    {
	      lstObject.push_back(getObjectParam());
	    }
	  else if (type != "" && type[0] != '#')
	    throw std::runtime_error("ERROR : THIS OBJECT DOSN'T EXIST");
	}
      file.close();
    }
  else
    throw std::runtime_error("ERROR : CAN'T OPEN");
  return lstObject;
}
