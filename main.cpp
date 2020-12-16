#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

bool isOperator(const string& input);
void performOp(const string& input, stack<int>& calcStack);

int main(){

	stack<int> calcStack;
	string input;

	while(true){
		cin >> input;

		int num;

		if(istringstream(input) >> num){
			calcStack.push(num);
		}

		else if(isOperator(input)){
			try {
				performOp(input, calcStack);
			} catch (const char* msg) {
     			cerr << msg << endl;
  			}
			
		}

		else if(input=="q"){
			return 1;
		}

		else{
			cout << "Invalid input" << endl;
		}
	}
	return 1;
}


bool isOperator(const string& input){
	string ops[] = {"-", "+", "*", "/"};

	for(int i = 0; i < 4;i++){
		if(input == ops[i]){
			return true;
		}
	}
	return false;
}


void performOp(const string& input, stack<int>& calcStack){
	int l, r, result;

	r = calcStack.top();
	calcStack.pop();

	l = calcStack.top();
	calcStack.pop();

	if(input == "-"){
		result = l - r;
	}
	else if(input == "+"){
		result = l + r;
	}
	else if(input == "*"){
		result = l * r;
	}
	else{
		if(r == 0) throw "Division by zero";
		result = l / r;
	}

	cout << result << endl;
	calcStack.push(result);
}
