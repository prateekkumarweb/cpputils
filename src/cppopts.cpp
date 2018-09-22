#include "cppopts.h"
#include <regex>
#include <iostream>

namespace cppopts {
    Option::Option() {
        key = "";
        value = "";
        desc = "";
        short_key = 0;
    }

    Option::Option(std::string key, char short_key, std::string desc, std::string value) {
        this->key = key;
        this->short_key = short_key;
        this->desc = desc;
        this->value = value;
    }

    std::string Option::getKey() {
        return key;
    }

    void Option::setValue(std::string val) {
        value = val;
    }

    std::string Option::getString() {
        return value;
    }

    int Option::getInt() {
        return std::stoi(value);
    }

    void Options::parse(int argc, char **argv) {
        for (int i=1; i<argc; i++) {
            parse(std::string(argv[i]));
        }
    }

    void Options::addOption(std::string key, char short_key, std::string desc, std::string default_value) {
        if (short_key != 0) short_keys[short_key] = key;
        options[key] = Option(key, short_key, desc, default_value);
    }

    void Options::parse(std::string opt) {
        std::regex single_dash("-([a-zA-Z0-9]+)");
        std::regex double_dash("--([a-zA-Z0-9]+)(=.+)?");
        std::smatch match;
        if(std::regex_match(opt, match, single_dash)) {
            std::string opts = match[1];
            for (int i=0; i<opts.length(); i++) {
                if (opts[i] != 0) {
                    options[short_keys[opt[i]]].setValue("1");
                }
            }
        } else if(std::regex_match(opt, match, double_dash)) {
            std::string key = match[1];
            std::string val = match[2];
            if (val == "") {
                options[key].setValue("1");
            } else {
                val = val.substr(1);
                options[key].setValue(val);
            }
        } else {
            std::cerr << "Invalid command line arguments" << std::endl;
        }
    }

    Option Options::operator[](std::string key) {
        return options[key];
    }
}