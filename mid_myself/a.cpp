#include <iostream>
using namespace std;

struct Node {
	string word;
	Node* next;

	Node(string word) {
		this->word = word;
		this->next = NULL;
	}
};

// your code goes here

int length(Node* head){
        int len = 0;
        while(head){
            len++;
            head = head->next;
        }
        return len;
    }

Node* cyclicShift(Node* head, int k) {
	int len = length(head);
	k = k%len;
	int n = k;
	Node* fast = head;
	Node* slow = head;
	while(--k and fast-> next){
		fast = fast -> next;
	}
	while(fast and fast->next){
		fast = fast->next;
	}
	while(n-- > 1){
		slow = slow->next;
	}
	Node* newHead = slow->next; //Very cool thing I must remember that!!!
	slow->next = nullptr;
	fast->next = head;
	return newHead;

    }
    

void print(Node* head) {
	Node* cur = head;
	while (cur != NULL) {
		cout << cur->word << " ";
		cur = cur->next;
	}
	cout << endl;
}

int main() {
	int n; cin >> n;
	int k; cin >> k;
	Node* head;
	Node* cur;
	for (int i = 0; i < n; i++) {
		string word; 
        cin >> word;
		if (i == 0) {
			head = new Node(word);
			cur = head;
		} else {
			cur->next = new Node(word);
			cur = cur->next;
		}
	}

	head = cyclicShift(head, k);
	print(head);
}