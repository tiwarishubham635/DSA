Detect loop in LL:
Take a fast pointer which moves by two at a time and a slow pointer which moves by one at a time. When slow == fast => loop detected. If no loop, speed of fast = 2* speed of slow. So they can't be equal.
The point where slow = fast is the meeting point. To find the starting point of the loop. Take a pointer at start (P1) of linked list and another at the meeting point (p2). 
For slow, it travels N nodes. If distance of Start of loop from start of linked list is D and the distance between start of loop and meeting point is k, then :
For slow:
N = D+K+Ci
where C is the no. of nodes in the loop and i is the no. of rotations of loop completed by slow
Similarly for fast:
2N = D+K+Cj
where Fast has completed j rotations of the loop. 
From these equations, we get:
D = (j-2i)C - K
So, the distance between the start of the linked list and Start of loop is the same as the distance from the meeting point in the loop falling short by k.
So, move P1 and P2 one by one and the point where they meet is the start of the loop.
