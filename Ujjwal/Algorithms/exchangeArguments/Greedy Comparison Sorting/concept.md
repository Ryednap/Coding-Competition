# **Overview**

In some problem we can solve the problem by custom sorting. Where the sorting criteria is actually based on greedy approach. How ?
Well note that if the solution of the sub-problem of greedy is optimal then the whole greedy solution is optimal. So, If we have to order two things, and we don't know which will come first, then we can check the both the order for the cost and then determine the optimal one.

**PS** :- For example look at **UVA 11269 Setting Problem** and **UVA 11729 Commando War**.

## Solution

Calculate the Cost(A, B) and Cost(B, A) and then choose the order which is optimal.