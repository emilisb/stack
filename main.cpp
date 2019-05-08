#include <iostream> 
#include "stack.h"

void showstack(stack <int> s)
{
    while (!s.empty())
    {
        std::cout << '\t' << s.top();
        s.pop();
    }
    std::cout << '\n';
}

int main()
{
    stack <int> s;
    s.push(10);
    s.push(30);
    s.push(20);
    s.push(5);
    s.push(1);

    std::cout << "The stack is : ";
    showstack(s);

    std::cout << "\ns.size() : " << s.size();
    std::cout << "\ns.top() : " << s.top();

    std::cout << "\ns.pop() : ";
    s.pop();
    showstack(s);
    std::cout << "\ns.size() : " << s.size();

    return 0;
}