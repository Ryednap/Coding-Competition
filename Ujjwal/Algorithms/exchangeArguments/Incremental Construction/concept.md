# **A very Famous Puzzle**

## **Overview**

There's a very nice puzzle. Suppose we have N people wanting to cross a bridge. Each member has different crossing time. Also we have only one flashlight. And the whole environment is dark. Atmost 2 people with one flashlight carrier can move back-and forth. We want all the N people to be on the other side of the bridge in the most minimum time.

## **Solution**

Well the solution which i coded is based on Incremental Optimization. Although I dont' have any formal proof. But the idea goes like,

Image we have two Set based on two side of the bridge $S_l$ and $S_r$. Now intitally $S_r$ = {a,b, c, d, e}, where $a < b < c < d < e$. <br />

The process start with two people moving from $S_r$ and then like single guy moving (*because the one that has moved to $S_l$ has to carryback the falshlight*) and then ends with two people moving.

In general, the operation can be mathematically represented as $\sum S_r$ - {A} - {B} + $min(S_l, A, B)$. So we will choose the operation that minimises the above function.

The function is the total time in operation, so in short we are choosing the one that has current minimum time via set inclusion/exclusion (Incremental Optimization).