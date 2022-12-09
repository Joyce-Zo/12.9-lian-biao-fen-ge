#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* partition(struct ListNode* pHead, int x)
{
	// 创建4个指针，作为2种方法的头和尾
	struct ListNode* lessHead, * lessTail, * greaterHead, * greaterTail, * cur;
	cur = pHead;
	// 创建哨兵位头结点，以便尾插	
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
	//	保存哨兵位的next，并free

	greaterTail->next = NULL;
	//	最后把 大的链表链接到小的尾部，不过会带有原先后面的，就是成环了，所以要把最后一个的next置空
	
	struct ListNode* newHead = lessHead->next;
	free(lessHead);
	free(greaterHead);
	return newHead;
}

int main()
{
    //  自己创建链表
    struct ListNode* newnode1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* newnode2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* newnode3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* newnode4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* newnode5 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* newnode6 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* newnode7 = (struct ListNode*)malloc(sizeof(struct ListNode));

    //  给链表赋值
    newnode1->val = 2; newnode1->next = newnode2;
    newnode2->val = 3; newnode2->next = newnode3;
    newnode3->val = 5; newnode3->next = newnode4;
    newnode4->val = 1; newnode4->next = newnode5;
	newnode5->val = 7; newnode5->next = newnode6;
    newnode6->val = 2; newnode6->next = NULL;

    //  调用链表函数
	struct ListNode* head = partition(newnode1, 4);
    return 0;
}