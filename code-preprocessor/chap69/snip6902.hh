/** @file snip6902.hh */
/** Code Snippet 69-2 */
int main()
{
   derived d{42, "example"};
   std::cout << d.value() << '\n' << d.msg() << '\n';
}
