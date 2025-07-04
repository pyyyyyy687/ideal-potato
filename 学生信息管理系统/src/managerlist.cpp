#include "managerlist.h"
#include <fstream>
int managerlist::size1 = 0;
void managerlist::add(manager*& newMan) {
	if (firstManager == nullptr) {
		firstManager = newMan;
	}
	else {
		manager* p = firstManager;
		while (p->next) p = p->next;
		p->next = newMan;
	}
	size1++;
}

void managerlist::deleteManagerList() {
	manager* p = firstManager;
	while (firstManager) {
		firstManager = firstManager->next;
		delete p;
		p = firstManager;
	}
	size1 = 0;
}

void managerlist::read() {
	ifstream inmanager("../test/data/manager.txt", ios::in);
	string maccount, mpassword;
	if (firstManager != nullptr) deleteManagerList();
	while (inmanager >> maccount >> mpassword) {
		manager* man = new manager(maccount, mpassword);
		add(man);
	}
}

void managerlist::write() {
	ofstream outfile("../test/data/manager.txt", ios::out);
	manager* p = firstManager;
	while (p) {
		outfile << p->getAccount() << ' ' << p->getPassword() << endl;
		p = p->next;
	}
	cin.get();
	cout << "密码修改成功！请按任意键退出" << endl;
	cin.get();

}

bool managerlist::find(manager exa, manager*& Now) {
	manager* p = firstManager;
	while (p) {
		if (p->getAccount() == exa.getAccount() && p->getPassword() == exa.getPassword()) {
			Now = p;
			return true;
		}
		p = p->next;
	}
	return false;
}