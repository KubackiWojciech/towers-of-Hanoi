#include <string>
#include "FrontEnd.h"
#include "protection.h"


int main()
{

    std::cout << "how many donuts do you want?: " << std::endl;
    int numberOfDonuts;
    std::cin >> numberOfDonuts;

    if (numberOfDonuts > 10)
    {
        if (!protectionAgainstEnterTooBigNumberOfElements(numberOfDonuts)) return 0;
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
