#pragma once
#include "manager.h"
class managerlist {
private:
	static int size1;
	manager* firstManager;
public:
	//初次构造一个manager链表
	managerlist():firstManager(nullptr){}

	//manager链表加manager
	void add(manager*& newMan);

	//删除整个manager链表
	void deleteManagerList();

	//从manager.txt读取信息
	void read();

	//向manager.txt中写入信息
	void write();

	//登陆时寻找有没有这个用户
	bool find(manager exa, manager*& Now);

};