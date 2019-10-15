#include <iostream>
#include<string.h>
#include<string>
#include<vector>
#include<stdlib.h>
#include<conio.h>
using namespace std;

class StuInfo{
	public:
		char* getSno(){
			return this->Sno;
		}
		void setAge(int age){
			this->Age = age;
		}
		void setCname(char *cname){
			strcpy(this->Cname, cname);
		}
		void setSname(char *sname){
			strcpy(this->Sname, sname);
		}
		void setSno(char *sno){
			strcpy(this->Sno, sno);
		}
		void setTel(char *tel){
			strcpy(this->Tel, tel);
		}
		void show(){
			cout << '\t' << Sno << '\t' << Sname << '\t'
			<< Cname << '\t' << Age << '\t' << Tel << endl;
		}
		
		StuInfo(){
		}
		StuInfo(char *sno, char *sname, char *cname, int age, char *tel){
			setAge(age);
			setCname(cname);
			setSname(sname);
			setSno(sno);
			setTel(tel);
		}
	private:
		int Age;
		char Cname[20];
		char Sname[20];
		char Sno[15];
		char Tel[15];
}; 

vector<StuInfo> StuInfos;
class Controller{
	public:
		void addStuInfo();
		void deleteStuInfo();
		void searchStuInfo();
		void updateStuInfo();
		void viewStuInfo();
		void menu();
		void showStuInfo(StuInfo stu); 
		int search(char sno[]){
			int length = StuInfos.size();
			int i = 0;
			for(i = 0; i < length; i++){
				//strcmp比较两个C-String 
				if(strcmp(StuInfos[i].getSno(), sno) == 0)
				return i;
			}
			if(i >= length)return -1;
		}
};
void Controller::addStuInfo(){
	int Age;
	char Cname[20];
	char Sname[20];
	char Sno[15];
	char Tel[15];
	cout << "请输入学号：\t";
	cin >> Sno;
	cout << "学生姓名：\t";
	cin >> Sname;
	cout << "学生班级：\t";
	cin >> Cname;
	cout << "学生年龄：\t";
	cin >> Age;
	cout << "学生电话：\t";
	cin >> Tel;
	StuInfo stu(Sno, Sname, Cname, Age, Tel);
	//stu.show();
	
	StuInfos.push_back(stu);
	
	cout << "\n\t<按任意键返回...>" << endl;
	getch(); 
}
void Controller::deleteStuInfo(){
	if(StuInfos.empty()){
		cout << "暂无学生信息\n";
		return ;
	}
	cout << "输入要删除的学生的学号：\t";
	char sno[15];
	cin >> sno;
	int index = Controller::search(sno);
	if(index == -1){
		cout << "\n没有这个学生";
		return ;
	}
	else StuInfos.erase(StuInfos.begin() + index);
	
	cout << "\n\t<按任意键返回...>" << endl;
	getch();
}
void Controller::searchStuInfo(){
	if(StuInfos.empty()){
		cout << "暂无学生信息\n";
		return ;
	}
	cout << "输入要查找的学生的学号：\t";
	char sno[15];
	cin >> sno;
	int index = Controller::search(sno);
	if(index == -1){
		cout << "\n没有这个学生";
		getch(); 
		return ;
	}
	else{
		cout << "\t学号" << "\t姓名" << "\t班级" << "\t年龄"
	 	<< "\t电话" << endl;
		
		StuInfos[index].show();
	
	}
	
	cout << "\n\t<按任意键返回...>" << endl;
	getch();
}
void Controller::updateStuInfo(){
	if(StuInfos.empty()){
		cout << "暂无学生信息\n";
		return ;
	}
	cout << "输入要修改的学生的学号：\t";
	char sno[15];
	cin >> sno;
	int index = Controller::search(sno);
	if(index == -1){
		cout << "\n没有这个学生";
		getch();
		return ;
	}
	else{
		int age;
		char cname[20];
		char sname[20];
		char tel[15];
	cout << "\n学生姓名：\t";
	cin >> sname;
	cout << "\n学生班级：\t";
	cin >> cname;
	cout << "\n学生年龄：\t";
	cin >> age;
	cout << "\n学生电话：\t";
	cin >> tel;
	
	StuInfos[index].setSname(sname);
	StuInfos[index].setCname(cname);
	StuInfos[index].setAge(age);
	StuInfos[index].setTel(tel);
	}
	
	cout << "\n\t<按任意键返回...>" << endl;
	getch();
}
void Controller::viewStuInfo(){
	if(StuInfos.empty()){
		cout << "\n暂无学生信息" << endl;
		return ;
	}
	cout << "\t学号" << "\t姓名" << "\t班级" << "\t年龄"
	 << "\t电话" << endl;
	for(int i = 0; i < StuInfos.size(); i++){
		StuInfos[i].show();
	}
	
	cout << "按任意键返回..." << endl;
	getch();
}
void Controller::menu(){
	again1:system("cls");
	cout << "选择操作：" << endl;
	cout << "1.增加学生信息\n";
	cout << "2.删除学生信息\n";
	cout << "3.查找学生信息\n";
	cout << "4.浏览学生信息\n";
	cout << "5.修改学生信息\n";
	cout << "6.退出\n";
	//char ch;
	int n;
	do{
		cout << "请输出1-6中的一个数字:\t";
		//ch = ();
		cin >> n;
	}//while(ch < '1' || ch > '6');
	while(n <= 0 || n >6);
		switch(n){
		//switch(ch){
			case 1:addStuInfo();break;
			case 2:deleteStuInfo();break;
			case 3:searchStuInfo();break;
			case 4:viewStuInfo();break;
			case 5:updateStuInfo();break;
			case 6:exit(1);
		}
	
	
	goto again1;
}
void Controller::showStuInfo(StuInfo stu){
	cout << "\t学号" << "\t姓名" << "\t班级" << "\t年龄"
	 << "\t电话" << endl;
	stu.show();
}
int main(int argc, char** argv) {
	//std::cout << "Hello world!\n";
	Controller controller;
	controller.menu();
	return 0;
}
