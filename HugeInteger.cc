#include "HugeInteger.h"


//Constructor, initializes the vector to be zero 
HugeInteger::HugeInteger(){
	
}

//Copy constructor
HugeInteger::HugeInteger(const HugeInteger &other){
    digits = other.digits; //is this heap or stack allocation?
}

//Initializes this HugeInteger to have the value of the
//string of digits in s. If s contains characters that are not 
//digits, then you should ignore them.
HugeInteger::HugeInteger( const string &s ){
    for(int i = 0; i < s.length(); i++){
        if(isdigit(s.at(i))){
            digits.push_back(s.at(i)-'0');
        }
    }
}

//Overloads the == operator to
//return whether this object has the same value as rightSide.
bool HugeInteger::operator==( const HugeInteger & rightSide ){
   	if(this->digits == rightSide.digits)
		return true;
	return false;
}

//Overloading the + operator
const HugeInteger HugeInteger::operator+( const HugeInteger & rightSide ){
	vector<int> max = this->digits;
	vector<int> min = rightSide.digits;

	if (max.size() < min.size()) {
		max.swap(min);
	}
	
	//another vector to hold the sum
	HugeInteger sum;
	int rest = 0;

	for (int i = 0; i < min.size(); i++) {
		int c = min[i] + max[i] + rest;
		sum.digits.push_back(c % 10);
		rest = c / 10;
	}

	for (int i = min.size(); i < max.size(); i++) {
		int c = max[i] + rest;
		sum.digits.push_back(c % 10);
		rest = c / 10;
	}
	while (rest > 0) {
		sum.digits.push_back(rest % 10);
		rest /= 10;
	}

	return sum;
}

//Overloads the > operator to
//return whether this is greater than rightSide.
bool HugeInteger::operator>( const HugeInteger & rightSide ){
	if (this->digits.size() > rightSide.digits.size())
		return true;
	if (this->digits.size() == rightSide.digits.size()) {
		for (int i = 0; i < this->digits.size(); i++) {
			if (this->digits.at(i) > rightSide.digits.at(i))
				return true;
		}
	}

    return false;
}

//Returns whether or not this object has a value of 0.
bool HugeInteger::isZero() const{
	for (int i = 0; i < this->digits.size(); i++) {
		if (this->digits.at(i) != 0)
			return false;
	}
	return true;
}


//string representation of th econtects of the 
string HugeInteger::toString() const{
    stringstream stream;
    for(int i = 0; i < digits.size(); i++){
        stream << digits.at(i);
    }   
    string result = stream.str(); //convert the stream into a string object
    return result;
}


