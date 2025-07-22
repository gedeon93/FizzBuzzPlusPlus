/*
 * FizzBuzz++: An advanced and extensible FizzBuzz exercise.
 */

#include <iostream>

#include <algorithm>
#include <fstream>

#include "RuleEngine.hpp"

#include <nlohmann/json.hpp>
using json = nlohmann::json;
using namespace std;

bool LoadConfig(const std::string &configFile, RuleSet &ruleSet);

int main(int argc, char *argv[])
{
    std::string appMode = "default";
    unsigned int start_number = 1;
    unsigned int end_number = 100;
    std::string configFile;

    if (argc >= 2)
        appMode = argv[1];

    if (appMode == "range" && argc == 4)
    {
        start_number = std::stoi(argv[2]);
        end_number = std::stoi(argv[3]);
    }
    else if (appMode == "config" && argc >= 3)
    {
        configFile = argv[2];
        if (argc >= 5)
        {
            start_number = std::stoi(argv[3]);
            end_number = std::stoi(argv[4]);
        }
    }
    else if (appMode != "default")
    {
        std::cerr << "Usage format:\n"
                  << "  default\n"
                  << "  range [start] [end]"
                  << "  config <json_file> [start] [end]\n";
    }

    if (start_number > end_number || start_number < 1)
    {
        std::cerr << "Invalid range provided via input.\n";
        return 1;
    }

    RuleSet ruleSet;

    // User-specified rule set.
    if (appMode == "config")
    {
        if (!LoadConfig(configFile, ruleSet))
            return 1;
    }
    // ChatGPT's challenge rule set.
    else
    {
        ruleSet.Add(3, "Fizz", "append");
        ruleSet.Add(5, "Buzz", "append");
        ruleSet.Add(7, "Bang", "append");
        ruleSet.Add(11, "Bong", "replace");
        ruleSet.Add(13, "Fezz", "insert", "B");
        ruleSet.Add(17, "", "reverse");
    }

    for (int i = start_number; i <= end_number; ++i)
    {
        std::cout << ruleSet.Evaluate(i) << std::endl;
    }

    return 0;
}

/**
 * @brief Loads rule configuration from a JSON file.
 *
 * @param filepath Path to the JSON file containing rules.
 * @param out Reference to a json object to populate.
 * @return true if the file was successfully opened and parsed; false otherwise.
 */
bool LoadConfig(const std::string &configFile, RuleSet &ruleSet)
{
    std::ifstream file(configFile);
    if (!file.is_open())
    {
        std::cerr << "Error: Failed to open file: " << configFile << std::endl;
        std::cerr << "Working directory: " << std::filesystem::current_path() << std::endl;
        return false;
    }

    json rules;
    try
    {
        rules = json::parse(file);
    }
    catch (const std::exception &e)
    {
        std::cerr << "JSON parse error: " << e.what() << std::endl;
        return false;
    }

    for (const auto &rule : rules)
    {
        int condition = rule["condition"];
        std::string tag = rule["tag"];
        std::string opStr = rule["op"];
        std::string token = rule["token"];

        ruleSet.Add(condition, tag, opStr, token);
    }

    return true;
}