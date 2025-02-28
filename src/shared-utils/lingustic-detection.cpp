#include <filesystem>
#include <iostream>

using std::string;

string getFileExt(const string &s) {
  size_t DotIndex = s.find('.', s.length());
  if (DotIndex != string::npos) {
    return s.substr(DotIndex + 1, s.length() - 1);
  }
  return "";
}
