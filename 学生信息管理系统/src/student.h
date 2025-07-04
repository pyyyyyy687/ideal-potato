#pragma once
#include <iostream>
#include <string>
using namespace std;
class student {
private:
	string name;//姓名
	string sex;//性别
	string id;//学号
	string academy;//学院
	string major;//专业
	string classname;//班级
	string dormitory;//宿舍
	string origin;//籍贯
	string tel;//电话
public:
	student* next;
	student(string Name = "null", string Sex = "null", string Id = "null", string Academy = "null", string Major = "null", string Classname = "null",
		string Dormitory = "null", string Origin = "null", string Tel = "null",student* Next=nullptr) {
		name = Name;
		sex = Sex;
		id = Id;
		academy = Academy;
		major = Major;
		classname = Classname;
		dormitory = Dormitory;
		origin = Origin;
		tel = Tel;
		next = Next;
	}
	//返回id
	string getId() { return id; }
	//返回姓名
	string getName() { return name; }
	//返回性别
	string getSex() { return sex; }
	//返回学院
	string getAcademy() { return academy; }
	//返回专业
	string getMajor() { return major; }
	//返回班级
	string getClassname() { return classname; }
	//返回宿舍
	string getDormitory() { return dormitory; }
	//返回籍贯
	string getOrigin() { return origin; }
	//返回电话
	string getTel() { return tel; }
	//打印该学生的信息
	void display();
	//修改学号
	void changeId(string newId) { id = newId; }
	//修改姓名
	void changeName(string newName) { name = newName; }
	//修改性别
	void changeSex(string newSex) { sex = newSex; }
	//修改学院
	void changeAcademy(string newAcademy) { academy = newAcademy; }
	//修改专业
	void changeMajor(string newMajor) { major = newMajor; }
	//修改班级
	void changeClassname(string newClassname) { classname = newClassname; }
	//修改宿舍
	void changeDormitory(string newDormitory) { dormitory = newDormitory; }
	//修改籍贯
	void changeOrigin(string newOrigin) { origin = newOrigin; }
	//修改电话
	void changeTel(string newTel) { tel = newTel; }
};