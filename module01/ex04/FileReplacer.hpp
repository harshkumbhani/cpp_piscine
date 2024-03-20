#ifndef FILEREPLACER_H
# define FILEREPLACER_H

#include <iostream>
#include <fstream>
#include <sstream>

class	FileReplacer
{
	private:
		std::string	_filename;
		std::string	_searchStr;
		std::string	_replaceStr;
		std::string	_buff;
		std::string	_outfile;
		std::string replaceOccurence(const std::string &source);

	public:
		FileReplacer(std::string filename, std::string searchStr, std::string replaceStr);
		~FileReplacer();
		void	replace();
};

#endif