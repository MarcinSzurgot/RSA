#include <bignum/Integer.hpp>
#include <bignum/Unsigned.hpp>

#include <numeric>
#include <iostream>

template<typename T>
bignum::Unsigned<T> pow(bignum::Unsigned<T> value, std::size_t pow)
{
    static const auto one = bignum::Unsigned{T(1u)};

    auto components = std::vector<bignum::Unsigned<T>>();
    if (const auto highestBitNumber = bignum::highestBitNumber(pow))
    {
        for (auto bit = 0u; bit <= *highestBitNumber; ++bit)
        {
            if (pow & (std::size_t(1) << bit))
            {
                components.push_back(value);
            }
            if (bit < *highestBitNumber)
            {
                value *= value;
            }
        }
    }
    return std::accumulate(begin(components), end(components), one, std::multiplies<>{});
}

template<typename T>
bignum::Integer<T> pow(bignum::Integer<T> value, std::size_t pow)
{
    const auto sign = pow % 2 ? value.sign() : bignum::Sign::Plus;
    return bignum::Integer(sign, ::pow(value.abs(), pow));
}

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cout << "No pow argument\n";
    }

    const auto power = std::atoi(argv[1]);
    auto value = pow(bignum::Integer<unsigned>(-9384751), power);
    std::cout << *bignum::highestBitNumber(value.abs()) << "\n";
    return 0;
}