Determine the vertical order traversal and add the first root with new horizontal distance in the top view.
Vertical order is printing nodes according to their horizontal distance from the root. So horizontal distance of root = 0, and for any child:
Horizontal distance of left child = Horizontal distance of parent - 1
Horizontal distance of right child = Horizontal distance of parent + 1
So, maintain a map of horizontal distance and keep pushing the nodes having that value as horizontal distance.
