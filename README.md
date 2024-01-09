# Accepted Solutions

This repository contains my accepted solutions of programming problems from different online judges.

## UVA Online Judge
*   [167 	The Sultan's Successors][0]  
    > No need to backtrack for each test case. Just pre-computing the EQS matrix and using it is enough.  

***

*   [624 	CD][1]  

*   [729 	The Hamming Distance Problem][2]  
    > Variation of subset generation.  

***
    
*   [10452 	Marcus][3]
    > I think it would be a better flagship problem for recursive backtracking with pruning where the output sequence is given. A pre-order dfs solution is also possible. Start with the position of '@' and traverse forth, left or right. Recursively hop to the square with next required letter and save the move, otherwise reject that move and check for the next move. Stop traversing when '#' is found. Print all the saved moves.   

    > Note that, this problem similar to 8-Queen varification problem. Suppose, you are given a solution of 8-Queen composition problem. How can you varify the solution?

    > This is a linear time solution.  

***

*   [524 	Prime Ring Problem][4]
    > No need to precompute all solutions. Don't check primes by any sub procedure, rather use precomputed boolean array. You can store all primes in [2 100], but [2  37] is enough.  
    
    > Printing solution is little tedious. Storing all the input before processing is an effective idea. 


***

*   [574 	Sum It Up][5]
    > Variant of subset sum solution. Generate all subsets and take subsets that sum to a given target.

***

## CSES
*   [Two Sets][6]
    > Two Sets is a fine problem. The task is to create two sets with numbers in the range $[1\ n]$ of equal sum if possible, otherwise, print "NO". Checking the possibility is straight forward. If $S$, the sum of all numbers in range $[1\ n]$ is even, then the partition is possible otherwise NOT. The condition can be further simplified for $n$. if $n$ is in the form $n = 4k$ or $n = 4k - 1$ for any $k>0$ then the partition is possible.  
    > Also the problem asks to print any valid partition. There are number of ways to do so. We can use the following two facts. My solution uses fact A.  


    > **A. Any number can be expressed as the sum of 2's power.**  

    > **B. For any four consecutive integers, the sum of first and fourth integer is equal to the sum of second and third integers.**  
    > Of course we can use **Subset Sum** technique to find a set of integers summed up to $S$. But for larger value of $n$ the solution will get a TLE.  

    > Be careful about integer size (memory) if you are using C/C++.  


[0]: /uva/uva_00167_the_sultan_successor.cpp
[1]: /uva/uva_00624_CD.cpp
[2]: /uva/uva_00729_the_hamming_distance.cpp
[3]: /uva/uva_10452_Marcus.cpp
[4]: /uva/uva_00524_prime_ring_problem.cpp
[5]: /uva/uva_574_sum_it_up.cpp
[6]: /cses/cses_Two_Sets.py
