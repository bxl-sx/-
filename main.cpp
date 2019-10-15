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
				//strcmp�Ƚ�����C-String 
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
	cout << "������ѧ�ţ�\t";
	cin >> Sno;
	cout << "ѧ��������\t";
	cin >> Sname;
	cout << "ѧ���༶��\t";
	cin >> Cname;
	cout << "ѧ�����䣺\t";
	cin >> Age;
	cout << "ѧ���绰��\t";
	cin >> Tel;
	StuInfo stu(Sno, Sname, Cname, Age, Tel);
	//stu.show();
	
	StuInfos.push_back(stu);
	
	cout << "\n\t<�����������...>" << endl;
	getch(); 
}
void Controller::deleteStuInfo(){
	if(StuInfos.empty()){
		cout << "����ѧ����Ϣ\n";
		return ;
	}
	cout << "����Ҫɾ����ѧ����ѧ�ţ�\t";
	char sno[15];
	cin >> sno;
	int index = Controller::search(sno);
	if(index == -1){
		cout << "\nû�����ѧ��";
		return ;
	}
	else StuInfos.erase(StuInfos.begin() + index);
	
	cout << "\n\t<�����������...>" << endl;
	getch();
}
void Controller::searchStuInfo(){
	if(StuInfos.empty()){
		cout << "����ѧ����Ϣ\n";
		return ;
	}
	cout << "����Ҫ���ҵ�ѧ����ѧ�ţ�\t";
	char sno[15];
	cin >> sno;
	int index = Controller::search(sno);
	if(index == -1){
		cout << "\nû�����ѧ��";
		getch(); 
		return ;
	}
	else{
		cout << "\tѧ��" << "\t����" << "\t�༶" << "\t����"
	 	<< "\t�绰" << endl;
		
		StuInfos[index].show();
	
	}
	
	cout << "\n\t<�����������...>" << endl;
	getch();
}
void Controller::updateStuInfo(){
	if(StuInfos.empty()){
		cout << "����ѧ����Ϣ\n";
		return ;
	}
	cout << "����Ҫ�޸ĵ�ѧ����ѧ�ţ�\t";
	char sno[15];
	cin >> sno;
	int index = Controller::search(sno);
	if(index == -1){
		cout << "\nû�����ѧ��";
		getch();
		return ;
	}
	else{
		int age;
		char cname[20];
		char sname[20];
		char tel[15];
	cout << "\nѧ��������\t";
	cin >> sname;
	cout << "\nѧ���༶��\t";
	cin >> cname;
	cout << "\nѧ�����䣺\t";
	cin >> age;
	cout << "\nѧ���绰��\t";
	cin >> tel;
	
	StuInfos[index].setSname(sname);
	StuInfos[index].setCname(cname);
	StuInfos[index].setAge(age);
	StuInfos[index].setTel(tel);
	}
	
	cout << "\n\t<�����������...>" << endl;
	getch();
}
void Controller::viewStuInfo(){
	if(StuInfos.empty()){
		cout << "\n����ѧ����Ϣ" << endl;
		return ;
	}
	cout << "\tѧ��" << "\t����" << "\t�༶" << "\t����"
	 << "\t�绰" << endl;
	for(int i = 0; i < StuInfos.size(); i++){
		StuInfos[i].show();
	}
	
	cout << "�����������..." << endl;
	getch();
}
void Controller::menu(){
	again1:system("cls");
	cout << "ѡ�������" << endl;
	cout << "1.����ѧ����Ϣ\n";
	cout << "2.ɾ��ѧ����Ϣ\n";
	cout << "3.����ѧ����Ϣ\n";
	cout << "4.���ѧ����Ϣ\n";
	cout << "5.�޸�ѧ����Ϣ\n";
	cout << "6.�˳�\n";
	//char ch;
	int n;
	do{
		cout << "�����1-6�е�һ������:\t";
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
	cout << "\tѧ��" << "\t����" << "\t�༶" << "\t����"
	 << "\t�绰" << endl;
	stu.show();
}
int main(int argc, char** argv) {
	//std::cout << "Hello world!\n";
	Controller controller;
	controller.menu();
	return 0;
}
