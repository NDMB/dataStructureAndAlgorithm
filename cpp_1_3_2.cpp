// ������ �������� ������ ���� �����̳� �����

#include <iostream>
#include <array>
#include <type_traits>

template<typename ... Args> // ���� �ۺ�
std::array<?,?> build_array(Args&&... args);

template<typename ... Args>
auto build_array(Args&&... args) -> std::array<typename std::common_type<Args...>::type, ?>
{
    using commonType = typename std::common_type<Args...>::type; // �迭����
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
