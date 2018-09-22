#ifndef _CPPOPTS_H_
#define _CPPOPTS_H_ 

#include <string>
#include <map>

namespace cppopts {
    class Option {
    public:
        Option();
        Option(std::string key, char short_key, std::string desc, std::string value);
        std::string getKey();
        void setValue(std::string val);
        std::string getString();
        int getInt();
    private:
        std::string key;
        std::string value;
        std::string desc;
        char short_key;
    };

    class Options {
    public:
        Option operator[](std::string key);
        void parse(int argc, char **argv);
        void addOption(std::string key, char short_key, std::string desc, std::string default_value = "");
    private:
        std::map<std::string, Option> options;
        std::map<char, std::string> short_keys;
        void parse(std::string opt);
    };
}

#endif