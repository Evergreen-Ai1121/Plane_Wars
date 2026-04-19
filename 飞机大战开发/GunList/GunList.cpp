#include"GunList.h"
#include"../Config/Config.h"
GunList::GunList() {}
GunList::~GunList() {
	list<Gun*> m_lstGun;
	for (Gun* p : m_lstGun) {
		if (p) {
			delete p;
		}
	}
}
void GunList::showAll() {
	for (Gun* p : m_lstGun) {
		if (p) {
			p->show();
		}
	}
}
void GunList::moveAll() {
	//迭代器
	list<Gun*>::iterator it = m_lstGun.begin();//定义迭代器，指向链表头结点
	while (it != m_lstGun.end()) { //如果迭代器没有到链表尾
		if (*it) {//炮弹指针不为空
			(*it)->move();

			if ((*it)->m_y <= -GUN_HEIGHT) { //如果出界的话
				//删除炮弹本身
				delete(*it);

				//删除节点
				it=m_lstGun.erase(it);
				continue;
			}
		}
		++it;
	}
}