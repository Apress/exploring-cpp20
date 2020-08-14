/** @file snip6503.hh */
/** Code Snippet 65-3 */
auto rp{std::make_unique<rational>(420, 10)};
int n{rp->numerator()};
rational r{*rp};
sendto(socket, rp.get(), sizeof(r), n, nullptr, 0);
