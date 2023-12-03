# Accepted Solutions

This repository contains my accepted solutions of programming problems from different online judges.

## UVA Online Judge
*   [167 	The Sultan's Successors][0]  
    > No need to backtrack for each test case. Just pre-computing the EQS matrix and using it is enough.  

*   [624 	CD][1]  

*   [729 	The Hamming Distance Problem][2]  
    > Variation of subset generation.  
    
*   [10452 	Marcus][3]
    > I think it would be a better flagship problem for recursive backtracking with pruning where the output sequence is given. A pre-order dfs solution is also possible. Start with the position of '@' and traverse forth, left or right. Recursively hop to the square with next required letter and save the move, otherwise reject that move and check for the next move. Stop traversing when '#' is found. Print all the saved moves.   

    > Note that, this problem similar to 8-Queen varification problem. Suppose, you are given a solution of 8-Queen composition problem. How can you varify the solution?

    > This is a linear time solution.        


***

[0]: /uva/uva_00167_the_sultan_successor.cpp
[1]: /uva/uva_00624_CD.cpp
[2]: /uva/uva_00729_the_hamming_distance.cpp
[3]: /uva/uva_10452_Marcus.cpp


