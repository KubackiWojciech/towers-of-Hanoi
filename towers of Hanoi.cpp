#include <string>
#include "FrontEnd.h"

int main()
{

    std::cout << "how many donuts do you want?: " << std::endl;
    int numberOfDonuts;
    std::cin >> numberOfDonuts;

    if (numberOfDonuts > 10)
    {
        std::cout << "Solving towers of Hanoi with more than 10 elements last very long:" << std::endl;
        std::cout << "To solve problem with 12 elements, computer need about 8.7 minutes." << std::endl;
        std::cout << "To solve problem with 14 elements, it will last about 35 minutes." << std::endl;
        std::cout << "To solve problem with 64 elements, computer will need about 75000000000... YEARS" << std::endl;
        
        std::cout << "Your problem will be solved in:" << std::endl;
        int elements = numberOfDonuts;
        int moves = 0;

        float seconds = 8.2; //my computer needs 8.2 sec to solve towers with 6 elements
        float minutes = 0;
        float hours = 0;
        float days = 0;
        float years = 0;

        for (int i = 6; i < elements; i++) seconds *= 2;

        minutes = seconds / 60;
        hours = minutes / 60;
        days = hours / 24;
        years = days / 365;

        std::cout << "seconds: " << seconds << std::endl;
        std::cout << "or" << std::endl;
        std::cout << "minutes: " << minutes << std::endl;
        std::cout << "or" << std::endl;
        std::cout << "hours: " << hours << std::endl;
        std::cout << "or" << std::endl;
        std::cout << "days: " << days << std::endl;
        std::cout << "or" << std::endl;
        std::cout << "years: " << years << std::endl;

        std::cout << "And you need at least " << pow(2, elements) - 1 << " moves to solve it" << std::endl;

        std::cout << "Do you still want to solve it? Y/N" << std::endl;
        char answer;
        std::cin >> answer;
        while (toupper(answer) != 'Y')
        {
            if (toupper(answer) == 'N') return 0;
            std::cin >> answer;
        } 
    }

    Donut::buildStakes(numberOfDonuts);
    FrontEnd fe(numberOfDonuts);

    char AB[2] = { 'A','B' };
    char AC[2] = { 'A','C' };
    char BC[2] = { 'B','C' };

    if (numberOfDonuts % 2 == 0)
    {
        while (true)                        //moves when number of donuts is even: AB AC BC
        {
            Donut::move(AB);
            fe.render();
            if (Donut::isSolved()) break;
            Donut::move(BC);
            fe.render();
            if (Donut::isSolved()) break;
            Donut::move(AC);
            fe.render();
            if (Donut::isSolved()) break;
        }
    }

    else while (true)                       //moves when number of donuts is odd: AC AB BC
    {
        Donut::move(AC);
        fe.render();
        if (Donut::isSolved()) break;
        Donut::move(BC);
        fe.render();
        if (Donut::isSolved()) break;
        Donut::move(AB);
        fe.render();
        if (Donut::isSolved()) break;
    }

    //Sleep(500);
    //_getch();

    return 0;
}
