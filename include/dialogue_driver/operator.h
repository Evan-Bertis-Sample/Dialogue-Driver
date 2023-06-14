#ifndef OPERATOR_H
#define OPERATOR_H

#pragma once

enum COMPARISON_OPERATOR
{
    COP_EQUAL, // ==
    COP_NOT_EQUAL, // !=
    COP_LT, // <
    COP_LTE, // <=
    COP_GT, // >
    COP_GTE // >=
};

enum LOGICAL_OPERATOR
{
    LOP_AND,
    LOP_OR
};

#endif // OPERATOR_H