#pragma once
#include "student.h"
#include "studentlist.h"
class manager{
private:
	string maccount;
	string mpassword;
public:
	manager* next;

	//构造manager
	manager(string Maccount,string Mpassword, manager* Next = nullptr) : maccount(Maccount),mpassword(Mpassword),next(next){}
	//返回姓名
	string getAccount() { return maccount; }
	//返回密码
	string getPassword() { return mpassword; }
	//修改密码
	void changePassword(string newPassword) { mpassword = newPassword; }
	//增
	void madd(studentlist*& stl);
	//删
	void mdelete(studentlist*& stl);
	//改
	void mchange(studentlist*& stl,string id,int n);
	//根据学号排序
	void msortById(studentlist*& stl);
	//根据学院排序
	void msortByAcademy(studentlist*& stl);
	//根据宿舍排序
	void msortByDormitory(studentlist*& stl);
};