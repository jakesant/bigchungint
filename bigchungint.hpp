#include <iostream>
#include <vector>

template <int T>
class Bigchungint
{
private:
    bool sign;
    std::vector<bool> vec;

public:
    Bigchungint() //Empty constructor
    {
        vec = vector<bool>(T); //Sets the vector bool to be of size T bits
    }

    Bigchungint(unsigned long long number)
    {
        vec.resize(T, false);

        for(int i = T-1; number > 0; i--) //Sets values of vector
            {
                vec[i] = number % 2;
                number = number/2;
            }
    }

};
//https://stackoverflow.com/questions/4421706/what-are-the-basic-rules-and-idioms-for-operator-overloading