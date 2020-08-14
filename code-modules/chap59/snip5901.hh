/** @file snip5901.hh */
/** Code Snippet 59-1 */
wchar_t capital_a{'A'};       // the compiler automatically widens narrow characters
std::wstring ray{L"Ray"};
wchar_t pi{L'π'};              // if your tools let you type π as a character
wchar_t pi_unicode{L'\x03c0'}; // if wchar_t uses a Unicode encoding, such as UTF-32
std::wstring price{L"\x20ac" L"12345"};           // Unicode Euro symbol: €12345
