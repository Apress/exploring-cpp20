/** @file list7308.hh */
/** Listing 73-8. Implementing the is_member Metafunction */
template<class Check, class... Args> struct is_member;

// Helper metafunction to separate Args into Head, Rest
template<class Check, class Head, class... Rest>
struct is_member_helper :
    std::conditional<std::is_same<Check, Head>::value,
        std::true_type,
        is_member<Check, Rest...>>::type
{};

// Partial specialization for empty Args
template<class Check, class Head>
struct is_member_helper<Check, Head> : std::is_same<Check, Head>::type {};

/// Test whether Check is the same type as a type in Args.
template<class Check, class... Args>
struct is_member : is_member_helper<Check, Args...> {};

