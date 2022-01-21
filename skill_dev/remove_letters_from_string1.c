#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int main ()
{
    char str1[100], str2[100], str[100];
    int i = 0, j = 0, k = 0;
 
    printf ("Enter the First string:\n");
    gets (str1);
 
    printf ("Enter the Second string:\n");
    gets (str2);
 
    for (i = 0; str1[i]!= '\0'; i++)
    {
        for (j = 0; str2[j] != '\0'; j++)
        {
            if (str1[i] == str2[j])
            {
                continue;
            }
            else
            {
                str[k] = str2[j];
                k ++;
            }
        }
        str[k] = '\0';
        strcpy (str2, str);
        k = 0;
    }
 
    printf ("after removing characters from second string : %s\n", str2);
 
    return 0;
}
