"""
# Definition for a Node.
class Node:
    def __init__(self, val, next, random):
        self.val = val
        self.next = next
        self.random = random
"""
class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        if head is None:
            return None
        
        curr = head
        while curr:
            tmp = curr.next
            curr.next = Node(curr.val, None, None)
            curr.next.next = tmp
            curr = tmp
        
        curr = head
        while curr:
            if curr.random:
                curr.next.random = curr.random.next
            curr = curr.next.next
            
        newH, prev, curr = head.next, head, head.next
        while prev:
            prev.next = prev.next.next
            prev = prev.next
            
            curr.next = prev.next if prev else None
            curr = curr.next
        
        return newH