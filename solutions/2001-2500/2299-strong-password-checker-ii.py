
class Solution:
    def strongPasswordCheckerII(self, password: str) -> bool:
        if len(password) < 8: return False
        if not any(c.isupper() for c in password): return False
        if not any(c.islower() for c in password): return False
        if not any(c.isdigit() for c in password): return False
        lst = ["!", "@" ,"#", "$", "%","^", "&", "*", "(", ")", "-" ,"+"]
        if not any(c in password for c in lst): return False
        for i in range(1, len(password)):
            if password[i] == password[i - 1]:
                return False
        return True
    
