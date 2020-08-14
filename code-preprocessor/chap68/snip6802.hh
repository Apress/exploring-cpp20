/** @file snip6802.hh */
/** Code Snippet 68-2 */
enum class color : unsigned { black, red=0xff0000, green=0x00ff00, blue=0x0000ff,
     cyan = blue|green, yellow=red|green, magenta=red|blue, white=red|blue|green };
