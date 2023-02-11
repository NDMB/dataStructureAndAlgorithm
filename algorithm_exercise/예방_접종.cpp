#include<iostream>
#include<algorithm>
#include<vector>

class Student
{
private:
    std::pair<int, int> name;
    bool vaccinated;

public:
    Student(int middle_name, int last_name, bool vaccinated)
    {
        this->name.first = middle_name;
        this->name.second = last_name;
        this->vaccinated = vaccinated;
    }

    std::pair<int, int> get_name()
    {
        return name;
    }

    bool is_vaccinated()
    {
        return vaccinated;
    }

    void to_string()
    {
        std::cout << name.first << " " << name.second << " " << vaccinated*1 << std::endl;
    }

    friend bool operator==(Student left, Student right)
    {
        if(left.name.first != right.name.first)
        {
            return false;
        }
        else
        {
            if(left.name.second != right.name.second)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
    }

    friend bool operator!=(Student left, Student right)
    {
        if(left.name.first != right.name.first)
        {
            return true;
        }
        else
        {
            if(left.name.second != right.name.second)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }

    friend bool operator<(Student left, Student right)
    {
        if(left.name.first == right.name.first)
        {
            if(left.name.second < right.name.second)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if(left.name.first < right.name.first)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }

    friend bool operator>(Student left, Student right)
    {
        if(left.name.first == right.name.first)
        {
            if(left.name.second > right.name.second)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if(left.name.first > right.name.first)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
};

bool is_vaccinated(std::vector<Student> std_list, std::pair<int, int> name)
{
    Student target(name.first, name.second, 0);

    std::sort(std_list.begin(), std_list.end());
    bool found = std::binary_search(std_list.begin(), std_list.end(), target);

    if(found)
    {
        auto it = std::find(std_list.begin(), std_list.end(), target);

        return it->is_vaccinated();
    }
    else
    {
        std::cout << "Student is not found" << std::endl;
        return false;
    }
}

int main()
{   
    Student std1(1, 3, 1);
    Student std2(2, 2, 0);
    Student std3(2, 3, 1);
    Student std4(4, 2, 1);
    Student std5(3, 2, 1);
    Student std6(2, 4, 0);
    Student std7(1, 2, 1);
    Student std8(3, 1, 0);

    Student target(1, 2, 0);
    
    std::vector<Student> std_list = {std1, std2, std3, std4, std5, std6, std7, std8};

    std::cout << "before sort" << std::endl;
    for (auto std : std_list)
    {
        std.to_string();
    }

    std::cout << "after sort" << std::endl;
    for (auto std : std_list)
    {
        std.to_string();
    }
    std::cout << std::endl;

    if(is_vaccinated(std_list, target.get_name()))
    {
        std::cout << "Student: (" << target.get_name().first << " " << target.get_name().second << ") got vaccinated";
    }
    else
    {
        std::cout << "Student: (" << target.get_name().first << " " << target.get_name().second << ") didn't vaccinated";
    }
    std::cout << std::endl;


    return 0;
}