#include <entt/entt.hpp>
#include <iostream>

int main()
{
    entt::registry registry;
    entt::entity  e = registry.create();
    std::cout << "Hello, EnTT! Entity ID = " << int(e) << '\n';
    return 0;
}
