## Search Algorithms

### Resources

**Read or watch**:

- [Search algorithm](https://en.wikipedia.org/wiki/Search_algorithm)
- [Space complexity (1)](https://www.geeksforgeeks.org/g-fact-86/)

### Requirements

#### General

- Allowed editors: `vi`, `vim`, `emacs`
- All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
- All your files should end with a new line
- A `README.md` file, at the root of the folder of the project, is mandatory
- Your code should use the `Betty` style. It will be checked using [betty-style.pl](https://github.com/alx-tools/Betty/blob/master/betty-style.pl "betty-style.pl") and [betty-doc.pl](https://github.com/alx-tools/Betty/blob/master/betty-doc.pl "betty-doc.pl")
- You are not allowed to use global variables
- No more than 5 functions per file
- You are only allowed to use the `printf` function of the standard library. Any call to another function like `strdup`, `malloc`, … is forbidden.
- In the following examples, the `main.c` files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own `main.c` files at compilation. Our `main.c` files might be different from the one shown in the examples
- The prototypes of all your functions should be included in your header file called `search_algos.h`
- Don’t forget to push your header file
- All your header files should be include guarded

### More Info

You will be asked to write files containing big O notations. Please use this format:

- `O(1)`
- `O(n)`
- `O(n!)`
- n\*m -> `O(nm)`
- n square -> `O(n^2)`
- sqrt n -> `O(sqrt(n))`
- log(n) -> `O(log(n))`
- n \* log(n) -> `O(nlog(n))`
- …

### Tasks

<details>
<summary>0. Linear search</summary>

Develop a function that implements the [Linear search algorithm](https://en.wikipedia.org/wiki/Linear_search) to find a specific value in an integer array.

Function Prototype: `int linear_search(int *array, size_t size, int value);`
In this prototype:
- `array` is a pointer pointing to the first element of the array you want to search in.
- `size` represents the total number of elements in the array.
- `value` is the specific value you're looking for in the array.
- The function should return the index of the first occurrence of the `value` in the array.
- If the `value` is not found in the array or if the `array` is NULL, the function should return ``-1``.

Also, each time a value in the array is compared to the `value` you're searching for, that value should be printed out. (Refer to the example below for more clarity)

```shell
wilfried@0x1E-search_algorithms$ cat 0-main.c 
#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * main - Entry point
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
    int array[] = {
        10, 1, 42, 3, 4, 42, 6, 7, -1, 9
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Found %d at index: %d\n\n", 3, linear_search(array, size, 3));
    printf("Found %d at index: %d\n\n", 42, linear_search(array, size, 42));
    printf("Found %d at index: %d\n", 999, linear_search(array, size, 999));
    return (EXIT_SUCCESS);
}
wilfried@0x1E-search_algorithms$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 0-main.c 0-linear.c -o 0-linear
wilfried@0x1E-search_algorithms$ ./0-linear 
Value checked array[0] = [10]
Value checked array[1] = [1]
Value checked array[2] = [42]
Value checked array[3] = [3]
Found 3 at index: 3

Value checked array[0] = [10]
Value checked array[1] = [1]
Value checked array[2] = [42]
Found 42 at index: 2

Value checked array[0] = [10]
Value checked array[1] = [1]
Value checked array[2] = [42]
Value checked array[3] = [3]
Value checked array[4] = [4]
Value checked array[5] = [42]
Value checked array[6] = [6]
Value checked array[7] = [7]
Value checked array[8] = [-1]
Value checked array[9] = [9]
Found 999 at index: -1
```

***
**File:**
- File: `0-linear.c`
</details>


<details>
<summary>1. Binary search</summary>

Construct a function that utilizes the [Binary search algorithm](https://en.wikipedia.org/wiki/Binary_search_algorithm) to locate a specific value in a sorted integer array.

Function Prototype: `int binary_search(int *array, size_t size, int value);`
In this prototype:
- `array` is a pointer that points to the first element of the array to be searched.
- `size` denotes the total number of elements in the array.
- `value` is the specific value you're searching for in the array.
- The function should return the index of the `value` in the array.
- It's assumed that the `array` will be sorted in ascending order and the `value` won't appear more than once in the array.
- If the `value` is not found in the array or if the `array` is NULL, the function should return -1.

Additionally, the array being searched should be printed every time it changes, such as at the beginning and when you search a subarray. (Refer to the example for more details)

```shell
wilfried@0x1E-search_algorithms$ cat 1-main.c 
#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * main - Entry point
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
    int array[] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Found %d at index: %d\n\n", 2, binary_search(array, size, 2));
    printf("Found %d at index: %d\n\n", 5, binary_search(array, 5, 5));
    printf("Found %d at index: %d\n", 999, binary_search(array, size, 999));
    return (EXIT_SUCCESS);
}
wilfried@0x1E-search_algorithms$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 1-main.c 1-binary.c -o 1-binary
wilfried@0x1E-search_algorithms$ ./1-binary 
Searching in array: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
Searching in array: 0, 1, 2, 3
Searching in array: 2, 3
Found 2 at index: 2

Searching in array: 0, 1, 2, 3, 4
Searching in array: 3, 4
Searching in array: 4
Found 5 at index: -1

Searching in array: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
Searching in array: 5, 6, 7, 8, 9
Searching in array: 8, 9
Searching in array: 9
Found 999 at index: -1
```

***
**File:**
- File: `1-binary.c`
</details>


<details>
<summary>2. Big O #0</summary>

What is the `time complexity` (worst case) of a linear search in an array of size `n`?

***
**File:**
- File: `2-O`
</details>


<details>
<summary>3. Big O #1</summary>

What is the `space complexity` (worst case) of an iterative linear search algorithm in an array of size `n`?

***
**File:**
- File: `3-O`
</details>


<details>
<summary>4. Big O #2</summary>

What is the `time complexity` (worst case) of a binary search in an array of size `n`?

***
**File:**
- File: `4-O`
</details>


<details>
<summary>5. Big O #3</summary>

What is the `space complexity` (worst case) of a binary search in an array of size `n`?

***
**File:**
- File: `5-O`
</details>


<details>
<summary>6. Big O #4</summary>

What is the space complexity of this function / algorithm?

```C
int **allocate_map(int n, int m)
{
     int **map;

     map = malloc(sizeof(int *) * n);
     for (size_t i = 0; i < n; i++)
     {
          map[i] = malloc(sizeof(int) * m);
     }
     return (map);
}
```

***
**File:**
- File: `6-O`
</details>


<details>
<summary>7. Jump search</summary>

Sure, here's a rephrased version:

Develop a function that employs the [Jump search algorithm](https://en.wikipedia.org/wiki/Jump_search) to find a specific value in a sorted integer array.

Function Prototype: `int jump_search(int *array, size_t size, int value);`
In this prototype:
- `array` is a pointer that points to the first element of the array to be searched.
- `size` represents the total number of elements in the array.
- `value` is the specific value you're searching for in the array.
- The function should return the index of the first occurrence of the `value` in the array.
- It's assumed that the `array` will be sorted in ascending order.
- If the `value` is not found in the array or if the `array` is NULL, the function should return `-1`.

The jump step should be the square root of the size of the array. You can use the `sqrt()` function from `<math.h>` (don't forget to compile with `-lm`).

Also, each time a value in the array is compared to the `value` you're searching for, that value should be printed out. (Refer to the example for more clarity)

```shell
wilfried@0x1E-search_algorithms$ cat 100-main.c 
#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * main - Entry point
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
    int array[] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Found %d at index: %d\n\n", 6, jump_search(array, size, 6));
    printf("Found %d at index: %d\n\n", 1, jump_search(array, size, 1));
    printf("Found %d at index: %d\n", 999, jump_search(array, size, 999));
    return (EXIT_SUCCESS);
}
wilfried@0x1E-search_algorithms$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 100-main.c 100-jump.c -lm -o 100-jump
wilfried@0x1E-search_algorithms$ ./100-jump 
Value checked array[0] = [0]
Value checked array[3] = [3]
Value found between indexes [3] and [6]
Value checked array[3] = [3]
Value checked array[4] = [4]
Value checked array[5] = [5]
Value checked array[6] = [6]
Found 6 at index: 6

Value checked array[0] = [0]
Value found between indexes [0] and [3]
Value checked array[0] = [0]
Value checked array[1] = [1]
Found 1 at index: 1

Value checked array[0] = [0]
Value checked array[3] = [3]
Value checked array[6] = [6]
Value checked array[9] = [9]
Value found between indexes [9] and [12]
Value checked array[9] = [9]
Found 999 at index: -1
```

***
**File:**
- File: `100-jump.c`
</details>


<details>
<summary>8. Big O #5</summary>

What is the `time complexity` (average case) of a jump search in an array of size `n`, using `step = sqrt(n)`?

***
**File:**
- File: `101-O`
</details>


<details>
<summary>9. Interpolation search</summary>

Construct a function that employs the [Interpolation search algorithm](https://en.wikipedia.org/wiki/Interpolation_search) to locate a specific value in a sorted integer array.

Function Prototype: `int interpolation_search(int *array, size_t size, int value);`
In this prototype:
- `array` is a pointer that points to the first element of the array to be searched.
- `size` represents the total number of elements in the array.
- `value` is the specific value you're searching for in the array.
- The function should return the index of the first occurrence of the `value` in the array.
- It's assumed that the `array` will be sorted in ascending order.
- If the `value` is not found in the array or if the `array` is NULL, the function should return `-1`.

To determine the probe position, you can use the following formula: `size_t pos = low + (((double)(high - low) / (array[high] - array[low])) * (value - array[low]))`.

Also, each time a value in the array is compared to the `value` you're searching for, that value should be printed out. (Refer to the example for more clarity)

```shell
wilfried@0x1E-search_algorithms$ cat 102-main.c 
#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * main - Entry point
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
    int array[] = {
        0, 0, 1, 2, 2, 2, 2, 3, 3, 4, 4, 5, 6, 6, 7, 8, 8, 8, 9, 9
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Found %d at index: %d\n\n", 3, interpolation_search(array, size, 3));
    printf("Found %d at index: %d\n\n", 7, interpolation_search(array, size, 7));
    printf("Found %d at index: %d\n", 999, interpolation_search(array, size, 999));
    return (EXIT_SUCCESS);
}
wilfried@0x1E-search_algorithms$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 102-main.c 102-interpolation.c -o 102-interpolation
wilfried@0x1E-search_algorithms$ ./102-interpolation 
Value checked array[6] = [2]
Value checked array[7] = [3]
Found 3 at index: 7

Value checked array[14] = [7]
Found 7 at index: 14

Value checked array[2109] is out of range
Found 999 at index: -1
```

***
**File:**
- File: `102-interpolation.c`
</details>


<details>
<summary>10. Exponential search</summary>

Sure, here's a rephrased version:

Develop a function that employs the [Exponential search algorithm](https://en.wikipedia.org/wiki/Exponential_search) to locate a specific value in a sorted integer array.

Function Prototype: `int exponential_search(int *array, size_t size, int value);`
In this prototype:
- `array` is a pointer that points to the first element of the array to be searched.
- `size` represents the total number of elements in the array.
- `value` is the specific value you're searching for in the array.
- The function should return the index of the first occurrence of the `value` in the array.
- It's assumed that the `array` will be sorted in ascending order.
- If the `value` is not found in the array or if the `array` is NULL, the function should return `-1`.

You should use powers of 2 as the exponential ranges to search in your array. Also, each time a value in the array is compared to the `value` you're searching for, that value should be printed out.

Once you've identified the appropriate range, you need to use a binary search. Every time you split the array, you should print the new array (or subarray) you're searching in. (Refer to the example for more clarity)

```shell
wilfried@0x1E-search_algorithms$ cat 103-main.c 
#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * main - Entry point
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
    int array[] = {
        0, 1, 2, 3, 4, 7, 12, 15, 18, 19, 23, 54, 61, 62, 76, 99
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Found %d at index: %d\n\n", 62, exponential_search(array, size, 62));
    printf("Found %d at index: %d\n\n", 3, exponential_search(array, size, 3));
    printf("Found %d at index: %d\n", 999, exponential_search(array, size, 999));
    return (EXIT_SUCCESS);
}
wilfried@0x1E-search_algorithms$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 103-main.c 103-exponential.c -o 103-exponential
wilfried@0x1E-search_algorithms$ ./103-exponential 
Value checked array[1] = [1]
Value checked array[2] = [2]
Value checked array[4] = [4]
Value checked array[8] = [18]
Value found between indexes [8] and [15]
Searching in array: 18, 19, 23, 54, 61, 62, 76, 99
Searching in array: 61, 62, 76, 99
Found 62 at index: 13

Value checked array[1] = [1]
Value checked array[2] = [2]
Value found between indexes [2] and [4]
Searching in array: 2, 3, 4
Found 3 at index: 3

Value checked array[1] = [1]
Value checked array[2] = [2]
Value checked array[4] = [4]
Value checked array[8] = [18]
Value found between indexes [8] and [15]
Searching in array: 18, 19, 23, 54, 61, 62, 76, 99
Searching in array: 61, 62, 76, 99
Searching in array: 76, 99
Searching in array: 99
Found 999 at index: -1
```
***
**File:**
- File: `103-exponential.c`
</details>


<details>
<summary>11. Advanced binary search</summary>

You might have observed that the standard binary search doesn't always return the index of the first occurrence of a value in the array (if this value appears more than once in the array). In this task, you'll need to address this issue.

Develop a function that implements a search for a specific value in a sorted integer array.

Function Prototype: `int advanced_binary(int *array, size_t size, int value);`
In this prototype:
- `array` is a pointer that points to the first element of the array to be searched.
- `size` represents the total number of elements in the array.
- `value` is the specific value you're searching for in the array.
- The function should return the index of the first occurrence of the `value` in the array.
- It's assumed that the `array` will be sorted in ascending order.
- If the `value` is not found in the array or if the `array` is NULL, the function should return -1.

Each time you split the array, you should print the new array (or subarray) you're searching in. 

You need to use recursion for this task. You're allowed to use only one loop (while, for, do while, etc.) to print the array. (Refer to the example for more clarity)

```shell
wilfried@0x1E-search_algorithms$ cat 104-main.c 
#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * main - Entry point
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
    int array[] = {
        0, 1, 2, 5, 5, 6, 6, 7, 8, 9
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Found %d at index: %d\n\n", 8, advanced_binary(array, size, 8));
    printf("Found %d at index: %d\n\n", 5, advanced_binary(array, size, 5));
    printf("Found %d at index: %d\n", 999, advanced_binary(array, size, 999));
    return (EXIT_SUCCESS);
}
wilfried@0x1E-search_algorithms$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 104-main.c 104-advanced_binary.c -o 104-advanced_binary
wilfried@0x1E-search_algorithms$ ./104-advanced_binary
Searching in array: 0, 1, 2, 5, 5, 6, 6, 7, 8, 9
Searching in array: 6, 6, 7, 8, 9
Searching in array: 8, 9
Found 8 at index: 8

Searching in array: 0, 1, 2, 5, 5, 6, 6, 7, 8, 9
Searching in array: 0, 1, 2, 5, 5
Searching in array: 5, 5
Found 5 at index: 3

Searching in array: 0, 1, 2, 5, 5, 6, 6, 7, 8, 9
Searching in array: 6, 6, 7, 8, 9
Searching in array: 8, 9
Searching in array: 9
Found 999 at index: -1
```

***
**File:**
- File: `104-advanced_binary.c`
</details>


<details>
<summary>12. Jump search in a singly linked list</summary>

You may perceive that a linear search might not be as efficient as other algorithms, correct? However, let's examine its performance with a singly linked list.

Please include the following data structure in your `search_algos.h` header file:

```c
/**
 * struct listint_s - singly linked list
 *
 * @n: Integer
 * @index: Index of the node in the list
 * @next: Pointer to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct listint_s
{
    int n;
    size_t index;
    struct listint_s *next;
} listint_t;
```
Develop a function that implements the Jump search algorithm to locate a specific value in a sorted list of integers.

Function Prototype: `listint_t *jump_list(listint_t *list, size_t size, int value);`
In this prototype:
- `list` is a pointer that points to the head of the list to be searched.
- `size` represents the total number of nodes in the list.
- `value` is the specific value you're searching for in the list.
- The function should return a pointer to the first node where the `value` is located.
- It's assumed that the `list` will be sorted in ascending order.
- If the `value` is not found in the list or if the `list` is `NULL`, the function should return `NULL`.

You should use the square root of the size of the list as the jump step. You can use the `sqrt()` function from `<math.h>` (don't forget to compile with `-lm`).

Each time you compare a value in the list to the `value` you're searching for, that value should be printed out.

NOTE: The functions used in the example can be found [here](https://github.com/alx-tools/0x1D.c/tree/master/listint). You don't need to push them, as we will compile your file with our own implementation during the correction.

```shell
wilfried@0x1E-search_algorithms$ cat 105-main.c 
#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

listint_t *create_list(int *array, size_t size);
void print_list(const listint_t *list);
void free_list(listint_t *list);

/**
 * main - Entry point
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
    listint_t *list, *res;
    int array[] = {
        0, 1, 2, 3, 4, 7, 12, 15, 18, 19, 23, 53, 61, 62, 76, 99
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    list = create_list(array, size);
    print_list(list);

    res =  jump_list(list, size, 53);
    printf("Found %d at index: %lu\n\n", 53, res->index);
    res =  jump_list(list, size, 2);
    printf("Found %d at index: %lu\n\n", 2, res->index);
    res =  jump_list(list, size, 999);
    printf("Found %d at index: %p\n", 999, (void *) res);

    free_list(list);
    return (EXIT_SUCCESS);
}
wilfried@0x1E-search_algorithms$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 105-main.c 105-jump_list.c listint/*.c -lm -o 105-jump
wilfried@0x1E-search_algorithms$ ./105-jump 
List :
Index[0] = [0]
Index[1] = [1]
Index[2] = [2]
Index[3] = [3]
Index[4] = [4]
Index[5] = [7]
Index[6] = [12]
Index[7] = [15]
Index[8] = [18]
Index[9] = [19]
Index[10] = [23]
Index[11] = [53]
Index[12] = [61]
Index[13] = [62]
Index[14] = [76]
Index[15] = [99]

Value checked at index [4] = [4]
Value checked at index [8] = [18]
Value checked at index [12] = [61]
Value found between indexes [8] and [12]
Value checked at index [8] = [18]
Value checked at index [9] = [19]
Value checked at index [10] = [23]
Value checked at index [11] = [53]
Found 53 at index: 11

Value checked at index [4] = [4]
Value found between indexes [0] and [4]
Value checked at index [0] = [0]
Value checked at index [1] = [1]
Value checked at index [2] = [2]
Found 2 at index: 2

Value checked at index [4] = [4]
Value checked at index [8] = [18]
Value checked at index [12] = [61]
Value checked at index [15] = [99]
Value found between indexes [12] and [15]
Value checked at index [12] = [61]
Value checked at index [13] = [62]
Value checked at index [14] = [76]
Value checked at index [15] = [99]
Found 999 at index: (nil)
```

***
**File:**
- File: `105-jump_list.c`
</details>


<details>
<summary>13. Linear search in a skip list</summary>

As you may have observed, searching for a specific value in a singly linked list inevitably requires traversing each element of the list. A common strategy to enhance the time complexity of a search in a singly linked list is to modify the list itself by adding an "express lane" for navigation. A linked list equipped with an express lane is referred to as a [skip list](https://en.wikipedia.org/wiki/Skip_list). However, this modification comes with its own implications. Indeed, the space complexity of a search in such a list will increase as ``sizeof(skiplist_t) > sizeof(listint_t)`` (refer to the example below).

Please incorporate the following data structure in your `search_algos.h` header file:

```c
/**
 * struct skiplist_s - Singly linked list with an express lane
 *
 * @n: Integer
 * @index: Index of the node in the list
 * @next: Pointer to the next node
 * @express: Pointer to the next node in the express lane
 *
 * Description: singly linked list node structure with an express lane
 */
typedef struct skiplist_s
{
    int n;
    size_t index;
    struct skiplist_s *next;
    struct skiplist_s *express;
} skiplist_t;
```
Develop a function that implements a search for a specific value in a sorted skip list of integers.

Function Prototype: `skiplist_t *linear_skip(skiplist_t *list, int value);`
In this prototype:
- `list` is a pointer that points to the head of the skip list to be searched.
- A node of the express lane is positioned at every index which is a multiple of the square root of the size of the list (refer to the example below).
- `value` is the specific value you're searching for in the list.
- The function should return a pointer to the first node where the `value` is located.
- It's assumed that the `list` will be sorted in ascending order.
- If the `value` is not found in the list or if the `list` is NULL, the function should return NULL.

Each time you compare a value in the list to the `value` you're searching for, that value should be printed out.

NOTE: The functions used in the example can be found [here](https://github.com/alx-tools/0x1D.c/tree/master/skiplist). You don't need to push them, as we will compile your file with our own implementation during the correction.

```shell
wilfried@0x1E-search_algorithms$ cat 106-main.c 
#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

skiplist_t *create_skiplist(int *array, size_t size);
void print_skiplist(const skiplist_t *list);
void free_skiplist(skiplist_t *list);

/**
 * main - Entry point
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
    skiplist_t *list, *res;
    int array[] = {
        0, 1, 2, 3, 4, 7, 12, 15, 18, 19, 23, 53, 61, 62, 76, 99
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    list = create_skiplist(array, size);
    print_skiplist(list);

    res =  linear_skip(list, 53);
    printf("Found %d at index: %lu\n\n", 53, res->index);
    res =  linear_skip(list, 2);
    printf("Found %d at index: %lu\n\n", 2, res->index);
    res =  linear_skip(list, 999);
    printf("Found %d at index: %p\n", 999, (void *) res);

    free_skiplist(list);
    return (EXIT_SUCCESS);
}
wilfried@0x1E-search_algorithms$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 106-main.c 106-linear_skip.c skiplist/*.c -lm -o 106-linear
wilfried@0x1E-search_algorithms$ ./106-linear 
List :
Index[0] = [0]
Index[1] = [1]
Index[2] = [2]
Index[3] = [3]
Index[4] = [4]
Index[5] = [7]
Index[6] = [12]
Index[7] = [15]
Index[8] = [18]
Index[9] = [19]
Index[10] = [23]
Index[11] = [53]
Index[12] = [61]
Index[13] = [62]
Index[14] = [76]
Index[15] = [99]

Express lane :
Index[0] = [0]
Index[4] = [4]
Index[8] = [18]
Index[12] = [61]

Value checked at index [4] = [4]
Value checked at index [8] = [18]
Value checked at index [12] = [61]
Value found between indexes [8] and [12]
Value checked at index [8] = [18]
Value checked at index [9] = [19]
Value checked at index [10] = [23]
Value checked at index [11] = [53]
Found 53 at index: 11

Value checked at index [4] = [4]
Value found between indexes [0] and [4]
Value checked at index [0] = [0]
Value checked at index [1] = [1]
Value checked at index [2] = [2]
Found 2 at index: 2

Value checked at index [4] = [4]
Value checked at index [8] = [18]
Value checked at index [12] = [61]
Value found between indexes [12] and [15]
Value checked at index [12] = [61]
Value checked at index [13] = [62]
Value checked at index [14] = [76]
Value checked at index [15] = [99]
Found 999 at index: (nil)
```
***
**File:**
- File: `106-linear_skip.c`
</details>


<details>
<summary>14. Big O #6</summary>

What is the `time complexity` (average case) of a jump search in a singly linked list of size `n`, using `step = sqrt(n)`?

***
**File:**
- File: `107-O`
</details>


<details>
<summary>15. Big O #7</summary>

What is the `time complexity` (average case) of a jump search in a skip list of size `n`, with an express lane using `step = sqrt(n)`?

***
**File:**
- File: `108-O`
</details>
