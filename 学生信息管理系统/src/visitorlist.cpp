#include "visitorlist.h"
#include <fstream>
int visitorlist::size2 = 0;
void visitorlist::add(visitor*& newVis) {
	if (firstVisitor == nullptr) {
		firstVisitor = newVis;
	}
	else {
		visitor* p = firstVisitor;
		while (p->next) p = p->next;
		p->next = newVis;
	}
	size2++;
}
void visitorlist::deleteVisitorList() {
	visitor* p = firstVisitor;
	while (firstVisitor) {
		firstVisitor = firstVisitor->next;
		delete p;
		p = firstVisitor;
	}
	size2 = 0;
}
void visitorlist::read() {
	ifstream invisitor("../test/data/visitor.txt", ios::in);
	if (firstVisitor != nullptr) deleteVisitorList();
	string account, password;
	while (invisitor >> account >> password) {
		visitor* vis = new visitor(account, password);
		add(vis);
	}

}
void visitorlist::write() {
	ofstream outfile("../test/data/visitor.txt", ios::out);
	visitor* p = firstVisitor;
	while (p) {
		outfile << p->getAccount() << ' ' << p->getPassword() << endl;
		p = p->next;
	}
	cin.get();
	cout << "密码修改成功！请按任意键退出" << endl;
	cin.get();
}

bool visitorlist::find(visitor exa, visitor*& Now) {
	visitor* p = firstVisitor;
	while (p) {
		if (p->getAccount() == exa.getAccount() && p->getPassword() == exa.getPassword()) {
			Now = p;
			return true;
		}
		p = p->next;
	}
	return false;
}