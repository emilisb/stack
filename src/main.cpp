#include <iostream> 
#include "stack.h"

void showstack(stack <int> s)
{
    std::cout << "The stack is : ";
    while (!s.empty())
    {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;
}

int main()
{
    stack <int> s;
    s.push(10);
    s.push(30);
    s.push(20);
    s.push(5);
    s.push(1);

    showstack(s);

    std::cout << "s.size() : " << s.size() << std::endl;
    std::cout << "s.top() : " << s.top() << std::endl;

    std::cout << "Calling s.pop()" << std::endl;
    s.pop();
    
    showstack(s);
    std::cout << "s.size() : " << s.size() << std::endl;

    return 0;
}
