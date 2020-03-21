#include <bignum/Unsigned.hpp>

#include <numeric>
#include <iostream>

template<typename T>
bignum::Unsigned<T> pow(const bignum::Unsigned<T>& value, std::size_t pow)
{
    auto components = std::vector<bignum::Unsigned<T>>();
    auto powerOf2 = bignum::Unsigned<T>(2u);
    for (auto bit = 0u; bit < sizeof(pow) * CHAR_BIT; ++bit)
    {

    }

    return std::accumulate(
        begin(components), 
        end(components), 
        bignum::Unsigned<T>(1u), 
        std::multiplies<>{}
    );
}

int main()
{
    auto value = pow(bignum::Unsigned<unsigned>(2u), 100000u);
    std::cout << bignum::highestBitNumber(value).value_or(-1) << "\n";
    return 0;
}