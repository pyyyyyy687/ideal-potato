#pragma once
#include "manager.h"
class managerlist {
private:
	static int size1;
	manager* firstManager;
public:
	//���ι���һ��manager����
	managerlist():firstManager(nullptr){}

	//manager�����manager
	void add(manager*& newMan);

	//ɾ������manager����
	void deleteManagerList();

	//��manager.txt��ȡ��Ϣ
	void read();

	//��manager.txt��д����Ϣ
	void write();

	//��½ʱѰ����û������û�
	bool find(manager exa, manager*& Now);

};