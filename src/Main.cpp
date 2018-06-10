#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include "com/tandon/global.h"
#include "com/tandon/Node.h"

#include <boost/filesystem.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/version.hpp>
#include <iterator>
#include <algorithm>
#include <vector>
#include <sstream>
#include <stdexcept>

using namespace std;

#define ARRAY_SIZE 5

using namespace boost::filesystem;

int pointer_references() {

	cout << "Printing the global variable " << g_nValue << endl;
	cout << "Printing the size of parameter" << endl;

	cout << "================================================================"
			<< endl;
	cout << "char:\t\t" << sizeof(char) << " bytes" << endl;
	cout << "wchar_t:\t" << sizeof(wchar_t) << " bytes" << endl;
	cout << "short:\t\t" << sizeof(short) << " bytes" << endl;
	cout << "int:\t\t" << sizeof(int) << " bytes" << endl;
	cout << "long:\t\t" << sizeof(long) << " bytes" << endl;
	cout << "float:\t\t" << sizeof(float) << " bytes" << endl;
	cout << "double:\t\t" << sizeof(double) << " bytes" << endl;
	cout << "long double:\t" << sizeof(long double) << " bytes" << endl;
	cout << "================================================================"
			<< endl;

	// INitializing all elements in the ARRAY to zero
	int arr[ARRAY_SIZE] = { 0 };
	cout << "size of array " << sizeof(arr) << endl;
	int numElements = sizeof(arr) / sizeof(arr[0]);
	cout << "length of array " << numElements << endl;

	// The last entry arr[5] is garbage value. Does not throw exception like Java
	for (int i = 0; i <= ARRAY_SIZE; i++)
		cout << "arr[" << i << "] :" << arr[i] << endl;

	// Accessing method defined in another file
	int num = add(3, 9);
	cout << "Number : " << num << endl;

	short refValue = 7; // &nValue = 0012FF60
	short *ptrValue;
	ptrValue = &refValue;

	cout << "Address >> " << &refValue << endl;
	cout << "Value >> " << refValue << endl;
	cout << "Address stored in pointer >> " << ptrValue << endl;
	cout << "Value stored in pointer >> " << *ptrValue << endl;
	cout << endl;

	cout << "size of pointer >> " << sizeof(ptrValue) << endl;
	cout << "size of value stored in pointer >>" << sizeof(*ptrValue) << endl;

	*ptrValue = 19; // changing the value stored in the address
	cout << "output of nValue >> " << refValue << endl;

	// Accessing array using pointers
	int anArray[5] = { 9, 7, 5, 3, 1 };
	cout << *(anArray + 1) << endl; // prints 7 using dereferencing

	using namespace global;
	Cents cCents1(7);
	Cents cCents2(8);
	Cents cCentsSum = cCents1 + cCents2;
	cout << "I have " << cCentsSum.getCents() << " cents." << endl;

	Base cBase(5); // use Base(int) constructor

	return 0;
}

int testLca() {
	// Let us construct the BST shown in the above figure
	struct TreeNode *root = newNode(20);
	root->lNode = newNode(8);
	root->rNode = newNode(22);
	root->lNode->lNode = newNode(4);
	root->lNode->rNode = newNode(12);
	root->lNode->rNode->lNode = newNode(10);
	root->lNode->rNode->rNode = newNode(14);

	int n1 = 10, n2 = 14;
	struct TreeNode *t = lca(root, n1, n2);
	printf("LCA of %d and %d is %d \n", n1, n2, t->data);

	return 0;
}
void print(int i) {
	std::cout << i << std::endl;
}

void printVector(vector<int>& v) {
	cout << "printing out of vector in a function" << endl;
	//Test boost lambda functions
	//for_each(v.begin(), v.end(), print);

	for (int i = 0; i < v.size(); i++) {
		cout << "vector [" << i << "] >>" << v[i] << endl;
	}
}

void getDate(std::string date) {
	vector<string> ret;

	std::string delimiter = "/";

	size_t pos = 0;
	std::string token;
	while ((pos = date.find(delimiter)) != std::string::npos) {
		token = date.substr(0, pos);
		ret.push_back(token);
		date.erase(0, pos + delimiter.length());
	}
	ret.push_back(date);
	for (int i = 0; i < ret.size(); i++) {
#include <sstream>
		stringstream geek(ret[i]);
		int x = 0;
		geek >> x;

		cout << "num[" << i << "] >> " << x << endl;
	}
}

enum Color {
	red = 1, green = 2, blue = 3
};

void printEnum(int n) {
	Color c = static_cast<Color>(n);
	cout << "number >> " << c << endl;
}

int main() {

	cout << "boost program version: " << BOOST_LIB_VERSION << endl;
	pointer_references();

	using namespace std;
	using namespace global;

	int numbers[5] = { 1, 2, 3, 5, 6 };
	int len = sizeof(numbers) / sizeof(numbers[0]);

	int num = numbers[0];
	ListNode* currentNode = newListNode(num);
	ListNode* head = currentNode;

	for (int i = 1; i < len; i++) {
		int node = numbers[i];
		ListNode* nextNode = newListNode(node);
		currentNode = addNode(currentNode, nextNode);
	}

	while (head != NULL) {
		cout << "data >> " << head->data << endl;
		head = head->next;
	}

	Base base(10); // = new Base(10);
	cout << "value stored in base >> " << base.getIntValue() << endl;

	int nValue = global::max(3, 7); // returns 7
	cout << "int value >  " << nValue << endl;

//	int resp = connect_db();
//	cout << "output of the connection >> " << resp << endl;

	// cannot use the namespace as multipleinheritace also has similar class
	string firstName("Abhishek");
	string lastName("Tandon");
	int age = 10;

	Person abhishek(firstName, lastName, age);
	Person another(abhishek);
	cout << "Another way of invoking copy constructor..." << endl;
	Person someOne = abhishek;

	int ret = findmax(3, 5);
	cout << "outputting the max using template function >> " << ret << endl;

	Person* person = getPersonRef(firstName, lastName, age);
	cout << "returning the object using pointer. Age : " << (*person).age
			<< " - Name << " << (*person).firstName << endl;

	std::vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(2);

	printVector(v);

	boost::scoped_ptr<int> i(new int);
	*i = -5;

	cout << "calling get() function on scoped_ptr >> " << *i.get() << endl;
	i.reset(new int);

	cout << "calling get() function on scoped_ptr after resetting >> "
			<< *i.get() << endl;

	std: string date = "11/12/2017";
	getDate(date);
	printEnum(1);

	return 0;
}

