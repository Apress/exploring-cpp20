/** @file list6703.hh */
/** Listing 67-3. A Simple Implementation of the unsetf Member Function */
void unsetf(fmtflags f)
{
   flags_ = flags_ & ~f;
}
