#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* partition(struct ListNode* pHead, int x)
{
	// ����4��ָ�룬��Ϊ2�ַ�����ͷ��β
	struct ListNode* lessHead, * lessTail, * greaterHead, * greaterTail, * cur;
	cur = pHead;
	// �����ڱ�λͷ��㣬�Ա�β��	
	lessHead = lessTail = (struct ListNode*)malloc(sizeof(struct ListNode));
	lessTail->next = NULL;
	greaterHead = greaterTail = (struct ListNode*)malloc(sizeof(struct ListNode));
	greaterTail->next = NULL;
	
	while (cur)
	{
		if (cur->val > x)
		{
			greaterTail->next = cur;
			greaterTail = greaterTail->next;
		}
		else
		{
			lessTail->next= cur;
			lessTail = lessTail->next;
		}
		cur = cur->next;
	}
	lessTail->next = greaterHead->next;
	//	�����ڱ�λ��next����free

	greaterTail->next = NULL;
	//	���� ����������ӵ�С��β�������������ԭ�Ⱥ���ģ����ǳɻ��ˣ�����Ҫ�����һ����next�ÿ�
	
	struct ListNode* newHead = lessHead->next;
	free(lessHead);
	free(greaterHead);
	return newHead;
}

int main()
{
    //  �Լ���������
    struct ListNode* newnode1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* newnode2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* newnode3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* newnode4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* newnode5 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* newnode6 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* newnode7 = (struct ListNode*)malloc(sizeof(struct ListNode));

    //  ������ֵ
    newnode1->val = 2; newnode1->next = newnode2;
    newnode2->val = 3; newnode2->next = newnode3;
    newnode3->val = 5; newnode3->next = newnode4;
    newnode4->val = 1; newnode4->next = newnode5;
	newnode5->val = 7; newnode5->next = newnode6;
    newnode6->val = 2; newnode6->next = NULL;

    //  ����������
	struct ListNode* head = partition(newnode1, 4);
    return 0;
}