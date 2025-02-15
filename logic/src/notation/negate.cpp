#include "negate.h"
#include "../utils.h"
#include "nand.h"
#include "value.h"

Negate::Negate(Node *left, Node *right)
    : Node(left, right)
{
    notation = '~';
}

Negate::~Negate()
{
}

bool Negate::getValue(string valList)
{
    return !left->getValue(valList);
}

Node *Negate::nandify(bool isNegation)
{
    if(isNegation)
        return left->nandify(isNegation);
    else
    {
        Node *tmp = new NAnd(left, new Value("1"));
        Node *ret = tmp->nandify();
        free(tmp);
        return ret;
    }
}

string Negate::toString()
{
    return notation + left->toString();
}

RULES Negate::getSTRuleName(bool isNegation)
{
    if (isNegation)
    {
        return ALPHA;
    }
    else
    {
        return left->getSTRuleName(true);
    }
}

void Negate::getSTNodeChild(STNode *root, long pos, bool isNegation)
{
    if (isNegation)
    {
        listReplaceAt(root->nodes, left->copy(), pos);
    }
    else
    {
        left->getSTNodeChild(root, pos, true);
    }
}

Node *Negate::copy()
{
    return new Negate(left->copy());
}

Node *Negate::cnfFilter(bool isNegation)
{
    if(isNegation)
    {
        return left->cnfFilter();
    }
    else
    {
        return left->cnfFilter(true);
    }
}
