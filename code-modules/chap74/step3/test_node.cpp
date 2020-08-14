#include <sstream>
#include <string>
#include <gtest/gtest.h>

#include "node.hpp"
#include "variables.hpp"

using namespace std::literals;

TEST(NodeTest, test_basics)
{
  node n{1.0};
  EXPECT_EQ(1.0, n.evaluate());
  EXPECT_EQ("1", n.to_string());
  node s{"ident"};
  EXPECT_EQ("ident", s.to_string());
}

TEST(NodeTest, test_negate)
{
  node n{1.0};
  node neg{'-', n};
  EXPECT_EQ(-1.0, neg.evaluate());
}

TEST(NodeTest, test_add)
{
  node a{1.0}, b{2.0}, c{3.0};
  // Extra parentheses are needed due to the way EXPECT_EQ works.
  // It can balance parentheses, but not curly braces.
  EXPECT_EQ(3.0, (node{a, '+', b}.evaluate()));
  EXPECT_EQ(6.0, (node{node{a, '+', b}, '+', c}.evaluate()));
}

TEST(NodeTest, test_subtract)
{
  node a{1.0}, b{2.0}, c{3.0};
  EXPECT_EQ(1.0, (node{c, '-', b}.evaluate()));
  EXPECT_EQ(-4.0, (node{node{a, '-', b}, '-', c}.evaluate()));
}

TEST(NodeTest, test_multiply)
{
  node a{1.0}, b{2.0}, c{3.0};
  EXPECT_EQ(3.0, (node{a, '*', c}.evaluate()));
  EXPECT_EQ(6.0, (node{node{a, '*', b}, '*', c}.evaluate()));
}

TEST(NodeTest, test_divide)
{
  node a{1.0}, b{2.0}, c{6.0};
  EXPECT_EQ(0.5, (node{a, '/', b}.evaluate()));
  EXPECT_EQ(3.0, (node{node{c, '/', a}, '/', b}.evaluate()));
}

TEST(NodeTest, test_mix)
{
  node a{node{1.5}, '*', node{2.0}};
  EXPECT_EQ(3.0, a.evaluate());

  node b{node{3.0}, '/', node{1.5}};
  EXPECT_EQ(2.0, b.evaluate());

  node c{a, '+', b};
  EXPECT_EQ(5.0, c.evaluate());

  node d{node{10}, '-', node{3}};
  EXPECT_EQ(7.0, d.evaluate());

  node e{'-', node{1.0}};
  EXPECT_EQ(-1.0, e.evaluate());

  node f{node{2}, '*', e};
  EXPECT_EQ(-2.0, f.evaluate());

  node g{d, '+', f};
  EXPECT_EQ(5.0, g.evaluate());

  node h{c, '-', g};
  EXPECT_EQ(0.0, h.evaluate());
}

TEST(NodeTest, test_var)
{
  node n{node{node{"half"}, node{node{1}, '/', node{2}}}};
  EXPECT_EQ(0.5, n.evaluate());
  EXPECT_EQ(0.5, get_variable("half"));
}

TEST(NodeTest, test_copy)
{
  node n{node{node{1}, '+', node{2}}};
  {
    node m{n};
    n = node{'-', m};
    EXPECT_EQ(3.0, m.evaluate());
  }
  EXPECT_EQ(-3.0, n.evaluate());
}
