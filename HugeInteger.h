//J.Chase
//CS343
//21/09/2017

#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class HugeInteger{
private:
    vector<int> digits;

public:
    HugeInteger(); //constructor
    HugeInteger( const HugeInteger & ); //copy constructor
    HugeInteger( const string & );

    bool operator==( const HugeInteger & );
    const HugeInteger operator+( const HugeInteger & );
    bool operator>( const HugeInteger & );
    
    bool isZero() const;
    string toString() const;
};