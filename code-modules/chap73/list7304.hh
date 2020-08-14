/** @file list7304.hh */
/** Listing 73-4. Defining a Literal Operator to Reverse Bits In an Integer */
consteval unsigned long long operator"" _rev(unsigned long long value)
{
    unsigned long long reversed{0};
    for (std::size_t i{std::numeric_limits<unsigned long long>::digits}; i > 0; --i)
    {
        auto bit{ value & 1 };
        value >>= 1;
        reversed = (reversed << 1) | bit;
    }
    return reversed;
}
static_assert(0_rev == 0);
static_assert(0x1234567890abcdef_rev == 0xf7b3d5091e6a2c48ULL);
