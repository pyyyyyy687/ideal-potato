#pragma once

#include <string>
#include "studentlist.h"

class visitor {
private:
	string vaccount;
	string vpassword;
public:
	visitor* next;
	visitor(string Account="",string Password=""):vaccount(Account),vpassword(Password),next(nullptr){}
	//获取姓名
	string getAccount() { return vaccount; }
	//获取密码
	string getPassword() { return vpassword; }
	//修改密码
	void changePassword(string newPassword) { vpassword = newPassword; }
	//申请显示学生信息
	void askToDisplay(studentlist*& stl);
};