#include "bigchungint.hpp"

int main()
{
    Bigchungint<5> num(10);

    std::cout << "Number is " << num << '\n';

    num++;
    
    std::cout << "Number is now " << num << '\n';

    std::cout << "Number size is " << num.size() << '\n';

    int conversion = int (num);
    double doub = double (num);
    float flo = float (num);

    std::cout << "Int conversion is " << conversion << '\n';
    std::cout << "Double conversion is " << doub << '\n';
    std::cout << "Float conversion is " << flo << '\n';
}