#include <iostream>
#include <stack>
#include <map>
#include <vector>

struct ListNode 
{
	int val;
	ListNode* next;
};

ListNode* createList(int num);
ListNode* oddEvenList(struct ListNode* head);
ListNode* LinkList(ListNode* head, ListNode* head2);
void printList(ListNode* head);
ListNode* deleteDuplicates(ListNode* head); 

ListNode* (*listAlog)(ListNode*);
int search(int* nums, int numsLen, int target);
int InversePairs(int* data, int dataLen);



int main() 
{
	/*ListNode* head;
	int number;
	std::cout << "please enter the length of list";
	std::cin >> number;
	head =createList(number);
	printList(head);


	listAlog = deleteDuplicates;
	head = (*listAlog)(head);
	printList(head);
	*/

	int arr[] = { 1,2,3,4,5,6,7,8,9,0,10 };
	int len = 0;
	len = sizeof(arr) / sizeof(arr[0]);

	
	int location = 0;
	location = InversePairs(arr, len);
	std::cout << "the pair's number of arr is:  " << location;


}


int InversePairs(int* data, int dataLen) 
{
	int P = 0;
		for (int j = 0; j < dataLen-1; j++) 
		{
			if (data[j] > data[j+1]) //data[0] vs data[1] data[1] vs data[2] 
			{
				P++;
				return data[j];
			}
		}
		if (P == 0) 
		{
			return -1;
		}
		
}



int findPeakElement(int* nums, int numsLen)\
{
	int right = 0;
	int mid = right - 1;
	int left = right - 1;
	while (right < numsLen - 1) 
	{
		if (nums[right] < nums[mid] && nums[left] < nums[mid]) 
		{
			return mid;
		}
		right++;
		left++;
		mid++;
	}
	return -1;
}

int search(int* nums, int numsLen, int target)
{
	int left = numsLen - 1;
	int right = 0;
	int mid;
	

	while (right < left) 
	{
		mid = (left + right) / 2;
		if (nums[mid] > target) 
		{
			left = mid-1;
		}
		else if (nums[mid] < target) 
		{
			right = mid+1;
		}
		else 
		{
			return mid;
		}
	}
	return -1;
}







ListNode* deleteDuplicates(ListNode* head) 
{
	if (head == NULL) 
	{
		return head;
	}
	
	ListNode *newhead = new ListNode();
	newhead->next = head;
	ListNode* copyhead = newhead;
	

	while (copyhead->next!=NULL&& copyhead->next->next!=NULL) 
	{
		if (copyhead->next->val==copyhead->next->next->val) 
		{
			int temp = copyhead->next->val;
			while (copyhead->next != NULL && copyhead->next->val == temp) 
			{
				copyhead->next = copyhead->next->next;
			}
		}
		else 
		{
			copyhead = copyhead->next;
		}
		
	}
	return newhead->next;
}

ListNode* deleteDuplicates_1(ListNode* head)//链表间有序 
{
	if (head == NULL) 
	{
		return head;
	}
	ListNode* fast= head;
	ListNode* slow = head;
	while (fast)
	{
		if (fast == slow) //双指针指向同一指针时
		{
			fast = fast->next;
		}
		else if(  (fast != slow) && (fast->val == slow->val))
		{
			fast = fast->next;
			slow->next = fast;
		}
		else if ((fast != slow) && fast->val !=slow->val)
		{
			fast = fast->next;
			slow = slow->next;
		}
	}
	return head;
}





ListNode* deleteDuplicates_(ListNode* head) 
{
	ListNode* copyhead = head;
	std::map<ListNode* ,int> list;
	while (copyhead) 
	{
		if (list[copyhead] == 1) //map容器中是否有节点，有则跳过
		{
			continue;
		}
		list[copyhead] = 1;//将节点键的值设置为1
		copyhead = copyhead->next;
	}

	copyhead = head;
	while (copyhead) 
	{
		
	}
	return NULL;
}


void printList(ListNode* head) 
{
	ListNode* copyhead = head;
	while (copyhead) 
	{
		std::cout << copyhead->val<<'\t';
		copyhead=copyhead->next;
	}
	std::cout << std::endl;
}
ListNode* createList(int num) 
{
	ListNode* head = new ListNode();
	ListNode* copyhead = head;
	std::cout << "please enter the value of list";
	std::cin >> head->val;
	for (int i = 1; i < num; i++) 
	{
		ListNode* nnode = new ListNode();
		copyhead->next = nnode;
		std::cout << "please enter the value of list";
		std::cin >> nnode->val;
		copyhead = copyhead->next;
	}
	return head;
}

ListNode* oddEvenList(struct ListNode* head) //两个指针有关系
{
	if (head == NULL) 
	{
		return NULL;
	}
	ListNode* odd = head;//奇起始于头
	ListNode* even = head->next;//偶始于奇的下一个
	ListNode* evenhead = even;//偶链 的头
	while (even && even->next) //偶链
	{
		odd->next = even->next;//奇的下一个是偶的下一个
		odd = odd->next;//奇的指针指向下一个位置
		even->next = odd->next;
		even = even->next;
	}
	odd->next = evenhead;//head链变成奇链，奇链与偶链相连
	return head;
}




ListNode* oddEvenList_1(struct ListNode* head) //两个指针没关系
{
	ListNode *fast = head;
	ListNode* slow = head->next;
	ListNode* oddhead = new ListNode();
	oddhead->next = fast;

	ListNode* evenhead = new ListNode();
	evenhead->next = slow;
	
	while ((slow !=NULL  && slow->next !=NULL) &&( fast!=NULL &&fast->next!=NULL))
	{
		
		fast->next = fast->next->next;
		fast = fast->next;
		slow->next = slow->next->next;
		slow = slow->next;
	}
	

	return LinkList(oddhead->next, evenhead->next);
}

ListNode* LinkList(ListNode* head, ListNode* head2) 
{
	ListNode* copyhead = head;
	while (copyhead->next) 
	{
		copyhead = copyhead->next;
	}
	copyhead->next = head2;
	return head;
}