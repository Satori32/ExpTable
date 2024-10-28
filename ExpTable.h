#pragma once
#include <stdio.h>
#include <stdint.h>

#include "FixedVector.h"

struct ExpTable {
	FixedVector<int, 1001> Table;
	intmax_t Exp = 0;
};

ExpTable ConstructExpTable<int, 1001>(FixedVector<int, 1001>& In);
bool Free(ExpTable& In);
bool Add(ExpTable& In, intmax_t B);
bool Sub(ExpTable& In, intmax_t B);
intmax_t Calc(ExpTable& In);
intmax_t TableValue(ExpTable& In, size_t I);