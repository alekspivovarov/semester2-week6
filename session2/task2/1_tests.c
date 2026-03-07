#include <stdio.h>
#include <string.h>
#include <assert.h>

int is_palindrome(const char *str);

int main(void) {
  // Use 'assert' to write some tests - does the function work?
  // consider what is and is not a palindrome!
  assert(is_palindrome("madam") == 1);
assert(is_palindrome("a") == 1);
assert(is_palindrome("racecar") == 1);
assert(is_palindrome("Racecar") == 0);
assert(is_palindrome("Hello") == 0);
assert(is_palindrome("z z") == 1);
printf("All tests passed");
  return 0;
}

/**
 * @brief Checks if a given string is a palindrome.
 * 
 * @param str The string to be checked.
 * @return int 1 if the string is a palindrome, 0 otherwise.
 */
int is_palindrome(const char *str) {
  int len = strlen(str);
  for (int i = 0; i < len / 2; i++) {
    if (str[i] != str[len - i - 1]) {
      return 0;
    }
  }
  return 1;
}



