/*Substitute two equal letters by the next letter of the alphabet (two letters convert to one):

"aa" => "b", "bb" => "c", .. "zz" => "a".

The equal letters do not have to be adjacent.
Repeat this operation until there are no possible substitutions left.
Return a string.

Example:

let str = "zzzab"
str = "azab"
str = "bzb"
str = "cz"
return "cz"

Notes

        The order of letters in the result is not important.
The letters "zz" transform into "a".
There will only be lowercase letters.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* sort_str(char* str);
void lastSurvivors(const char* str, char* out);

int main() {
    char* string = "xsdlafqpcmjytoikojsecamgdkehrqqgfknlhoudqygkbxftivfbpxhxtqgpkvsrfflpgrlhkbfnyftwkdebwfidmpauoteahyh";
    char* out = malloc(sizeof(char) * strlen(string));

    lastSurvivors(string, out);
}

void lastSurvivors(const char* str, char* out) {

    size_t counts[26]={0};
    for(const char* c = str; *c; ++c) {
        ++counts[*c-'a'];
    }

    do {
        for(size_t i = 0; i < 26; ++i) {
            size_t next = i == 25 ? 0 : i + 1;
            counts[next] += counts[i] / 2;
            counts[i] %= 2;
        }
    } while(counts[0] > 1);

    char* c = out;
    for(size_t i=0; i<26; ++i) {
        if(counts[i])
            *c++ = 'a'+i;
    }
    *c = '\0';
}

/** some kind of magic
*
  void lastSurvivors(const char* s, char* out) {
  unsigned long sum = 0;
  for (; *s; ++s)
    sum += 1ul << (*s - 'a');
  sum = (sum & ~(~0ul << 26)) + (sum >> 26);

  for (int i = 0; sum; sum >>= 1, ++i)
    if (sum & 1)
      *(out++) = i + 'a';
  *out = '\0';
}
*/