#ifndef STATEMENT_H
#define STATEMENT_H

#include "node.h"

class Statement : public Node
{
public:
    Statement(string notate, list<Node *> listNodes = list<Node *>());
    Statement(char notate, list<Node *> variables = list<Node *>());
    ~Statement();

    // Node interface
public:
    string toString();
    void setVariable(string fromVariable, string toVariable);
    Node *copy();
};

#endif // STATEMENT_H
