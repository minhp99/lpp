#ifndef VALUE_H
#define VALUE_H

#include "node.h"

class Value : public Node
{
public:
    explicit Value(string value);
    ~Value() override;

    // Node interface
public:
    bool getValue(string valList) override;
    string toString() override;
    Node *nandify(bool isNegation) override;
    void setVariable(string fromVariable, string toVariable) override;
    Node *copy() override;
    Node *cnfFilter(bool isNegation = false) override;
};

#endif // VALUE_H
