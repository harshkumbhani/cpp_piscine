#include "FileReplacer.hpp"

FileReplacer::FileReplacer(std::string filename, std::string searchStr,
                           std::string replaceStr)
    : _filename(filename), _searchStr(searchStr), _replaceStr(replaceStr) {}

FileReplacer::~FileReplacer() {}

void FileReplacer::replace() {

  std::ifstream inputFile(_filename.c_str());
  if (inputFile.fail() == true) {
    std::cerr << "Could not open the input file: " << _filename << std::endl;
    return;
  }
  if (_searchStr.empty() == true) {
    std::cerr << "Search string cannot be empty" << std::endl;
    return;
  }

  std::ofstream outputFile((_filename + ".replace").c_str());
  if (outputFile.fail() == true) {
    std::cerr << "Could not create output file: " << _filename + ".replace"
              << std::endl;
    return;
  }
  _buff.assign(std::istreambuf_iterator<char>(inputFile),
               std::istreambuf_iterator<char>());
  _outfile = replaceOccurence(_buff);
  outputFile << _outfile;
  inputFile.close();
  outputFile.close();
  return;
}

std::string FileReplacer::replaceOccurence(const std::string &source) {
  std::string result;
  size_t lastPos = 0, findPos;

  while ((findPos = source.find(_searchStr, lastPos)) != std::string::npos) {
    result.append(source, lastPos, findPos - lastPos);
    result += _replaceStr;
    lastPos = findPos + _searchStr.length();
  }
  result += source.substr(lastPos);
  return result;
}
