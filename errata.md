# Errata for *Exploring C++20*

On **page 109** [technical accuracy]:
 
The book states "C++ guarantees that any character set your compiler and library support represents digit characters with contiguous values", which is true.

It goes on to say "The same sequence is true for letters in the alphabet, that is, 'A' + 25 == 'Z'", which is not.  In EBCDIC (mentioned earlier in the chapter) the letters are not contiguous.

***

On **page 112** [technical accuracy]:
 
The book states that "MacOS uses a carriage return ('\x0d')" as a newline character.  This is not true of more modern versions of MacOS, which use a line feed like UNIX.

***
On **page 300** [Listing 41-4]:
 
Listing 41-4 (finding the longest string in a data set) appears to have been rewritten to use std::ranges::max(), as the surrounding text refers to a local variable named "string" in a for loop, and the listing contains no such loop or variable.

***
On **page xx** [Summary of error]:
 
Details of error here. Highlight key pieces in **bold**.
