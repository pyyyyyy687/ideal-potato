#pragma once
#include "visitor.h"
class visitorlist {
private:
	static int size2;
	visitor* firstVisitor;
public:
	//���ι���һ��visitor����
	visitorlist():firstVisitor(nullptr){}

	//visitor�����visitor
	void add(visitor*& newvis);

	//ɾ������visitor����
	void deleteVisitorList();

	//��visitor.txt��ȡ��Ϣ
	void read();

	//��visitor.txtд����Ϣ
	void write();

	//��½ʱѰ����û������û�
	bool find(visitor exa,visitor*& Now);


};
