#include <iostream>
#include <vector>
#include <ranges>
#include <string>

template <int T>
class Bigchungint
{
private:
    bool sign;
    std::vector<bool> vec;

public:
    Bigchungint() //Empty constructor
    {
        vec = std::vector<bool>(T); //Sets the vector bool to be of size T bits
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

    Bigchungint(const Bigchungint &bci) //Copy Constructor
    {
        vec = bci.vec;
    }

    Bigchungint& operator++() //Overloads Preincrement ++ operator
    {
        for (unsigned int i = T-1; i < this->vec.size(); --i)
        {
            if (this->vec[i] == 0)
            {
                this->vec[i] = 1;
                break;
            }
            this->vec[i] = 0;
        }

        return *this;
    }

    Bigchungint operator++(const int) //Overloads Postincrement ++ operator
    {
        Bigchungint<T> temp = *this;
        ++*this;
        return temp;
    }

    Bigchungint& operator--() //Overloads Predecrement -- operator
    {
        for (unsigned int i = T-1; i < this->vec.size(); --i)
        {
            if (this->vec[i] == 1)
            {
                this->vec[i] = 0;
                break;
            }
            this->vec[i] = 1;
        }

        return *this;
    }

    Bigchungint operator--(const int) //Overloads Postdecrement -- operator
    {
        Bigchungint<T> temp = *this;
        --*this;
        return temp;
    }

    Bigchungint operator~() //Overloads bitwise NOT ~ operator
    {
        for(auto bit : this->vec)
            bit = !bit; //Inverts the value of the bit

        return *this;
    }

    bool operator==(const Bigchungint myu) //Overloads equality == operator
    {
        if (this->vec == myu.vec)
            return true;
        return false;
    }

    int size()
    {
        return vec.size();
    }

    friend std::ostream& operator<< <T>(std::ostream &out, const Bigchungint &bci);

    operator int () const
    {
        int output = 0;
        int rep = 1;

        for(auto bit : this->vec | std::views::reverse)
        {
            if(bit)
                output += rep;
            rep *= 2;
        }
        return output;
    }

    operator double () const
    {
        double output = 0.0;
        int rep = 1;

        for(auto bit : this->vec | std::views::reverse)
        {
            if(bit)
                output += rep;
            rep *= 2;
        }
        return output;
    }

    operator float () const
    {
        float output = 0.0;
        int rep = 1;

        for(auto bit : this->vec | std::views::reverse)
        {
            if(bit)
                output += rep;
            rep *= 2;
        }
        return output;
    }

};

template <int T>
std::ostream& operator<<(std::ostream &out, const Bigchungint<T> &bci)
{
    for (auto bit : bci.vec)
        out << bit;
    return out;
}
//https://stackoverflow.com/questions/4421706/what-are-the-basic-rules-and-idioms-for-operator-overloading