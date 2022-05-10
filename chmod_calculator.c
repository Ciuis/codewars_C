/*Lot of junior developer can be stuck when they need to change the access permission to a file or a directory in an Unix-like operating systems.

To do that they can use the chmod command and with some magic trick they can change the permissionof a file or a directory. For more information about the chmod command you can take a look at the wikipedia page.

chmod provides two types of syntax that can be used for changing permissions. An absolute form using octal to denote which permissions bits are set e.g: 766. Your goal in this kata is to define the octal you need to use in order to set yout permission correctly.

Here is the list of the permission you can set with the octal representation of this one.

User
read (4)
write (2)
execute (1)
Group
read (4)
write (2)
execute (1)
Other
read (4)
write (2)
execute (1)

The method take a hash in argument this one can have a maximum of 3 keys (owner,group,other). Each key will have a 3 chars string to represent the permission, for example the string rw- say that the user want the permission read, write without the execute. If a key is missing set the permission to ---

Note: chmod allow you to set some special flags too (setuid, setgid, sticky bit) but to keep some simplicity for this kata we will ignore this one.*/

// user, group and other can be NULL, in which case they are
// equivalent to "---"

#include <stdio.h>
#include <stdlib.h>

char* itoa(int val, int base);
int convert(const char type[3]);
char *chmod_calculator (char octal[4], const char user[3], const char group[3], const char other[3]);

int main() {
    char octal[4];
    chmod_calculator(octal, "---", "---", "---");

    for (int i = 0; i < 4; ++i) {
        printf("%c", octal[i]);
    }

}

int convert(const char type[3]) {
    int res = 0;
    if (type == NULL) return 0;
    for (int i = 0; i < 3; ++i) {
        switch (type[i]) {
            case 'r':
                res += 4;
                break;
            case 'w':
                res += 2;
                break;
            case 'x':
                res += 1;
                break;
            default:
                res += 0;
                break;
        }
    }

    return res;
}


char *chmod_calculator (char octal[4], const char user[3], const char group[3], const char other[3]) {

    int a = convert(user);
    int b = convert(group);
    int c = convert(other);

    octal[0] = a + '0';
    octal[1] = b + '0';
    octal[2] = c + '0';

    octal[3] = '\0';


/*    sprintf(&octal[0], "%c", a);
    sprintf(&octal[1], "%c", b);
    sprintf(&octal[2], "%c", c);*/

    //*octal = '\0';
    return octal;
}