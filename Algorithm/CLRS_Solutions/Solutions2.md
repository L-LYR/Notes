## Exercise 2.1-1

Using Figure 2.2 as a model, illustrate the operation of INSERTION-SORT on the array A = 〈31, 41, 59, 26, 41, 58〉.
|31|41|59|26|41|58|
|---|---|---|---|---|---|
|31|41|59|26|41|58|
|31|41|59|26|41|58|
|26|31|41|59|41|58|
|26|31|41|41|59|58|
|26|31|41|41|58|59|

## Exercises 2.1-2

Rewrite the INSERTION-SORT procedure to sort into nonincreasing instead of nondecreasing order.

> ```pseudocode
> INSERTION-SORT(A)
> for j = 2 to A.length
> 	key = A[j]
> 	i = j - 1
> 	while i > 0 and A[i] < key
> 		A[i + 1] = A[i]
> 		i = i - 1
> 	A[i + 1] = key
> ```

## Exercises 2.1-3

Consider the searching problem:

Input: A sequence of n numbers A = 〈a1, a2, . . . , an〉 and a value v.

Output: An index i such that v = A[i] or the special value NIL if v does not appear in A.

Write pseudocode for linear search, which scans through the sequence, looking for v. Using a loop invariant, prove that your algorithm is correct. Make sure that your loop invariant fulfills the three necessary properties.

> ```pseudocode
> LINEAR-SEARCH(A, v)
> for i = 1 to A.length
> 	if A[i] == v
>       		return i
> return NIL
> ```

## Exercises 2.1-4

Consider the problem of adding two n-bit binary integers, stored in two n-element arrays A and B. The sum of the two integers should be stored in binary form in an (n + 1)-element array C. State the problem formally and write pseudocode for adding the two integers.

> INPUT: 
>
> A and B are integer arrays.
>
> $\forall i \in [1,n], A[i] , B[i]\in \{1,0\}$
>
> $A.length = B.length$
>
> OUTPUT:
>
> Integer array C
>
> $C.length = n+1$
>
> $\forall i \in [1,n], C[i]\in \{1,0\}$
>
> $\sum_{i=1}^{n+1}C[i]\times 2^{i-1}=\sum_{i=1}^{n}A[i]\times 2^{i-1}+\sum_{i=1}^{n}B[i]\times 2^{i-1}$
>
> 
>
> ```pseudocode
> BINARY-ADD(A, B)
> C = Array[A.length + 1]
> for i = A.length to 1
> 	C[i + 1] = (A[i] + B[i] + C[i]) % 2
> 	C[i] = (A[i] + B[i] + C[i]) / 2
> return C
> ```
>

## Exercises 2.2-1

Express the function $\frac{1}{1000}n^3 - 100n^2 - 100n + 3$ in terms of Θ-notation.

> $\Theta(n^3)$

## Exercises 2.2-2

Consider sorting n numbers stored in array A by first finding the smallest element of A and exchanging it with the element in A[1]. Then find the second smallest element of A, and exchange it with A[2]. Continue in this manner for the first n - 1 elements of A. Write pseudocode for this algorithm, which is known as selection sort. What loop invariant does this algorithm maintain? Why does it need to run for only the first n - 1 elements, rather than for all n elements? Give the best-case and worst-case running times of selection sort in Θ-notation.

> ```pseudocode
> SELECTION-SORT(A)
> for i = 1 to A.length - 1
> 	min = i
> 	for j = i + 1 to A.length
> 		if A[j] < A[min]
> 			min = j
> 	temp = A[min]
> 	A[min] = A[i]
> 	A[i] = temp		
> ```
>
> $\Theta (n^2)$
>
> After n - 1 times of loop, the last element left will be the largest, because the previous n - 1 elements are all the i-th smallest element in their loop.

## Exercises 2.2-3

Consider linear search again (see Exercise 2.1-3). How many elements of the input sequence need to be checked on the average, assuming that the element being searched for is equally likely to be any element in the array? How about in the worst case? What are the average-case and worst-case running times of linear search in Θ-notation? Justify your answers.

> Assuming that positions where the target appears in the array are of such possibility, we have $(1+2+\cdots +n)\times \frac{1}{n}=\frac{n+1}{2}$，while under the worst circumstance, this value will be $n$. They are both equal to $\Theta(n)$。

## Exercises 2.2-4

How can we modify almost any algorithm to have a good best-case running time?

> Though in the worst case, the algorithm will still give the right answer.

## Exercises 2.3-1

Using Figure 2.4 as a model, illustrate the operation of merge sort on the array A = 〈3, 41, 52, 26, 38, 57, 9, 49〉.

> ```mermaid
> graph TD
> A[3]
> B[41]
> C[52]
> D[26]
> E[38]
> F[57]
> G[9]
> H[49]
> A-->A1[3,41]
> B-->A1
> C-->A2[26,52]
> D-->A2
> E-->A3[38,57]
> F-->A3
> G-->A4[9,49]
> H-->A4
> A1-->B1[1,26,41,52]
> A2-->B1
> A3-->B2[9,38,49,57]
> A4-->B2
> B2-->C0[1,9,26,38,41,49,52,57]
> B1-->C0
> ```

## Exercises 2.3-2

Rewrite the MERGE procedure so that it does not use sentinels, instead stopping once either array L or R has had all its elements copied back to A and then copying the remainder of the other array back into A.

