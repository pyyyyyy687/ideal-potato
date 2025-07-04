#pragma once
#include "visitor.h"
class visitorlist {
private:
	static int size2;
	visitor* firstVisitor;
public:
	//初次构造一个visitor链表
	visitorlist():firstVisitor(nullptr){}

	//visitor链表加visitor
	void add(visitor*& newvis);

	//删除整个visitor链表
	void deleteVisitorList();

	//从visitor.txt读取信息
	void read();

	//向visitor.txt写入信息
	void write();

	//登陆时寻找有没有这个用户
	bool find(visitor exa,visitor*& Now);


};
