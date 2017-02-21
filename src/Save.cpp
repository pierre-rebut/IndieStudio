//
// Save.cpp for indi in /home/ikkar/CPP/cpp_indie_studio/src
// 
// Made by ikkar
// Login   <ikkar@epitech.net>
// 
// Started on  Sat Jun  4 22:39:47 2016 ikkar
// Last update Sun Jun  5 23:11:41 2016 Pierre Rebut
//

#include        <iostream>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<sstream>
#include	<fstream>
#include	<string>
#include	<vector>
#include	<algorithm>

bool compare(int i, int j)
{
  return (i > j);
}

void    save(int score)
{
  std::string		repo = "./save";
  time_t temps;
  struct tm datetime;
  std::string file;
  char  format[32];
  std::string	line;
  std::vector<int>	lst_score;
  std::vector<std::string>	lst_time;

  mkdir(repo.c_str(), 0777);
  file = repo + "/" + "save.txt";
  time(&temps);
  datetime = *localtime(&temps);
  strftime(format, 32, "%d/%m/%Y %H:%M", &datetime);
  std::ifstream		file_name(file, std::ios::in);

  if (file_name)
    {
      lst_time.push_back(format);
      lst_score.push_back(score);
      while (getline(file_name, line))
	{
	  lst_time.push_back(line.substr(0, line.find('|')));
	  lst_score.push_back(atoi((line.substr(line.find('|') + 1, line.size())).c_str()));
	}
      std::sort (lst_score.begin(), lst_score.end(), compare);
      file_name.close();
    }
  std::ofstream		of_name(file, std::ofstream::out);
  if (of_name)
    {
      size_t	i = 0;
      while (i < lst_score.size())
	{
	  of_name << lst_time[i] << '|' << lst_score[i] << std::endl;
	  i++;
	}
    }
  of_name.close();
}
