#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
class Link {
private://�൱�ڽ��
    int num;
    Link* pre, * next;
public:
    Link();
    ~Link();
    bool _insert(int i, int x);//����ǰ�����뵽ѡ��λ��֮��
    bool _delete(int i);//ɾ��ѡ�����
    bool _outputall();//�������
    int _getnum();//���ͷ���num ������size
};
Link::Link() {
    pre = next = NULL;
}
Link::~Link() { //����ڴ�  ͷ��㲻��� ֻ���ʣ�µĽ�� 
    if (this->pre != NULL) return;//��ֹdeleteʱ����
    Link* p = this->next;//pָ���head���һ�����
    if (p == NULL) return;//�������� return
    else if (p->next == NULL) {//��ֻ��һ����� ɾ��֮�� return 
        this->next = NULL;
        delete p;
        return;
    }
    else if (p->next != NULL) {//������������� 
        p = p->next;
        while (p->next != NULL) {
            delete p->pre;
            p = p->next;
        }
        delete p;
    }
}
bool Link::_insert(int i, int x) { 
    if (i<1 || i>num + 1) {//�����ܲ嵽���ʵ�λ��  num+1�ǲ嵽��β
        printf("��������ȷ�Ĳ���λ��\n");
        return false;
    }
    else {//�����Բ嵽���ʵ�λ��
        Link* head = this;
        Link* p = new Link;
        p->num = x;
        if (head->next == NULL) { //������Ϊ��
            head->next = p, p->pre = head;//˫��ֵ
        }
        else { //������Ϊ��
            Link* q = head, * r = head->next;
            while (--i) { //ע�� �����һ����head֮��
                q = q->next;
                if (r != NULL) r = r->next;//��������ж�β
            }
            q->next = p, p->next = r;
            p->pre = q;
            if (r != NULL) r->pre = p;//���ж�β
        }
        num++;
        return true;
    }
}
bool Link::_delete(int i) {//����ʱ���Զ�������������
    if (i<1 || i>num) {//�����ܲ嵽���ʵ�λ��
        printf("��������ȷ��ɾ��λ��\n");
        return false;
    }
    else {//������ɾ����ȷλ��
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
bool Link::_outputall() { //������н��
    Link* p = this;
    if (p->next == NULL) { //���ǿ�����
        printf("����Ϊ�գ�\n");
        return false;
    }
    else { //����ǿ�
        printf("��������Ԫ�����£�\n");
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
    //��ʼ��һ������  ��ʼֻ��һ��ͷ���
    Link head;
    while (1) {
        printf("���������ѡ��\n");
        printf("1��������\n");
        printf("2��ɾ�����\n");
        printf("3����ӡ���\n");
        printf("0���˳�\n");
        int op;
        scanf_s("%d", &op);
        bool flag = true;
        if (op == 1) {
            int i, x;
            printf("�����ڵ�i��λ�ò���x��������i x��\n");
            scanf_s("%d%d", &i, &x);
            flag = head._insert(i, x);
        }
        if (op == 2) {
            int num = head._getnum();
            if (num == 0) printf("����Ϊ�գ��޷�ɾ����\n");
            else {
                int i;
                printf("����ɾ����i����㣬������i��\n");
                scanf_s("%d", &i);
                flag = head._delete(i);
            }
        }
        if (op == 3) flag = head._outputall();
        if (op == 0) break;
        if (flag == false) printf("����ʧ��\n");
        else printf("�����ɹ�\n");
    }
    return 0;

}

