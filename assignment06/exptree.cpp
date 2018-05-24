#include "exptree.hpp"

namespace ExpTree {
  double VarNode::evaluate(const Variable* vars, int numVars) const {
    for(int i = 0; i<numVars; i++)  {
      if(vars[i].name == name)
        return double(vars[i]);
    }
    return -1000; //hopefully unreachable(TM)
  }

  double SumNode::evaluate(const Variable* vars, int numVars) const {
    return lhs->evaluate(vars, numVars) + rhs->evaluate(vars, numVars);
  }

  double MulNode::evaluate(const Variable* vars, int numVars) const {
    return lhs->evaluate(vars, numVars) * rhs->evaluate(vars, numVars);
  }

  BinOpNode::BinOpNode(Node* lhs, Node* rhs) {
    this->rhs = rhs;
    this->lhs = lhs;
  }

  BinOpNode::~BinOpNode() {
    delete rhs;
    delete lhs;
  }


}
