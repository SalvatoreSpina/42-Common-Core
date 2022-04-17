#ifndef Harl_H
#define Harl_H

#include <iostream>
#include <string>

#define DEBUG 0
#define INFO 1
#define WARNING 2
#define ERROR 3
#define MAX_LVL 4

using std::cout;
using std::endl;
using std::string;
using std::cerr;
using std::exit;

class Harl
{
private:
	void debug( void );
    void info( void );
    void warning( void );
    void error( void );

public:
	void complain(string level);
};

#endif