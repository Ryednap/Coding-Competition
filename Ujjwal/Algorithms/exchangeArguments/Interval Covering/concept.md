# **Interval Covering Problem**

## Problem Description

Given a set $(S = {[a_1, b_1], [a_2, b_2], ......, [a_n, b_n]})$ we define the cover set $C = {[l_1, r_1], [l_2, r_2], ....., [l_n, r_n]}$ if and only if $C \subset S$ <br />
**i.e** $\forall [a_i, b_i]$ , $i <= n$ $\exists$ $[l_j, r_j]$ in $C$ such that $l_j <= a_i, r_j >= b_i$

Now Find such such set with minimum cardinality.


## Solution

Let's try find a greedy algorithm and then later we will prove that it is the most optimal we can get. Hence the greedy stands here.

Let's sort the intervals by their left points and in case of tie sort them by right points. So that, 

Now, $(S = {[a_1, b_1], [a_2, b_2], ......, [a_n, b_n]})$, then 
$a_1 <= a_2 <= a_3 ... <= a_n$, and iff $a_1 == a_2$ then $b_1 >= b_2$.


Now we will pick the most leftmost one, and then for the next one we will pick the one whose left point intersects with the previous one and has the longest end point.

This is the most optimal solution.


## Proof

We will use exchange argument.

Let $G = [g_1, g_2, g_3, ... g_m]$ be our greedy solution <br />
and $O* = [o_1, o_2, o_3, ...., o_n]$ be the most optimal <br />

Then by the law of optimality we know then $n <= m$, but here for our greedy to work $n = m$ is must.

**Some quick Oberservation**

*   left of $g_1$ is the most leftomost we can get
*   left of $g_2$ is less than right of $g_1$, i.e they intersect
*   right of $g_i$ is the longest among all valid one.

Now keeping above oberservations in mid, <br />

* We know that, left of $g_1$ == left of $o_1$ <br />

**Reason :-** By the property we know $g_1$ is the most leftmost that will cover our leftmost of $S$, it can't be true simultaneously than $g_1 \neq o_1$ and $O*$ is optimal.

* Know right of $g_1$ $<=$ right of $o_1$, but we know that right of $g_1$ is the most longest of all the starting points so, infact right of $g_1$ = right of $o_1$
* Hence $g_1 == o_1$, i.e we can exchange both and still be the same
* By induction We have proved that our solution is indeed same as the optimal one.



HENCE PROVED.