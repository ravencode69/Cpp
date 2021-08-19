#include<stdio.h>
#include <string.h>
struct pkt{
char ch1;
char ch2[2];
char ch3;
};
struct pkt in;
void aggregate();
void display(char n[4])
{
    in.ch1=n[0];
    //n=n/10;
    in.ch2[0]=n[1];
    //n=n/10;
    in.ch2[1]=n[2];
    //n=n/10;
    in.ch3=n[3];
    printf("Digits-%c %c %c %c\n",in.ch1,in.ch2[0],in.ch2[1],in.ch3);
    aggregate();
}
void aggregate()
{
    char s[4];
    s[0]=in.ch1;
    s[1]=in.ch2[0];
    s[2]=in.ch2[1];
    s[3]=in.ch3;
    printf("%s",s);

}
void main()
{
    
    char n[4];
    printf("Enter a  four digit number\n");
    scanf("%s",&n);
    display(n);
    

}