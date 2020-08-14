/** @file snip7104.hh */
/** Code Snippet 71-4 */
namespace ns1 { typedef int Integer; }
namespace ns2 { using ns1::Integer; }
namespace ns3 { ns2::Integer x; }
