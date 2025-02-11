#include <iostream>
#include <stack>
#include <unordered_map>

bool isValid(std::string s)
{
    std::stack<char> stack;
    std::unordered_map<char, char> mapping = {
        {')', '('},
        {']', '['},
        {'}', '{'}};

    for (char ch : s)
    {

        if (mapping.find(ch) != mapping.end())
        {

            if (stack.empty() || stack.top() != mapping[ch])
            {
                return false;
            }

            stack.pop();
        }
        else
        {
            stack.push(ch);
        }
    }
    return stack.empty();
}

int main()
{
    // Test cases
    std::cout << std::boolalpha;
    std::cout << isValid("()") << std::endl;
    std::cout << isValid("()[]{}") << std::endl;
    std::cout << isValid("(]") << std::endl;
    std::cout << isValid("([)]") << std::endl;
    std::cout << isValid("{[]}") << std::endl;
    std::cout << isValid("([{}])") << std::endl;
    std::cout << isValid("([{}])(]") << std::endl;

    return 0;
}