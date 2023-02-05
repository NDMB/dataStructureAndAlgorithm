#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<chrono>

int main()
{
    // 랜덤 백터 만들기
    int n = 10000;
    int lb = 1;
    int ub = 100000;

    srand(time(NULL));

    std::vector<int> randomVector(n);

    for(int i = 0; i < n; i++)
    {
        randomVector[i] = lb + rand() % (ub - lb);
    }
    
    std::sort(randomVector.begin(), randomVector.end());

    /////////////////////////////
    // show vector
    /////////////////////////////
    // 
    // for(int i = 0; i < 100; i++)
    // {
    //     std::cout << std::setw(5) << randomVector[i] << " ";

    //     if((i+1)%10 == 0)
    //     {
    //         std::cout << std::endl;
    //     }
    // }


    int target = 5134;

    std::chrono::system_clock::time_point Start_time = std::chrono::system_clock::now();

    bool is_in = std::binary_search(randomVector.begin(), randomVector.end(), target);

    std::chrono::system_clock::time_point End_time = std::chrono::system_clock::now();
    std::chrono::nanoseconds diff = std::chrono::duration_cast<std::chrono::nanoseconds>(End_time - Start_time);

    std::cout << target;
    if(is_in)
    {
        std::cout << " is found!";
    }
    else
    {
        std::cout << " is not found...";
    }

    std::cout << std::endl << "duration: " << diff.count() << " nanoseconds";
    std::cout << std::endl << End_time.time_since_epoch().count() << std::endl << Start_time.time_since_epoch().count();
}