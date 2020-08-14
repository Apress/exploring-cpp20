/** @file snip7103.hh */
/** Code Snippet 71-3 */
namespace ns1 { typedef int Integer; }
namespace ns2 { using namespace ns1; }
namespace ns3 { ns2::Integer x; }
