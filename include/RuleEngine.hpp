/**
 * @file RuleEngine.hpp
 *
 * Implements Rule and RuleSet classes for configurable FizzBuzz++ engine.
 * Contains logic for rule evaluation, operation mapping, and output generation.
 */
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

enum OP_TYPE
{
	OP_NONE,
	OP_APPEND,
	OP_INSERT,
	OP_REPLACE,
	OP_REVERSE,
};

/**
 * @brief Represents a single transformation rule applied to a number.
 *
 * Each rule defines a condition (e.g., divisible by 3) and an operation (e.g., append "Fizz").
 */
class Rule
{
public:
	Rule() = delete;
	Rule(int condition, const std::string& tag, const std::string& opType, std::string referenceToken = "");
	
	bool valid_condition(int number, std::vector<std::string>& vec) const;

	static OP_TYPE parse_op_type(const std::string& str);

private:
	int m_condition;
	std::string m_tag;
	int m_opType;
	std::string m_token;

	static const std::unordered_map<std::string, OP_TYPE> op_map;
};

/**
 * @brief Manages and applies a set of Rule objects to evaluate integer input.
 */
class RuleSet 
{
public:
	RuleSet() {}
	
	std::string Evaluate(int number);
	inline void Add(int condition, const std::string& tag, const std::string& opType, const std::string& token = "") 
    { 
        m_rules.push_back(std::make_unique<Rule>(condition, tag, opType, token)); 
    }
	
private:
	std::vector<std::unique_ptr<Rule>> m_rules;
	std::vector<std::string> m_result;
};



