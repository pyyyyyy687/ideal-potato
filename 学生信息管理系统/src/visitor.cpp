#include "visitor.h"
void visitor::askToDisplay(studentlist*& stl) {
	student* p = stl->getFirst();
	while (p) {
		if (p->getName() == vaccount) {
			p->display();
			break;
		}
		p = p->next;
	}
	cin.get();
	cout << "请输入任意键退出" << endl;
	cin.get();
}
