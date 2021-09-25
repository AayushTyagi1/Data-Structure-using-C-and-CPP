/*
Problem Description:
Agarwal has a habit of creating Ajeeb Samasya as usual and Shubham always comes to his rescue. 
This is time he has created another samasya which is as follows. Read carefully! 
Shubham has an array of N integers and an integer K. He wants to create a subsequence of 
this array with some conditions applied. 
He builds ceil(N/K) blocks of this array with size of each block as [i∗K+1,min((i+1)∗k,N)] 
for 0≤i≤N/K. For two consecutive integers in this subsequence, 
he wants the integers to be of two different blocks. 
(It is not a compulsion to have one integer from each block).
 Also, lets say the indexes of any two integers of this subsequence be i and j, 
 then he wants |i−j| != K. Shubham takes the sum of integers in the subsequence.
  He wonders what can be the maximum sum obtained? Help shubham in this samasya.

Input Format: First line contains two space separated integers : N and K 
Second line contains N space separated integers : A1, A2,…, AN
Sample Input: 6 5
5 4 3 2 1 -1
Output Format: print a single integer describing maximum sum that can be obtained.
Sample Output: 5
*/