> ```pseudocode
> MERGE(A, p, q, r)
> n1 = q - p + 1
> n2 = r - q
> let L[1...n1] and R[1...n2] be new arrays
> for i = 1 to n1
> 	L[i] = A[p + i - 1]
> for i = 1 to n2
> 	R[i] = A[q + i]
> i = 1
> k = 1
> while i <= n1 and i <= n2
> 	if L[i] <= R[j]
> 		A[l + k] = L[i]
> 		i = i + 1
> 	else 
> 		A[l + k] = R[j]
> 		j = j + 1
> 	k = k + 1
> while i <= n1
> 	A[l + k] = L[i]
> 	k = k + 1
> 	i = i + 1
> while j <= n2
> 	A[l + k] = R[j]
> 	k = k + 1
> 	j = j + 1
> ```

## Exercises 2.3-3

Use mathematical induction to show that when n is an exact power of 2, the solution of the recurrence
$$
\begin{align}
T(n)=\begin{cases}
2 &if \ n=2
\\
2T(n/2)+n& if \ n = 2^k ,for\ k>1
\end{cases} 
\end{align}
$$
is $T(n)= n\lg n$.

> We have $n=2^k$, so if $k=1,T(2)=2=2\lg 2$. 
>
> Suppose that it is true for case $k=m$, we have $T(2^m)=2^m\lg 2^m=m2^m$. And we will show it is true for $k=m+1$.
> $$
> T(2^{m+1})=2T(2^m)+2^{m+1}=2m2^m+2^{m+1}=(m+1)2^{m+1}
> $$

Exercises 2.3-4
--- 
Insertion sort can be expressed as a recursive procedure as follows. In order to sort A[1...n], we recursively sort A[1...n -1] and then insert A[n] into the sorted array A[1...n-1]. Write a recurrence for the running time of this recursive version of insertion sort.

> $$
> T(n)=\begin{cases}
> \Theta(1)&n=1
> \\
> T(n-1)+O(n)&n>1
> \end{cases}
> $$

Exercises 2.3-5
---
Referring back to the searching problem (see Exercise 2.1-3), observe that if the sequence A is sorted, we can check the midpoint of the sequence against v and eliminate half of the sequence from further consideration. Binary search is an algorithm that repeats this procedure, halving the size of the remaining portion of the sequence each time. Write pseudocode, either iterative or recursive, for binary search. Argue that the worst-case running time of binary search is Θ(lg n).

>Suppose that the A is ascending.
>
>
>```pseudocode
>BINARY-SEARCH(A, v, l, r)
>if(l > r)
>	return NIL
>mid = (l + r) / 2
>if(A[mid] == v) 
>	return mid
>if(A[mid] > v)
>	return BINARY-SORT(A, v, mid + 1, r)
>else
>	return BINARY-SORT(A, V, l, mid)
>```
>
>From the psudocode above, we may see the initial question is divided into two parts whose scales are `[l, mid]` and `[mid+1, r]` respectively. So we have the recurrence $T(n)=T(n/2)+c$. Obviously, it shows that $T(n)\in \Theta(\lg n)$.

Exercises 2.3-6
---
Observe that the while loop of lines 5 - 7 of the INSERTION-SORT procedure in Section 2.1 uses a linear search to scan (backward) through the sorted sub-array A[1...j - 1]. Can we use a binary search (see Exercise 2.3-5) instead to improve the overall worst-case running time of insertion sort to  $n\Theta (\lg n)$?

> No. Though BINARY-SEARCH can find the accurate item in $\Theta (\lg n)$, but we still use $O(n)$ time to move elements.

## Exercises 2.3-7

Describe a Θ(n lg n)-time algorithm that, given a set S of n integers and another integer x, determines whether or not there exist two elements in S whose sum is exactly x.

> ```pseudocode
> FIND-TWO-SUM(A, n, S)
> MERGE-SORT(A, 0, n)
> i = 1
> j = n
> while i < j
> 	if(A[i] + A[j] == S)
> 		return true
> 	else if(A[i] + A[j] < S)
> 		i = i + 1
> 	else 
> 		j = j - 1
> return false
> ```
>
> Because MERGE-SORT will cost $\Theta(n \lg n)$ and the rest search procedure will cost $\Theta(n)$, the total running time is $\Theta(n \lg n)$.

Problems 2-1: Insertion sort on small arrays in merge sort
---
Although merge sort runs in $\Theta(n \lg n)$ worst-case time and insertion sort runs in $\Theta(n^2)$worst-case time, the constant factors in insertion sort make it faster for small $n$. Thus, it makes sense to use insertion sort within merge sort when subproblems become sufficiently small. Consider a modification to merge sort in which $n/k$ sublists of length $k$ are sorted using insertion sort and then merged using the standard merging mechanism, where $k$ is a value to be determined.

1. Show that the $n/k$ sublists, each of length $k$, can be sorted by insertion sort in $\Theta(nk)$ worst-case time.

2. Show that the sublists can be merged in $\Theta (n \lg(n/k))$ worst-case time.

3. Given that the modified algorithm runs in $\Theta (nk+n \lg(n/k))$ worst-case time, what is the largest asymptotic ($\Theta$notation) value of $k$ as a function of n for which the modified algorithm has the same asymptotic running time as standard merge sort?

4. How should $k$ be chosen in practice?

