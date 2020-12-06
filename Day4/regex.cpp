#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <unordered_map>
#include <functional>
#include <list>

int main() {
    // Read input
    std::ifstream file("input.txt");
    std::vector<std::string> passports{};
    std::string passport{};
    
    for (std::string line; std::getline(file, line);) {
        if (line.empty()) {
            passports.push_back(passport);
            passport = "";
            continue;
        }
        if (passport.length() > 0) {
            passport += " ";
        }
        
        passport += line;
    }
    passports.push_back(passport);

    // Part one
    const std::regex regex("([a-zA-Z0-9_]+):([^\r\n\t\f\v ]+)");
    int num_valids = 0;

    for (const std::string& passport : passports) {
        std::vector<std::string> required_keys{};

        std::smatch match;
        std::string::const_iterator search(passport.cbegin());
        while (regex_search(search, passport.cend(), match, regex))
        {
            const std::string& key = match[1].str();
            // cid is not required
            if (key != "cid") {
                required_keys.push_back(key);
            }
            search = match.suffix().first;
        }

        if (required_keys.size() == 7) {
            num_valids++;
        }
    }

    // Part two
    const std::unordered_map<std::string, const std::function<bool(const std::string&)>> validators{
        {"byr", [](const std::string& value) -> bool {
            return value.length() == 4 && std::stoi(value) >= 1920 && std::stoi(value) <= 2002;
        }},
        {"iyr", [](const std::string& value) -> bool {
            return value.length() == 4 && std::stoi(value) >= 2010 && std::stoi(value) <= 2020;
        }},
        {"eyr", [](const std::string& value) -> bool {
            return value.length() == 4 && std::stoi(value) >= 2020 && std::stoi(value) <= 2030;
        }},
        {"hgt", [](const std::string& value) -> bool {
            std::smatch match;
            if (regex_match(value.cbegin(), value.cend(), match, std::regex("([0-9]+)(cm|in)"))) {
                if (match[2].str() == "cm") return std::stoi(match[1].str()) >= 150 && std::stoi(match[1].str()) <= 193;
                if (match[2].str() == "in") return std::stoi(match[1].str()) >= 59 && std::stoi(match[1].str()) <= 76;
                return false;
            }
            return false;
        }},
        {"hcl", [](const std::string& value) -> bool {
            return regex_match(value.cbegin(), value.cend(), std::regex("#([0-9]|[a-f]){6}+"));
        }},
        {"ecl", [](const std::string& value) -> bool {
            const std::list<std::string> valid_values{
                "amb", "blu", "brn", "gry", "grn", "hzl", "oth"
            };
            return std::find(valid_values.begin(), valid_values.end(), value) != valid_values.end();
        }},
        {"pid", [](const std::string& value) -> bool {
            return regex_match(value.cbegin(), value.cend(), std::regex("[0-9]{9}+"));
        }},
    };

    num_valids = 0;

    for (const std::string& passport : passports) {
        std::vector<std::string> required_keys{};

        std::smatch match;
        std::string::const_iterator search(passport.cbegin());
        while (regex_search(search, passport.cend(), match, regex))
        {
            const std::string& key = match[1].str(), value = match[2].str();
            if (key != "cid" && validators.at(key)(value)) { 
                required_keys.push_back(key);
            }
            search = match.suffix().first;
        }

        if (required_keys.size() == 7) {
            num_valids++;
        }
    }

    std::cout << "Number of valid passports: " << num_valids << std::endl;

    file.close();
    return 0;
}