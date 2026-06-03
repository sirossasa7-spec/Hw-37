#include "Queue.h"
#include <iostream>
#include <string>

int main()
{
    Queue<std::string> q;

    q.push("one");
    q.push("two");
    q.push("three");
    q.push("four");
    q.push("five");
    q.push("six");

    std::cout << "Queue:\n";
    q.show();

    q.pop();
    q.pop();

    q.push("seven");

    std::cout << "\nQueue after modifications:\n";
    q.show();

    int count = 0;

    Queue<std::string> temp = q;

    while (!temp.isEmpty())
    {
        std::string s = temp.first();

        if (!s.empty() && (s[0] == 'f' || s[0] == 't'))
            count++;

        temp.pop();
    }

    std::cout << "\nNumber of strings starting with 'f' or 't': "
        << count << std::endl;

    return 0;
}