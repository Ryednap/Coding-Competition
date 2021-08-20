# **Solutions to the problem**

**A** :-  It's an easy greedy problem. We need to replace all the  elements **$a_i > k$**, and the only operation allowed is replacement by some **$a_k + a_j$**. Now suppose the above condition exist then pick the smallest two number and if those two are less than k , then we can make any wrong sequence correct else never and ever.
**Note** :- (If the sequence is already correct we don't need to do , Checking this condition on some correct sequence can also leads to WA)


**B** :- Actually it can also be done with the brute force approach just try upto 20 and you are done, but still i got 2 TLE's **(Because i had smoked and was using DP xD)** . Now Suppose we have two strings **s** and **t**, with **$|s| = a$** and **$|t| = b$** , then if the strings are not equal even after copying for **$lcm(a,b)$** times then we are done bro. Reason , After the lcm we will repeating the sequence . **Note** Special case if **gcd(a,b) = 1**, then we can append b copies of **s** and a copies **s** and check.

**C** :- One of the most interesting constructive problem. I will start with proof only.

![proof.jpeg]()

So as you can see it doesn't matter what the elements are , and not what the order in which they are the number of inversion in palindromic sequence always remains the constant. Now for the problem we don't have complete palindrome sequence , so keep the non-palindromic elements as it is on it's position and then we can reverse starting from the palindromic sequence.

**D** : **Recommended problem for the range type problem. This can be solved using data - structres and all but this is nice trick solution for this king of problem.

![idea.jpg]()

So the idea is clear and is simple is'nt it so all we need to do as pre-computation is to store the **lo and hi** for each suffix. Now get all the query of the form **[l, r]** and then sort them according to **l**  **(Actually this is done to avoid using prefix array)**. Now keep on storing **lo and hi** up-to-here. and then for the **SECOND** range, **suffix[r]**, **also note that t here should be taken as (r - 1)th element**, because if the lo or hi is **$r^(th)$** element then we get wrong answer.

