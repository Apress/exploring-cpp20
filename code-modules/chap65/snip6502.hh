/** @file snip6502.hh */
/** Code Snippet 65-2 */
auto ap{std::make_unique<int>(42)};
ap.reset();            // deletes the pointer to 42
