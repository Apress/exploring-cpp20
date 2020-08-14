/** @file list7309.hh */
/** Listing 73-9. One Way to Implement std::conditional */
template<bool Condition, class IfTrue, class IfFalse>
struct conditional
{
    using type = IfFalse;
};

template<class IfTrue, class IfFalse>
struct conditional<true, IfTrue, IfFalse>
{
   using type = IfTrue;
};
