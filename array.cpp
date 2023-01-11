#include <iostream>
#include <array>
#include <sstream>
#include <algorithm>

template <typename P>
class dynamic_player
{
    P* data;
    size_t n;

    public:
        dynamic_player(int n)
        {
            this->n = n;
            data = new P[n];
        }

        dynamic_player(const dynamic_player<P>& other)
        {
            n = other.n;

            data = new P[n];

            for(int i = 0; i < n; i ++)
            {
                data[i] = other[i];
            }
        }

        P& operator[](int index)
        {
            return data[index];
        }

        P& at(int index)
        {
            if(index < n)
            {
                return data[index];
            }
            throw "index out of bound!";
        }

        size_t size()
        {
            return this->n;
        }

        P& begin()
        {
            return data;
        }

        P& end()
        {
            return data + this->n;
        }
};

struct player
{
    std::string name;
    int shoot;
};

int main()
{ 
    std::cout << "Enter # of platers: ";
    int nPlayer;
    std::cin >> nPlayer;

    std::cout << "nPlayers: " << nPlayer << std::endl;

    dynamic_player<player> players(nPlayer);

    for(int i = 0; i < nPlayer; i++)
    {
        std::string name;
        int shoot;
        std::cout << "player" << i + 1 << " name shoot: ";
        std::cin >> name >> shoot;
        try
        {
            players[i] = player{name, shoot};
        }
        catch(const std::exception& e)
        {
            std::cout << "error!" << std::endl;
        }
    }

    for(int i = 0; i < nPlayer; i++)
    {
        std::cout << i+1;
        std::cout << "player" << i+1 << ": " << players[i].name << std::endl;
        std::cout << "shoot: " << players[i].shoot << std::endl;
        // std::cout << "curve: " << players[i].curve << std::endl;
        // std::cout << "header: " << players[i].curve << std::endl;
    }

    return 0;
}

//////////////////////////////////////////
// book exercise
//////////////////////////////////////////
/*
template <typename T>
class dynamic_array
{
    T* data;
    size_t n;


    public:
        dynamic_array(int n)
        {
            this->n = n;
            data = new T[n];
        }

        dynamic_array(const dynamic_array<T>& other)
        {
            n = other.n;
            data = new T[n];

            for (int i = 0; i < n; i++)
            {
                data[i] = other[i];
            }
        }

        T& operator[](int index)
        {
            return data[index];
        }

        const T& operator[](int index) const
        {
            return data[index];
        }

        T& at(int index)
        {
            if (index < n)
            {
                return data[index];
            }
            throw "Index out of range";
        }

        size_t size() const
        {
            return n;
        }

        ~dynamic_array()
        {
            delete[] data;
        }

        T* begin() {return data;}
        const T* begin() const { return data; }
        T* end() {return data + n;}
        const T* end() const { return data + n; }

        friend dynamic_array<T> operator+(const dynamic_array<T>& arr1, const dynamic_array<T>& arr2)
        {
            dynamic_array<T> result(arr1.size() + arr2.size());
            std::copy(arr1.begin(), arr1.end(), result.begin());
            std::copy(arr2.begin(), arr2.end(), result.begin() + arr1.size());

            return result;
        }

        std::string to_string(const std::string& sep = ", ")
        {
            if(n == 0)
                return "";

            std::ostringstream os;
            os << data[0];

            for (int i = 1; i < n; i++)
            {
                os << sep << data[i];
            }

            return os.str();
        }
};

struct student
{
    std::string name;
    int standard;
};

std::ostream& operator<<(std::ostream& os, const student& s)
{
    return (os << "[" << s.name << ", " << s.standard << "]");
}

int main()
{
    int nStudents;
    std::cout << "enter number of students in class 1 : ";
    std::cin >> nStudents;

    dynamic_array<student> class1(nStudents);

    for(int i = 0; i < nStudents; i++)
    {
        std::string name;
        int standard;
        std::cout << i + 1 << "th students name and age : ";
        std::cin >> name >> standard;
        class1[i] = student{name, standard};
    }

    try
    {
        // class1.at(nStudents) = student{"John", 8};
    }
    catch(const std::exception& e)
    {
        std::cout << "error!" << std::endl;
    }

    auto class2 = class1;
    std::cout << "copy class1 and create class2 " << class2.to_string() << std::endl;

    auto class3 = class1 + class2;
    std::cout << "add class1 and class2 to create class3 : " << class3.to_string() << std::endl;

    return 0;
}
*/




//////////////////////////////////////////
// basic concepts
//////////////////////////////////////////
/*
int main(void)
{
    std::array<int, 10> arr1;
    arr1[0] = 1;
    std::cout << "first element of array arr1: " << arr1[0] << std::endl;

    std::array<int, 4> arr2 = {1,2,3,4};
    std::cout << "every element of array arr2: ";

    for(int i = 0; i < arr2.size(); i++)
    {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    std::array<int, 3> arr3 = {1,2,3};

    try
    {
        std::cout << arr3.at(3) << std::endl;
        std::cout << arr3.at(4) << std::endl;
    }
    catch ( const std::out_of_range& ex)
    {
        std::cerr << ex.what() << std::endl;
    }


    std::array<int, 5> arr4  = {4,2,3,4,5};
    for(auto ele : arr4)
    {
        std::cout << ele << ' ';
    }
    std::cout << std::endl;

    for (auto it = arr4.begin(); it != arr4.end(); it++)
    {
        auto element = (*it);
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    return 0;
}
*/