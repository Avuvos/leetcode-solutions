class Solution:
    def interpret(self, command: str) -> str:
        msg = ""
        
        for i in range(len(command)):
            if command[i] == "G":
                msg += "G"
            elif command[i] == "(":
                if command[i+1] ==  ")":
                    msg += "o"
                else:
                    msg += "al"
        return msg
