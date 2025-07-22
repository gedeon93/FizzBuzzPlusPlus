/**
 * @file RuleEngine.cpp
 *
 * Encapsulates Rule and RuleSet function implementations.
 */
#include <algorithm>

#include "RuleEngine.hpp"

const std::unordered_map<std::string, OP_TYPE> Rule::op_map = {
	{"append",  OP_APPEND},
	{"insert",  OP_INSERT},
	{"replace", OP_REPLACE},
	{"reverse", OP_REVERSE}
};

Rule::Rule(int condition, const std::string& tag, const std::string& opType, std::string referenceToken)
	: m_condition(condition), m_tag(tag), m_token(referenceToken)
{
	m_opType = parse_op_type(opType);
}

/**
 * @brief Checks if the rule's condition applies to the input number and mutates output accordingly.
 *
 * If the condition matches, performs the configured operation (append, insert, etc.) on the result vector.
 *
 * @param number Input number being evaluated.
 * @param vec Reference to the output tokens vector.
 * @return true if the rule was applied; false otherwise.
 */
bool Rule::valid_condition(int number, std::vector<std::string>& vec) const
{
	std::string curr = m_tag;
	bool condition_met = (number % m_condition) == 0;
	
	if (condition_met)
	{
		switch(m_opType)
		{
		case OP_REPLACE: vec.clear();
		case OP_APPEND: vec.push_back(curr); break;
		case OP_INSERT: 
		{
			if (m_token.empty())
				vec.insert(vec.begin(), curr); 
			else
			{
				unsigned int pos = 0;
				for (int i = 0; i < vec.size(); ++i)
				{
                    if (!vec[i].empty() && vec[i].rfind(m_token, 0) != std::string::npos)
                    {
                        pos = i;
                        break;
					}
				}
				vec.insert(vec.begin() + pos, curr);
			}
            break;
		}
		case OP_REVERSE: std::reverse(vec.begin(), vec.end()); break;
		case OP_NONE:
		default: return false;
		}
	}
	
	return condition_met;
}

/**
 * @brief Maps a string representation of an operation to its OP_TYPE enum.
 *
 * Converts input like "append" or "reverse" (case-insensitive) to the corresponding OP_TYPE.
 * Throws std::invalid_argument if the operation type is not recognized.
 *
 * @param str Operation string from config.
 * @return Corresponding OP_TYPE enum value.
 */
/*static*/ OP_TYPE Rule::parse_op_type(const std::string& str)
{
    auto it = op_map.find(str);
    if (it != op_map.end()) {
        return it->second;
    }
	return OP_NONE;
}

/**
 * @brief Evaluates all rules against a given number.
 *
 * Applies each rule's logic to the input number and builds the final output string.
 * Outputs the result to stdout.
 *
 * @param number The integer to evaluate against the configured rules.
 */
std::string RuleSet::Evaluate(int number)
{
	m_result.clear();
	std::string result;
	bool is_match = false;
	for (const auto& rulePtr : m_rules)
	{
		bool check = rulePtr->valid_condition(number, m_result);
		is_match = check || is_match;
    }
    
    if (is_match)
    {
    	if (m_result.empty())
    		result = std::to_string(number);
    	else
	    	for (int i = 0; i < m_result.size(); ++i)
    			result += m_result[i];
    }
    else
    	result = std::to_string(number);
    
    return result;
}