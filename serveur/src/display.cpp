#include	<iostream>
#include	<ctime>

#define		INFO "[\033[32mINFO\033[0m]"
#define		ERRO "[\033[31mINFO\033[0m]"

using namespace	std;

// static void    	display_hour()
// {
//   time_t	now = time(0);
//   tm		*ltm = localtime(&now);
  
//   cout << "["<< 1 + ltm->tm_hour << ":";
//   cout << 1 + ltm->tm_min << ":";
//   cout << 1 + ltm->tm_sec << "]";
// }

void		display_info(char *msg)
{
  cout // << display_hour()
       << INFO << " : " << msg << endl;
}

void		display_error(char *msg)
{
  cout // << display_hour()
       << ERRO << " : " << msg << endl;
}
