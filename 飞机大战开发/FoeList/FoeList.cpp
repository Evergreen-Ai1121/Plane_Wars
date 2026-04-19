#include"FoeList.h"
#include<typeinfo>
using namespace std;

#include"./FoeBig.h"
#include"./FoeMid.h"
#include"./FoeSma.h"
#include"../Config/Config.h"
FoeList::FoeList() {}
FoeList::~FoeList() {
	for (Foe*& p: m_lsFoe) {
		if (p) {
			delete p;
			p = nullptr;
		}
	}
	for (Foe*& p : m_lstBoomFoe) {
		if (p) {
			delete p;
			p = nullptr;
		}
	}
}
void FoeList::showAll(){
	for (Foe*& p : m_lsFoe) {
		if (p) {
			p->show();
		}
	}
	for (Foe*& p : m_lstBoomFoe) {
		if (p) {
			p->show();
		}
	}
}
void FoeList::moveAll() {
	list<Foe*>::iterator it = m_lsFoe.begin();
	while (it != m_lsFoe.end()) {
		if (*it) {
			//区分开类型，根据类型传递不同的步长
			//if(*it)->m_showld==4
			//RTTI :运行时类型识别
			//typeid(表达式，变量，类型);计算表达式的类型
			//int a=0;
			//if(typeid(int) ==typeid (a) )

			//*it == Foe* =&子类对象
			//**it == * Foe* =子类对象
			if(typeid(**it) == typeid(FoeSma)){
				(*it)->move(8);
			}else if (typeid(**it) == typeid(FoeMid)) {
				(*it)->move(6);
			}else if (typeid(**it) == typeid(FoeBig)) {
				(*it)->move(4);
			}
			//判断是否出界，出界就删除
			if ((*it)->m_y >= BACK_HEIGHT) {
				//先删除敌人飞机本身
				delete(*it);
				//再删除链表节点
				it = m_lsFoe.erase(it); //返回删除的下一个 自带++
				continue;
			}
		}
		++it;
	}
	
}