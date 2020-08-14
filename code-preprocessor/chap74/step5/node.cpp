#include <istream>
#include <stdexcept>

#include "calc_error.hpp"
#include "node.hpp"
#include "node_impl.hpp"

std::shared_ptr<node_impl> node::make_binary_operator(node left, char op, node right)
{
  if (op == '+')
    return std::make_shared<node_add>(left, right);
  else if (op == '-')
    return std::make_shared<node_subtract>(left, right);
  else if (op == '*')
    return std::make_shared<node_multiply>(left, right);
  else if (op == '/')
    return std::make_shared<node_divide>(left, right);
  else
    throw calc_error{"fatal error in make_binary_opreator: unknown operator: " + std::string(1,op)};
}

node::node()
: pimpl_{std::make_shared<node_void>()}
{}

node::node(std::istream& stream)
: pimpl_{node_impl::read_node(stream)}
{}

node::node(double number)
: pimpl_{std::make_shared<node_number>(number)}
{}

node::node(std::string identifier)
: pimpl_{std::make_shared<node_identifier>(identifier)}
{}

node::node(char, node operand)
: pimpl_{std::make_shared<node_negate>(operand)}
{}

node::node(node left, char op, node right)
: pimpl_{make_binary_operator(left, op, right)}
{}

node::node(identifier_list parameters, node definition)
: pimpl_{std::make_shared<node_function>(parameters, definition)}
{}

node::node(std::string name, node_list arguments)
: pimpl_{std::make_shared<node_function_call>(name, arguments)}
{}

void node::print(std::ostream& stream, int indent)
const
{
  pimpl_->print(stream, indent);
}

double node::evaluate()
const
{
  return pimpl_->evaluate();
}

std::string node::to_string()
const
{
  return pimpl_->to_string();
}

identifier_list const& node::get_parameters()
const
{
  return pimpl_->get_parameters();
}

void node::save(std::ostream& stream)
const
{
  pimpl_->save(stream);
}
