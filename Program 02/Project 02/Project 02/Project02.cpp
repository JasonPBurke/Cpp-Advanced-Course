// Project02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Customer.h"
#include "Order.h"
#include "Product.h"
#include<iostream>// for ostringstream
#include<ctime> // for asctime, localtime, time_t
//#define _CRT_SECURE_NO_WARNINGS
//#include<chrono>// included to provide system_clock::now()

using namespace std;

// SAVE AS A SSTREAM STRING??  THIS FUNCTION DOES NOT AGREE WITH THE INSTRUCTIONS!!!!!!
//void getTime(int &month, int &year, int &day)
void getTime(string& s) {

	ostringstream output;
	time_t now = time(NULL);
	output << (asctime(localtime(&now)));
	s = output.str();	
}


void outputReport(vector<Customer> customers, vector<Order> orders, vector<Product> products) {

	for (Customer aCust : customers) {
		static int i = 0;
		static int custAdjust = 1;
		cout << endl << "Customer ID is: " << aCust.getCustID() << endl;
		cout << "Customer name is: " << aCust.getName() << endl;
		cout << "Customer address is: " << aCust.getAddress() << endl;
		cout << "Customer order number is: " << aCust.getOrderNums(i) << endl;
		cout << "Customer creation time is: " << aCust.getCustomerCreationTime();
		cout << "Customer count is: " << aCust.getCustomerCount()-customers.size()+ custAdjust <<endl<<endl;
		custAdjust++;
	}
	for (Order custO : orders){
		static int j = 0;
		static int orderAdjust = 1;
		cout << "The order number is: " << custO.getOrderNum() << endl;
		cout << "Customer ID is: " << custO.getCustID() << endl;
		cout << "Customer's wanted product number is: " << custO.getProductNums(j) << endl;
		cout << "Customer's order creation time is: " << custO.getOrderCreationTime();
		cout << "Order count is: " << custO.getOrderCount()-orders.size()+ orderAdjust <<endl<<endl;
		orderAdjust++;
	}
	//cout << "Total orders entered: " << orders[0].
	for (Product prod : products) {
		static int prodAdjust = 1;
		cout << "Product Number: " << prod.getProductNum() << endl;
		cout << "Product Name:" << prod.getProductName() << endl;
		cout << "Product Description: " << prod.getProductDescription() << endl;
		cout << "Product Creation Time: " << prod.getProductCreationTime();
		cout << "Product Count: " << prod.getProductCount()-products.size()+prodAdjust <<endl<<endl;
		prodAdjust++;
	}
	//cout << "Total products entered: " << products[0].getProductCount();// cout the static productCount
	
	
}

int main() {

	Customer c; // instantiate an object c of the Customer class

	//Create three vector<class> to hold instantiated objects of the three classes
	vector<Customer> customers;
	vector<Order> orders;
	vector<Product> products;

	// TRY THIS IN A DO-WHILE LOOP TO ALLOW FOR MORE THAN ONE CUSTOMER TO BE ENTERED
	cout << "This program allows you to enter a new customer into the system, enter a " << endl
		<< "new product into the system, or create a new order for an existing customer." << endl;

	do {
		cout << endl << "Enter 'c' to add a new customer"
			<< endl << "Enter 'p' to add a new product"
			<< endl << "Enter 'o' to add a new order"
			<< endl << "Enter 'x' to exit and output the report"
			<< endl << " ?";
		char userChoice;
		cin >> userChoice;
		cin.clear();
		cin.ignore(1024, '\n');
		if (toupper(userChoice) == 'C') {
			Customer c;// if i create this here, i need to output through the vector 
			//customers.push_back(c); // this was creating a blank first element in the vector
			// PLACE BELOW CODE HERE
			cout << "Please enter customer ID number: ";
			static unsigned int ID;
			cin >> ID;
			cin.clear();
			cin.ignore(1024, '\n');
			c.setCustID(ID); // SET CUSTOMER ID 
			cout << endl;

			cout << "Please enter customer's name: ";
			string newName;
			getline(cin, newName);
			c.setName(newName);
			cout << endl;

			cout << "Please enter customer's address: ";
			string newAddress;
			getline(cin, newAddress);
			c.setAddress(newAddress);
			cout << endl;

			string timeStamp1;
			getTime(timeStamp1);
			c.setCustomerCreationTime(timeStamp1);
			c.setCustomerCount();

			cout << "Please enter order number: ";
			static int orderNum;// NOT SURE THIS NEEDS TO BE STATIC
			cin >> orderNum;
			cin.clear();
			cin.ignore(1024, '\n');
			c.setOrderNums(orderNum);
			customers.push_back(c);// add to customers vector
			cout << "Customer info saved." << endl;
			//orderNum++;
			continue;
		}
		if (toupper(userChoice) == 'P') {
			Product p;

			cout << "Please enter the Product Number: ";
			int prodNum;
			cin >> prodNum;
			cout << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			p.setProductNum(prodNum);

			cout << "Please enter the Product Name: ";
			string prodName;
			getline(cin, prodName);
			p.setProductName(prodName);
			
			cout << endl << "Please enter the Product Description: ";
			string prodDesc;
			getline(cin, prodDesc);
			p.setProductDescription(prodDesc);

			string timeStamp2;
			getTime(timeStamp2);
			p.setProductCreationTime(timeStamp2);
			p.setProductCount();

			products.push_back(p);
			cout << "Product info saved." << endl;
			continue;
		}
		else if (toupper(userChoice) == 'O') {
			
			Order o; // create an Order object.
			cout << "Please enter the order number: ";
			unsigned int newONum;
			cin >> newONum;
			o.setOrderNum(newONum);
			cout << "Please enter the Customer ID number: ";
			unsigned int cID;// passing the customer number directly
			cin >> cID;
			//for (int item : )

			o.setCustID(cID);
			cout << "Please enter the product number: ";
			int procuctNum;
			cin >> procuctNum;
			o.setProductNums(procuctNum);

			string timeStamp3;
			getTime(timeStamp3);
			o.setOrderCreationTime(timeStamp3);
			o.setOrderCount();

			orders.push_back(o);
			cout << "Order info saved." << endl;
			continue;// this should kick me out of the if statement i believe
		}
		else if (toupper(userChoice) == 'X') {
			break;
		}		
		else { 
			cout << "That is an invalid entry.  Try again." << endl;
		}		
	} while (true);
	

	// TRY A LOOP HERE TO LOOP THROUGH ALL CUSTOMERS THAT HAVE BEEN CREATED
	// A TRIPLE NESTED LOOP; CUSTOMER, ORDER, PRODUCT
	// PASS IN THE OBJECTS FROM THE VECTOR	customers[i]
	outputReport(customers, orders, products);// I DONT THINK PASSING IN ORDERnUM IS APPROPRIATE HERE..
	/*
	for (Customer cObject : customers) {

		for (Order oObject : orders) {
			for (Product pObject : products) {
				cout << "In nested loop" << endl;
				outputReport(cObject, oObject, pObject, 1);// you need to fix the 1 here..it
														  //  replaced the orderNum variable
			}
		}
	}
	*/

	system("PAUSE");
    return 0;
}