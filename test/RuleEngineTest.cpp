/**
 * @file RuleEngineTest.cpp
 *
 * Unit testing for FizzBuzz++ core functions.
 */
#include <iostream>

#include <algorithm>
#include <cassert>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
#include "../include/RuleEngine.hpp"  // Adjust path as needed

void test_valid_condition_append()
{
    Rule rule(3, "Fizz", "append");
    std::vector<std::string> output;
    bool applied = rule.valid_condition(6, output);

    assert(applied);
    assert(output.size() == 1 && output[0] == "Fizz");
}

// void test_valid_condition_insert()
// void test_valid_condition_replace()
// void test_valid_condition_reverse()

void test_valid_condition_insert_tokens()
{
    std::vector<std::string> tokens = {"B", "Bu", "Buz", "Buzz", "b"};
    std::vector<std::vector<std::string>> expected_result(tokens.size(), {"Fuzz", "Buzz"});
    for (int i = 0; i < tokens.size(); ++i)
    {
        Rule rule(11, "Fuzz", "insert", tokens[i]);
        std::vector<std::string> output = {"Buzz"};
        bool applied = rule.valid_condition(11, output);
        assert(applied && output == expected_result[i]);
    }
}

void test_parse_op_type_none()
{
    assert(Rule::parse_op_type("replace") == OP_REPLACE);
    assert(Rule::parse_op_type("inverse") == OP_NONE); // "inverse" is an unsupported operation
}

void test_ruleset_empty_rules()
{
    RuleSet rules;
    std::string output = rules.Evaluate(7);
    // Remove newlines for cross-platform compatibility
    output.erase(std::remove(output.begin(), output.end(), '\r'), output.end());
    output.erase(std::remove(output.begin(), output.end(), '\n'), output.end());
    assert(output == "7");
}

int main()
{
    test_valid_condition_append();
    // test_valid_condition_insert();
    // test_valid_condition_replace();
    // test_valid_condition_reverse();
    test_valid_condition_insert_tokens();
    test_parse_op_type_none();
    test_ruleset_empty_rules();

    std::cout << "All tests passed." << std::endl;

    return 0;
}