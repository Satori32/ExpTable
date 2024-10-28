#include <stdio.h>
#include <stdint.h>

#include "FixedVector.h"

struct ExpTable {
	FixedVector<int,1001> Table;
	intmax_t Exp = 0;
};

ExpTable ConstructExpTable<int, 1001>(FixedVector<int, 1001>& In) {
	ExpTable E;

	E.Exp = 0;
	E.Table = In;

	return E;
}

bool Add(ExpTable& In,intmax_t B) {
	In.Exp += B;
	return true;
}

bool Sub(ExpTable& In, intmax_t B) {
	In.Exp -= B;
	return true;
}

intmax_t Calc(ExpTable& In) {
	intmax_t E=In.Exp;
	for (size_t i = 0; i < Size(In.Table); i++) {
		if (Index(In.Table, i) == NULL) { return -1; }
		intmax_t X = *Index(In.Table, i);
		if (E - X < 0) { return i - 1; }
	}
}
intmax_t TableValue(ExpTable& In, size_t I) {
	if (Index(In.Table, I) == NULL) { return -1; }
	return *Index(In.Table, I);
}