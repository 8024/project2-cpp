#include<stdio.h>
class STACK {
public:
	STACK(int m);
	STACK(const STACK& s);
	int size() const;
	int howMany() const;
	int getelem(int x) const;
	STACK& push(int e);
	STACK& pop(int &e);
	STACK& assign(const STACK& s);
	void print(FILE *fp) const;
	~STACK();
public:
	int *const m_iElems;
	const int m_iMax;
	int m_iPos;
	bool m_bError_exist;
};
