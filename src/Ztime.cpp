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

#ifndef ZTIME_CPP_INCLUDED
#define ZTIME_CPP_INCLUDED
#include "Ztime.h"
namespace ZONED
{

Ztime::Ztime()
{
	CPFERR= false ; CPFMSG = "";
	
	am_pm = "24";
	hu = 0 ; hr =0 ;min =0 ; sec =0 ;

	// Get current time
	std::chrono::time_point<std::chrono::system_clock> time_now = std::chrono::system_clock::now();
	std::time_t time_now_t = std::chrono::system_clock::to_time_t(time_now);
	// Format time and print using strftime
	std::tm now_tm = *std::localtime(&time_now_t);

	
	 hu		= now_tm.tm_hour;
	 min	= now_tm.tm_min;
	 sec	= now_tm.tm_sec;

	 get_hour();

}

void Ztime::hms(unsigned int h = 0, unsigned int m = 0, unsigned int s = 0 , std::string ampm = "24" )
{
	CPFERR= false ; CPFMSG = "";

	 hu = 0 ; hr =0 ;min =0 ; sec =0 ;
	if( ampm != "24" && ampm != "AM" && ampm != "PM" && h > 23 && m > 59 && s >59 && (ampm == "AM" && h >12 ))
	{

		CPFERR= true ; CPFMSG = "PGTYPES_ AM OR PM OR 24  or  ZONED_BAD  define..."; return ;
	}
	else
	{
		hu = h ; min = m ; sec = s;  am_pm =ampm;
	
		if (am_pm == "PM" && hu < 12 ) hu += 12 ;

		get_hour();
	}
	
}

Ztime::~Ztime(){ }




Ztime Ztime::operator=(const char * _C_ )											/// default ampm 24  
{
	CPFERR= false ; CPFMSG = "";

	hu = 0 ; hr =0 ;min =0 ; sec =0 ; 
	
	std::string _S_ = _C_; 
	int h = std::stoi(_S_.substr(0,2));  
	int m = std::stoi(_S_.substr(3,2));	
	int s = std::stoi(_S_.substr(6,2));	
	if(  h > 23 || m > 59 ||s >59 )
	{
		CPFERR= true ; CPFMSG = "PGTYPES_ AM OR PM OR 24  or  ZONED_BAD  define..."; return *this;
	}
	else
	{
		hu = h ; min = m ; sec = s; am_pm="24";
		get_hour();
	}
	return *this;
}

void Ztime::chr(const char * _C_ , std::string ampm ="24")  
{
	CPFERR= false ; CPFMSG = "";

	hu = 0 ; hr =0 ;min =0 ; sec =0 ;
	
	std::string _S_ = _C_;
	int h = std::stoi(_S_.substr(0,2));
	int m = std::stoi(_S_.substr(3,2));
	int s = std::stoi(_S_.substr(6,2));
	if( (ampm != "24" && ampm != "AM" && ampm != "PM" )|| h > 23 || m > 59 ||s >59 || (ampm == "AM" && h >12 ))
	{
		CPFERR= true ; CPFMSG = "PGTYPES_ AM OR PM OR 24  or  ZONED_BAD  define..."; return ;
	}
	else
	{
		hu = h ; min = m ; sec = s;  am_pm= ampm;

		if (am_pm == "PM" && hu < 12 ) hu += 12 ;
		
		get_hour();
	}
	
}

Ztime Ztime::operator=(std::string _S_ )											/// default ampm 24 
{
	CPFERR= false ; CPFMSG = "";

	hu = 0 ; hr =0 ;min =0 ; sec =0 ;

	int h = std::stoi(_S_.substr(0,2));
	int m = std::stoi(_S_.substr(3,2));
	int s = std::stoi(_S_.substr(6,2));
	if( h > 23 || m > 59 || s >59 )
	{
		CPFERR= true ; CPFMSG = "PGTYPES_ AM OR PM OR 24  or  ZONED_BAD  define..."; return *this;
	}
	else
	{
		hu = h ; min = m ; sec = s;  am_pm ="24";

		get_hour();
	}
	return *this;
}
void Ztime::str(std::string _S_ , std::string ampm ="24") 
{
	CPFERR= false ; CPFMSG = "";

	hu = 0 ; hr =0 ;min =0 ; sec =0 ; 

	int h = std::stoi(_S_.substr(0,2));
	int m = std::stoi(_S_.substr(3,2));
	int s = std::stoi(_S_.substr(6,2));
	if( (ampm != "24" || ampm != "AM" || am_pm != "PM") || h > 23 || m > 59 || s >59 || (ampm != "24" && h >12 ))
	{
		CPFERR= true ; CPFMSG = "PGTYPES_ AM OR PM OR 24  or  ZONED_BAD  define..."; return ;
	}

	else
	{
		hu = h ; min = m ; sec = s;  am_pm= ampm;
	
		if (am_pm == "PM" && hu < 12 ) hu += 12 ;

		get_hour();
	}
	
}



void Ztime::add_hr(unsigned int _Hr_)
{
	for ( unsigned i = 0 ; i < _Hr_ ; i++)
	{	
    if (hu <23) hu ++ ; else hu =0 ; 
	}
    get_hour();
}


void Ztime::add_hr()
{
    if (hu <23) hu ++ ; else hu =0 ; 
    
    get_hour();
}


void Ztime::sub_hr()
{
    if (hu >0) hu -- ; else hu =23 ; 
    
    get_hour();
}
void Ztime::sub_hr(unsigned int _Hr_)
{
	for ( unsigned i = 0 ; i < _Hr_ ; i++)
	{	
    if (hu >0) hu -- ; else hu =23 ; 
	}
    get_hour();
}


void Ztime::add_min(unsigned int _Mn_)
{
	for ( unsigned i = 0 ; i < _Mn_ ; i++)
	{
		if (++min == 60)
		{
			hu = (hu + 1) % 24;
			min = 0;
		} 
	}

	get_hour();
}


void Ztime::add_min()
{
    if (++min == 60) {
        hu = (hu + 1) % 24;
        min = 0;
    } 

    get_hour();
}


void Ztime::sub_min(unsigned int _Mn_)
{
	for ( unsigned i = 0 ; i < _Mn_ ; i++)
	{
		if (--min < 0)
		{
			hu = (hu - 1) % 24;
			min = 59;
		}
	}

	get_hour();
}


void Ztime::sub_min()
{

    if (--min < 0) {
        hu = (hu - 1) % 24;
        min = 59;
    }

    get_hour();
}

void Ztime::add_sec(unsigned int _Sc_)
{
	for ( unsigned i = 0 ; i < _Sc_ ; i++)
	{
    if (++sec == 60) {
        min ++;
        sec = 0;
    }
	
    if (min == 60) {
        hu = (hu + 1) % 24;
        min = 0;
    }
	}

	get_hour();
}


void Ztime::add_sec()
{
    if (++sec == 60) {
        min = (min + 1) %60;
        sec = 0;
    }
	
    if (min == 60) {
        hu = (hu + 1) % 24;
        min = 0;
    }

    get_hour();
}


void Ztime::sub_sec(unsigned int _Sc_)
{
	for ( unsigned i = 0 ; i < _Sc_ ; i++)
	{
    if (--sec < 0) {
        min --;
        sec = 59;
    }
	
    if (min < 0) {
        hu = (hu - 1) % 24;
        min = 59;
    }
	}

	get_hour();
}


void Ztime::sub_sec()
{
    if (--sec < 0) {
        min --;
        sec = 59;
    }
	
    if (min < 0) {
        hu = (hu - 1) % 24;
        min = 59;
    }

    get_hour();
}

void Ztime::get_hour()
{
	if ( am_pm != "24")
	{	
		if ( hu < 12 )	am_pm = "AM" ;
		if ( hu > 12 )	am_pm = "PM" ;
		if ( hu > 12 )  hr = hu-12; else hr= hu ;
	}
	else hr = hu ;
	
}


const char * Ztime::print()
{
	get_hour();

    std::stringstream ss;
    if (am_pm == "24" )
    ss<< std::setfill('0') << std::setw(2)<<hu<< ":" << std::setw(2)<<min<<":"<< std::setw(2)<<sec;
    else
    ss<< std::setfill('0') << std::setw(2)<<hr<< ":" << std::setw(2)<<min<<":"<< std::setw(2)<<sec<<" " <<am_pm;
    return (const char*) ss.str().c_str();;
}


char*   Ztime::Chr()
{
    std::stringstream ss;
    ss<< std::setfill('0') << std::setw(2)<<hu<< ":" << std::setw(2)<<min<<":"<< std::setw(2)<<sec;
    return (char*) ss.str().c_str();
}

const char*   Ztime::ConstChr()
{
    std::stringstream ss;
    ss<< std::setfill('0') << std::setw(2)<<hu<< ":" << std::setw(2)<<min<<":"<< std::setw(2)<<sec;
    return   ss.str().c_str();
}

std::string   Ztime::Str()
{
    std::stringstream ss;
    ss<< std::setfill('0') << std::setw(2)<<hu<< ":" << std::setw(2)<<min<<":"<< std::setw(2)<<sec;

    return ss.str();
}

const char*   Ztime::getAmPm()
{
    return (const char*)  am_pm.c_str();
}


const char *  Ztime::cerror()
{
    return  CPFMSG.c_str() ;
}




}

#endif
