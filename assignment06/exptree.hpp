#include <string>

/* An expression is a sequence of operators and operands that specifies a computation.
 * It can be organised in form of a tree, where nodes are operators and leaves
 * are values or variables.
 * TODO: * complete Variable
 *       * make use of inheritance to organize the nodes
 *       * implement functionality of the node types
 */

namespace ExpTree {

// Stores the value of a named variable.
// This class is used to subtitute values for the variables represented by the VarNodes
// in the expression tree.
  class Variable {
  public:
      // Constructs a variable with the given name.
      Variable(const char* _name) : name{_name}{}

      // Store the name as a std::string for easy comparison
      const std::string name;

      // TODO: Implement an assignment operator to set and a conversion operator
      // to double to get the value.
      Variable& operator=(double var) {
        value = var;
        return *this;
      }

      explicit operator double() const {
        return value;
      }

      ~Variable() = default;
  private:
      double value;
  };


  // The (abstract) base class of nodes the expression tree is built of.
  class Node {
  public:
      /**
       * This function calculates the value of the term the (sub)tree represents
       * with the current variable values. Something is missing though ...
       *
       * @param vars An array of Variables
       * @param numVars The length of vars.
       * TODO: Implement this function for all node types.
       *       Make sure that the right one is called when operating with Node*.
       */
      virtual double evaluate(const Variable* vars, int numVars) const = 0;

      virtual ~Node() = default;
  };

  // A base class for binary operators.
  // TODO: Use this class to correctly delete subnodes on destruction.
  class BinOpNode : public Node {
  public:
    BinOpNode(Node* lhs, Node* rhs);
    virtual double evaluate(const Variable* vars, int numVars) const {
      return 0;
    };

    ~BinOpNode();
  protected:
    Node* lhs;
    Node* rhs;
  };

  // Calculates the sum of the two operands.
  class SumNode : public BinOpNode {
  public:
    using BinOpNode::BinOpNode;
    double evaluate(const Variable* vars, int numVars) const override;

  };

  // Calculates the product of the two operands.
  class MulNode : public BinOpNode {
  public:
    using BinOpNode::BinOpNode;
    double evaluate(const Variable* vars, int numVars) const override;
  };

  // Represents a variable in the tree.
  class VarNode : public Variable, public Node {
  public:
    using Variable::Variable;
    double evaluate(const Variable* vars, int numVars) const override;

  };

}
