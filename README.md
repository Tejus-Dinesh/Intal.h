# Intal.h
**Introduction**
Intal.h is a library, which handles integers of arbitrary length. An intal is a nonnegative integer of arbitrary length. The integer is stored as a null-terminated string of ASCII characters, in Big-Endian style. There are no leading zero intals.        In C, the int data type (integers), has certain limitations, when it comes to the size of the number it can hold. We can use long int or long long int data type, but even those data types can’t hold numbers which have more than 19 digits. Therefore in these cases we can use intals, where the number is stored as an array of characters. Intal can store any length because the  array size is not limited.
This finds application in many fields such as cosmology, astronomy, mathematics, cryptography, and statistical mechanics. In the field of cryptography and cybersecurity, larger numbers are combined in certain combinations which are hard to decode, and hence provide a layer of security. In the field of astronomy, the distance between two celestial bodies, calculations of the rockets to send to a particular orbit, they all are complex calculations with large numbers, which can be achieved with intals. The lower bound on the game-tree complexity of chess, also known as the "Shannon number" , is one such large number example, which can be used in other calculations, with the use of intals.
IMPLEMENTATION OF FUNCTIONS
1. Intal_add
   1. The smaller number is iterated first, and the corresponding numbers from both the intals are added.
   2. Then the larger number is iterated to add the remaining digits.
   3. If there is a carry at last, that is added to the final answer
   4. The final string is then reversed for the correct answer and returned.
2. Intal_compare
   1. The function checks the length of the intals, the one with the larger length is greater than the other.
   2. If the lengths are the same, function iterates through every character,and checks each character when one of the ascii values is greater than the second string then  returns +1  and if it less then returns -1
   3. Returns 0 if both the intals are the same.
3. Intal_diff
   1. Determines which of two intals passed is greater through intal_compare.
   2. Iterates through the smaller number, and subtract corresponding characters(after converting to int)
   3. If the value(x) is negative at any point, then 10 is added to x, and the value to the left of the number is reduced by 1 until a non-negative number is found after subtracting 1.
   4. The remaining numbers of the larger number are copied as it is, into the answer string.
   5. The final answer is reversed and stripped of  leading 0, before returning.
4. Intal_multiply
   1. Start from the last digit of the second number and multiply it with the first number. Then we multiply the second digit of the second number with the first number, and so on. We add all these multiplications. While adding, we put i-th multiplication shift.
   2. Finally leading zeros are stripped before returning.
5. Intal_pow
   1. Log n implementation 
   2. Initially the result is 1.
   3. When power is even, the base is squared(using the intal_multiply function), and the power is halved.
   4. When power is odd, the base is multiplied with previous result value, and power is reduced by 1.
6. Intal_mod
   1. This function is to find the mod of two numbers. If the intal1 is less than intal2 then answer is intal1.
   2. Finds remainder using long division method.
7. Intal_gcd
   1. Function uses Euclid’s Algorithm, to calculate GCD of two numbers.
   2. Follows the recursive version of the following algorithm to find the GCD of two numbers.
   3. Recursive function, until one of the two intals is 0
8. Intal_min
   1. Assumes the first intal as minimum and traverses through the array, if any intal less than the assumed intal is found, that is made the new minimum and traversal continues till the end.
   2. Returns the offset of the first occurence maximum at the end of the traversal of the array.
9. Intal_max
   1. Assume the first intal as maximum and traverse through the array, if any intal is more than the assumed intal is found, that is made the new maximum and traversal continues till the end.
   2. Returns the offset of the first occurrence of the maximum at the end of the traversal of the array.
10. Intal_sort
    1. The function is implemented using heap sort, which is an inplace sorting technique, which takes O(n log n) time.
    2. Build a max heap from the input array. The largest item is stored at the root of the heap. Replace it with the last item of the heap followed by reducing the size of the heap by 1.Finally, heapify the root of the tree.Repeat above steps until the size of the heap is greater than 1.
11. Intal_search
    1. It traverses through the entire array comparing each intal of the array with the key.
    2. Function calls  intal_compare to compare two intals.
    3. Returns the offset of the first occurence of the key in the array.
    4. Returns -1 if not found.
12. Intal_binsearch
    1. O(log n) implementation of binary search, where the sorted array is passed, with the key.
    2. The array is split into halves, in order to reduce the number of iterations.
    3. To get the first occurence initialize offset as -1 and keep comparing the middle term of the array  and the key if mid element in the array is less than key then make end index as mid - 1
    4. If mid element in the array is greater than key then make start as mid+1
    5. If both are equal then make the answer as that index and end as mid-1 to get the first occurence in the binary search.
    6. Return -1 if key not found.
13. Intal_fibonacci
    1. Two pointers are taken for the first two numbers of the fibonacci series 0 and 1(fib_a,fib_b)
    2. Looping till n, we add fib_a and fib_b using Intal_add.
    3. Fib_a and FIb_b is updated accordingly for the iterations.
14. Intal_factorial
    1. Function iterates from 1 to n, multiplying at each stage
    2. Two pointers, (start, step), start is the first pointer, and step pointer updates the start pointer using intal_add.
15. Intal_bincoeff
    1. The value of C(n, k) can be recursively calculated using the following standard formula for Binomial Coefficients.
C(n, k) = C(n-1, k-1) + C(n-1, k) .
    2. Using Dynamic Programming, the function  can run  in O(n) time and O(k) space, by checking k and n-k.
    3. If k is greater than n- k,  then k = n-k;
16. Coin_row_problem
    1. This is solved using the dynamic programming approach, in O(n)
    2.  The basic case being that in an array,  if there is only a coin of a particular value then it is the maximum value.
    3.  For the nth type of coin it's effect with the maximum value is checked. If it is greater than the maximum value obtained in the previous case it is updated, else the previous maximum value is maintained.
Future Work
1. Intals can be extended to negative numbers
2. Functions such as division, square root, cube root, LCM can be implemented.
