/** @file list5301.hh */
/** Listing 53-1. The is_void Class Template */
template<class T>
class is_void : public std::false_type
{};

template<>
class is_void<void> : public std::true_type
{};
