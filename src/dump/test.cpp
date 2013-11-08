//      test.cpp
//      
//      Copyright 2010 vishnu <vishnu@vishnu-laptop>
//      
//      This program is free software; you can redistribute it and/or modify
//      it under the terms of the GNU General Public License as published by
//      the Free Software Foundation; either version 2 of the License, or
//      (at your option) any later version.
//      
//      This program is distributed in the hope that it will be useful,
//      but WITHOUT ANY WARRANTY; without even the implied warranty of
//      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//      GNU General Public License for more details.
//      
//      You should have received a copy of the GNU General Public License
//      along with this program; if not, write to the Free Software
//      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
//      MA 02110-1301, USA.


#include <iostream>
#include<stdio.h>
#include<string.h>


char result[20];
void int2binstr(int i){		//to convert an integer to binary string.
  int j=0;char t[2];  
  if(i!=0){
  j=i;
  bin(i>>1);
  sprintf(t,"%d",j&0x01);
  
  strcat(result,t);
   }
   }
  
  
int main(int argc, char** argv)
{
	bin(23);
	printf("%s",result);
	return 0;
}
