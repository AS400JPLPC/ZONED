/*
 *
 * M. laroche jean Pierre  12-10-1951    laroche.jeanpierre@gmail.com
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 */

#ifndef ZTIME_H_INCLUDED
#define ZTIME_H_INCLUDED


#include <stdio.h>
#include <cstring>
#include <cstdio>
#include <iomanip>      // std::get_time
#include <ctime>        // struct std::tm
#include <chrono>
#include <sstream>
#include <iostream>
#include <exception>

 
namespace ZONED
{

#include <Zcomon.h>



class Ztime {
	private:

	int hu;
	int min;
	int sec;
	
	std::string  am_pm ;

	unsigned int hr;

	std::string	CPFMSG;				/// flag msg error
    
	protected:

	void get_hour();
		
    public:
    
	bool 	CPFERR	= false;	/// flag si erreur
    
	Ztime (); 																		// get heure system   am_pm = 24  
	Ztime operator=(const char *);													// date system ex 23:01:58 
	Ztime operator=(std::string );													// date system ex 23:01:58 
	~Ztime();
        
      
	void  hms(unsigned int, unsigned int, unsigned int , std::string);				// manuel H M S + AM/PM/24
	void  chr(const char * , std::string );											// date system ex 23:01:58 + AM/PM/24
	void  str(std::string  , std::string );											// date system ex 23:01:58 + AM/PM/24       
 
	char*         Chr();
	const char*   ConstChr();
	std::string   Str(); 

	const char* print();															// initialised
	const char* getAmPm();															// return am pm 24
	void add_hr();
	void add_hr(unsigned int);
	void add_min();
	void add_min(unsigned int);
	void add_sec();
	void add_sec(unsigned int);
	void sub_hr();
	void sub_hr(unsigned int);
	void sub_min();
	void sub_min(unsigned int);
	void sub_sec();
	void sub_sec(unsigned int);
        


///****************************************************************************
/// FONCTIONS util  --------------------------------------------------------
///****************************************************************************
	const char* 	cerror();

	friend std::istream& operator>>(std::istream& is,  Ztime& t)
	{
		std::string _var_ ;
		is >> _var_ ;
		t = _var_;
		return is;
	}
	
	friend std::ostream& operator<<(std::ostream& out, const Ztime& t)
	{
		auto oldfill = out.fill('0'); std::string outprt =""; if (t.am_pm !="24" ) outprt = " " + t.am_pm ;
		return out << std::setw(2)<< t.hr 
		<< ':' << std::setw(2) << t.min 
		<< ':' << std::setw(2) << t.sec << outprt<< std::setfill(oldfill);
	}
	
};

}
#endif
