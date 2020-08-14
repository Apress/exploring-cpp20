/** @file list7307.hpp */
/** Listing 73-7. Another Implementation of the promote Metafunction */
// Primary template when IsMember=std::true_type, that is, T is in the
// list of types to promote to int.
template<class IsMember, class T>
struct get_member {
   using type = int;
};

// false means T is not in the list, so leave the type alone.
template<class T>
struct get_member<std::false_type, T>
{
   using type = T;
};

template<class T>
struct promote {
    using type = get_member<typename is_member<T,
        bool, unsigned char, signed char, char, unsigned short, short>::type, T>::type;
};
