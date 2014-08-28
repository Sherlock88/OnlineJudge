/* http://cboard.cprogramming.com/c-programming/118509-beginner-question-problem-scanf-strings-help.html */

#include <stdio.h>
#include <string.h>
 
int main (int argc, const char * argv[]) {
 
    char        firstname[31];
    char        lastname[31];
    char        fullname[63];
     
    printf( "What is your FIRST name: " );
    //scanf( "%[^\n]", firstname );      // Accepts everything until it sees a \n
    scanf( "%[^\n]%*c", firstname );      // Eat up trailing \r or \n
 
    printf( "What is your LAST name: " );
    scanf( "%[^\n]", lastname );      // Accepts everything until it sees a \n
     
    strcpy( fullname, firstname );
    strcat( fullname, " " );
    strcat( fullname, lastname );
     
    printf( "Your FULL name is %s\n", fullname);
           
    return 0;
}