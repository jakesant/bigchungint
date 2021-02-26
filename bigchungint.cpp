#include "bigchungint.hpp"

int main()
{
    Bigchungint<5> num(10);

    std::cout << "Number is " << num << '\n';

    num++;
    
    std::cout << "Number is now " << num << '\n';

    std::cout << "Number size is " << num.size() << '\n';

    int conversion = int (num);

    std::cout << "Conversion is " << conversion << '\n';
}