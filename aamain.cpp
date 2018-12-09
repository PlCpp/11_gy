#include <string>
#include <iostream>
#include "arrapp.h"
#include <algorithm>
#include <vector>
#include "arrapp.h"

const int max = 1000;

int main()
{
  int your_mark = 1;
  // 2-es
  int s[] = {3, 2};
  array_appender<int> ia ( s, sizeof( s ) / sizeof( s[ 0 ] ) );
  for( int i = 0; i < max - 1; ++i )
  {
    ia.append( s, sizeof( s ) / sizeof( s[ 0 ] ) );
  }

  std::string hw[] = { "Hello", "World" };
  std::string langs[] = { "C++", "Ada", "Brainfuck" };
  std::string x[] = { "Goodbye", "Cruel", "World" };
  array_appender<std::string> sa ( hw, sizeof( hw ) / sizeof( hw[ 0 ] ) );
  sa.append( langs, sizeof( langs ) / sizeof( langs[ 0 ] ) );
  sa.append( x, sizeof( x ) / sizeof( x[ 0 ] ) );

  const array_appender<std::string> ha( hw, sizeof( hw ) / sizeof( hw[ 0 ] ) );


  if ( max * 2 == ia.size() && 3 == ia.at( max ) && 2 == ia.at( 3 ) &&
       &( s[ 0 ] ) == &(ia.at( max / 2 ) ) && 2 == ha.size() && 8 == sa.size() &&
       "C++" == sa.at( 2 ) && 7 == sa.at( 5 ).length() && &( ha.at( 0 ) ) == hw )
  {
    your_mark = ia.at( max + 1 );
  }

  // 3-as
  sa[ 0 ] = "Hallo";
  ++ia[ 1 ];
  if ( 'a'  == hw[ 0 ][ 1 ] && "Ada" == sa[ 3 ] && "World" == ha[ 1 ] )
  {
    your_mark = ia[ max - 1 ];
  }

   //4-es
  std::vector<int> vi;
  vi.push_back( 1 );
  ia.append( vi );
  ia[ 2 * max ] = 4;

  std::vector<std::string> vs;
  vs.push_back( "Some" );
  vs.push_back( "Text" );

  sa.append( vs );
  sa.append( vs );

  if ( 1 + 2 * max == ia.size() && 12 == sa.size() && "Some" == sa[ 10 ] )
  {
    your_mark = vi[ 0 ];
  }

  // 5-os
  array_appender<std::string>::iterator i = std::find( sa.begin(), sa.end(), "Hallo" );
  if ( 1 == std::count( ia.begin(), ia.end(), 4 ) && i == sa.begin() )
  {
    your_mark += std::count( sa.begin(), sa.end(), "C++" );
  }
  
  std::cout << "Your mark is " << your_mark;
  std::endl( std::cout );
}