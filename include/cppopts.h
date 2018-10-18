#ifndef _CPPOPTS_H_
#define _CPPOPTS_H_

#include <map>
#include <string>

namespace cppopts {

template <typename T>
class Option {
 public:
  Option();
  Option(std::string key, char short_key, std::string desc, T value);
  std::string getKey();
  void setValue(T val);
  T getValue();

 private:
  std::string key;
  T value;
  std::string desc;
  char short_key;
};

class Options {
 public:
  Option<std::string> operator[](std::string key);
  void parse(int argc, char **argv);
  void addOption(std::string key, char short_key, std::string desc,
                 std::string default_value = "");

 private:
  std::map<std::string, Option<std::string>> options;
  std::map<char, std::string> short_keys;
  void parse(std::string opt);
};
}  // namespace cppopts

#endif
