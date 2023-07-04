# Sorting QuickSelect, Quicksort, Selection
This project focuses on finding the kth smallest element in an array using three different algorithms: SELECT1, SELECT2, and SELECT3. The algorithms are compared based on their performance in terms of the number of key comparisons. The project provides implementations and analysis for each algorithm, along with experiments using different values of n (10,000, 100,000, and 1,000,000) and randomly generated arrays. The goal is to determine the kth smallest element for k = n/2 and display the results, including the algorithm used, n, k, A[k], and the number of key comparisons.

Note:

The SELECT1 algorithm utilizes Quicksort to sort the array and find the kth smallest element.
The SELECT2 algorithm applies randomized selection, also known as Quickselect, with special considerations for arrays with n < 25.
The SELECT3 algorithm adopts a selection algorithm with linear worst-case time, using the median of medians as a pivot for partitioning.
The project performs experiments and reports the results for different values of n, providing insights into the performance of each algorithm.
