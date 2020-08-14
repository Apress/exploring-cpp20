/** @file list6801.hh */
/** Listing 68-1. One Way to Implement openmode Type */
enum class openmode : unsigned char { 
    in=1, out=2, binary=4, trunc=8, app=16, ate=32
};

openmode operator|(openmode lhs, openmode rhs)
{
   return static_cast<openmode>(
     static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs) );
}

openmode operator&(openmode lhs, openmode rhs)
{
   return static_cast<openmode>(
     static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs) );
}

openmode operator~(openmode arg)
{
   return static_cast<openmode>( ~static_cast<unsigned>(arg) );
}
