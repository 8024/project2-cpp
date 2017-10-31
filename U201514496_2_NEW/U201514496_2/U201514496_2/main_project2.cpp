#include<iostream>
#include<string>
#include<string.h>
#include"STACK.h"
#include<stdio.h>
 
using namespace std;


int main(int agrc,char *agrv[]) {
	int get_num = NULL;
	int num_cnt = 3;
	int lost_num = NULL;
	int sign_tran = 0;
	int sign_max = NULL;

	char filename[20] = "U201514496_2.txt";
	FILE *fp = fopen(filename, "w+");

	get_num = atoi(agrv[2]);
	fprintf(fp, "%c  %d  ", 'S', get_num);
	if (!get_num) {
		fprintf(fp, "%c", 'E');
		fclose(fp);
		cout << "the length of stack is 0,input error!" << endl;
		return 0;
	}
	sign_max = get_num;
	STACK stack(get_num);
	STACK *pstack = &stack;
	if (stack.m_bError_exist == true) {
		cout << "Errors!" << endl;
		fprintf(fp, "%c", 'E');
		fclose(fp);
		return 0;
	}
	

	while (num_cnt < agrc) {
		if (!strcmp("-I", agrv[num_cnt])) {
			fprintf(fp, "%c  ", 'I');
			++num_cnt;
			while ((strcmp("-I", agrv[num_cnt]) && strcmp("-O", agrv[num_cnt]) && strcmp("-A", agrv[num_cnt]) && strcmp("-C", agrv[num_cnt]) && strcmp("-N", agrv[num_cnt]) && strcmp("-G", agrv[num_cnt])) && (num_cnt < agrc - 1)) {
				get_num = atoi(agrv[num_cnt]);
				if (sign_max <= pstack->howMany()) {
					cout << "errors" << endl;
					fprintf(fp, "%c", 'E');
					fclose(fp);
					return 0;
				}
				else pstack->push(get_num);
				++num_cnt;
			}
			if (num_cnt == agrc - 1) {
				get_num = atoi(agrv[num_cnt]);
				if (sign_max <= pstack->howMany()) {
					cout << "errors" << endl;
					fprintf(fp, "%c", 'E');
					fclose(fp);
					return 0;
				}
				else pstack->push(get_num);
				++num_cnt;
			}
			pstack->print(fp);
		}
		else if (!strcmp("-A", agrv[num_cnt])) {
			fprintf(fp, "%c  ", 'A');
			++num_cnt;
			get_num = atoi(agrv[num_cnt]);
			STACK *pstack_new_A = new STACK(get_num);
			pstack_new_A=&(pstack_new_A->assign(*pstack));
			if (sign_tran) { delete pstack; }
			if (pstack_new_A->m_bError_exist == true) {
				cout << "Errors!" << endl;
				fprintf(fp, "%c", 'E');
				fclose(fp);
				return 0;
			}
			pstack = pstack_new_A;
			pstack->print(fp);
			sign_tran = 1;
			++num_cnt;
		}
		else if (!strcmp("-C", agrv[num_cnt])) {
			fprintf(fp, "%c  ", 'C');
			STACK* pstack_new_C=new STACK(*pstack);
			if (sign_tran) { delete pstack; }
			if (pstack_new_C->m_bError_exist == true) {
				cout << "Errors!" << endl;
				fprintf(fp, "%c", 'E');
				fclose(fp);
				return 0;
			}
			pstack = pstack_new_C;
			pstack->print(fp);
			sign_tran = 1;

			++num_cnt;
		}
		else if (!strcmp("-N", agrv[num_cnt])) {
			fprintf(fp, "%c  ",'N');
			fprintf(fp, "%d  ", pstack->howMany());

			++num_cnt;
		}
		else if (!strcmp("-G", agrv[num_cnt])) {
			fprintf(fp, "%c  ", 'G');
			++num_cnt;
			get_num = atoi(agrv[num_cnt]);
			if (get_num < pstack->howMany()) {
				fprintf(fp, "%d  ", pstack->getelem(get_num));
			}
			else {
				cout << "Errors!" << endl;
				fprintf(fp, "%c", 'E');
				fclose(fp);
				return 0;
			}
			++num_cnt;
		}
		else if (!strcmp("-O", agrv[num_cnt])) {
			fprintf(fp, "%c  ", 'O');
			++num_cnt;
			get_num = atoi(agrv[num_cnt]);
			for (; get_num > 0; get_num--) {
				if (pstack->howMany() <= 0) {
					cout << "Errors" << endl;
					fprintf(fp, "%c  ", 'E');
					fclose(fp);
					return 0;
				}
				else pstack->pop(lost_num);
			}
			pstack->print(fp);
			++num_cnt;
		}
		else {
			cout << "the input is wrong!" << endl;
			fclose(fp);
			return 0;
		}
	}
	if (sign_tran) {
		delete pstack;
	}
	cout << "the operations are done!" << endl;
	fclose(fp);
	return 0;
}