class Solution:
    def isValid(self, s: str) -> bool:
        stack = list()
        
        for ch in s:
            if ch is '(':
                stack.append(')')
            elif ch is '[':
                stack.append(']')
            elif ch is '{':
                stack.append('}')
            else:
                if ch is not ')' and ch is not ']' and ch is not '}':
                    continue
                elif not stack or stack[-1] != ch:
                    return False
                else:
                    stack.pop()
        
        return not stack