/** @file snip2408.hh */
/** Code Snippet 24-8 */
auto lambda =
   [by_value, &by_reference, another_by_value, &another_by_reference]() {
      by_reference = by_value;
      another_by_reference = another_by_value;
   };
