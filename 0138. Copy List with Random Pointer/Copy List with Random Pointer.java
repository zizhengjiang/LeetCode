/*
// Definition for a Node.
class Node {
    public int val;
    public Node next;
    public Node random;

    public Node() {}

    public Node(int _val,Node _next,Node _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
    public Node copyRandomList(Node head) {
        if (head == null) return null;
        Node old = head;
        
        while (old != null) {
            Node tmp = old.next;
            old.next = new Node(old.val);
            old.next.next = tmp;
            old = tmp;
        }
        
        old = head;
        
        while (old != null) {
            if (old.random != null) old.next.random = old.random.next;
            old = old.next.next;
        }
        
        Node res = head.next, cur = head;
        old = head.next;
        
        while (cur != null) {
            cur.next = cur.next.next;
            cur = cur.next;
            
            old.next = cur != null ? cur.next : null;
            old = old.next;
        }
        
        return res;
    }
}