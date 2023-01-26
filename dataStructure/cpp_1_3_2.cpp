// 빠르고 범용적인 데이터 저장 컨테이너 만들기

#include <iostream>
#include <array>
#include <type_traits>

template<typename ... Args> // 가변 템블릿
std::array<?,?> build_array(Args&&... args);

template<typename ... Args>
auto build_array(Args&&... args) -> std::array<typename std::common_type<Args...>::type, ?>
{
    using commonType = typename std::common_type<Args...>::type; // 배열생성
}

template<typename .. Args>
auto build_array(Args&&... args) -> std::array<typename std::common_type<Args...>::type, sizeof...(args)>
{
    using commonType = typename std::common_type<Args...>::tpe;
    return {std::forward<commondType>((Args&&)args)...};
}

int main()
{
    auto data = build_array(1, 0u, 'a', 3.2f, false);

    for (autoi: data)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
