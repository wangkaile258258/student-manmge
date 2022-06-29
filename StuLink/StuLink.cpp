#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
class Link {
private://相当于结点
    int num;
    Link* pre, * next;
public:
    Link();
    ~Link();
    bool _insert(int i, int x);//将当前结点插入到选定位置之后
    bool _delete(int i);//删除选定结点
    bool _outputall();//遍历输出
    int _getnum();//输出头结点num 即链表size
};
Link::Link() {
    pre = next = NULL;
}
Link::~Link() { //清空内存  头结点不清空 只清空剩下的结点 
    if (this->pre != NULL) return;//防止delete时调用
    Link* p = this->next;//p指向第head后第一个结点
    if (p == NULL) return;//若空链表 return
    else if (p->next == NULL) {//若只有一个结点 删了之后 return 
        this->next = NULL;
        delete p;
        return;
    }
    else if (p->next != NULL) {//若至少两个结点 
        p = p->next;
        while (p->next != NULL) {
            delete p->pre;
            p = p->next;
        }
        delete p;
    }
}
bool Link::_insert(int i, int x) { 
    if (i<1 || i>num + 1) {//若不能插到合适的位置  num+1是插到队尾
        printf("请输入正确的插入位置\n");
        return false;
    }
    else {//若可以插到合适的位置
        Link* head = this;
        Link* p = new Link;
        p->num = x;
        if (head->next == NULL) { //若链表为空
            head->next = p, p->pre = head;//双向赋值
        }
        else { //若链表不为空
            Link* q = head, * r = head->next;
            while (--i) { //注意 这里第一个是head之后
                q = q->next;
                if (r != NULL) r = r->next;//这个是特判队尾
            }
            q->next = p, p->next = r;
            p->pre = q;
            if (r != NULL) r->pre = p;//特判队尾
        }
        num++;
        return true;
    }
}
bool Link::_delete(int i) {//调用时会自动调用析构函数
    if (i<1 || i>num) {//若不能插到合适的位置
        printf("请输入正确的删除位置\n");
        return false;
    }
    else {//若可以删除正确位置
        Link* p = this->next;
        while (--i) { 
            p = p->next;
        }
        p->pre->next = p->next;
        if (p->next != NULL) p->next->pre = p->pre;
        delete p;
        num--;
        return true;
    }
}
bool Link::_outputall() { //输出所有结点
    Link* p = this;
    if (p->next == NULL) { //若是空链表
        printf("链表为空！\n");
        return false;
    }
    else { //链表非空
        printf("链表所有元素如下：\n");
        p = p->next;
        while (p != NULL) {
            printf("%d ", p->num);
            p = p->next;
        }
        printf("\n");
    }
    return true;
}
int Link::_getnum() {
    return num;
}
struct stud_node {
    int    num;
    char   name[30];
    int    score;
    struct stud_node* next;
};

struct stud_node* createlist();
struct stud_node* deletelist(struct stud_node* head, int min_score);
int main() {
    //初始化一个链表  初始只有一个头结点
    Link head;
    while (1) {
        printf("请输入你的选择：\n");
        printf("1、插入结点\n");
        printf("2、删除结点\n");
        printf("3、打印结点\n");
        printf("0、退出\n");
        int op;
        scanf_s("%d", &op);
        bool flag = true;
        if (op == 1) {
            int i, x;
            printf("你想在第i个位置插入x，请输入i x：\n");
            scanf_s("%d%d", &i, &x);
            flag = head._insert(i, x);
        }
        if (op == 2) {
            int num = head._getnum();
            if (num == 0) printf("链表为空，无法删除！\n");
            else {
                int i;
                printf("你想删除第i个结点，请输入i：\n");
                scanf_s("%d", &i);
                flag = head._delete(i);
            }
        }
        if (op == 3) flag = head._outputall();
        if (op == 0) break;
        if (flag == false) printf("操作失败\n");
        else printf("操作成功\n");
    }
    return 0;

}

