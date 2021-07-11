class Solution:
    def addBinary(self, a: str, b: str) -> str:
        
        
        def add(bin1, bin2):
            added_str = ""
            new_small_bin = "" #creating new strings instead of changing bin1 and bin2
            new_big_bin = ""
            carry = '0'
            n = 0
            if len(bin1) > len(bin2): #the idea here is to check which str is longer
                                      #and to the shorter one we just add zeroes
                n = len(bin1)
                for x in range(0, n-len(bin2)):
                    new_small_bin = new_small_bin + '0'
                new_small_bin = new_small_bin + bin2
                new_big_bin = bin1
            else:
                n = len(bin2)
                for y in range(0, n-len(bin1)):
                    new_small_bin = new_small_bin + '0'
                new_small_bin = new_small_bin + bin1
                new_big_bin = bin2
                
            for i in range(n-1, -1, -1): #now we will check all the possible options
                                 #and add the 0 or 1 according to the case
                if carry == '0':
                    if (new_small_bin[i] == '0' and new_big_bin[i] == '1') or (new_big_bin[i] == '0' and new_small_bin[i] == '1'):
                        added_str = added_str + '1'  
                    if (new_small_bin[i] == '0' and new_big_bin[i] == '0'):
                        added_str = added_str + '0'
                    if (new_small_bin[i] == '1' and new_big_bin[i] == '1'):
                        added_str = added_str + '0'
                        carry = '1' #both ones so we add zero and make carry=1
                else:
                    if (new_small_bin[i] == '0' and new_big_bin[i] == '1') or (new_big_bin[i] == '0' and new_small_bin[i] == '1'):
                        added_str = added_str + '0'  
                    if (new_small_bin[i] == '0' and new_big_bin[i] == '0'):
                        added_str = added_str + '1'
                        carry = '0' #both zeroes and we have carry, so add 1 and reset carry
                    if (new_small_bin[i] == '1' and new_big_bin[i] == '1'):
                        added_str = added_str + '1' #both ones and we have carry so add one


            if carry == '1': 
                added_str = added_str + '1'
        
            return added_str[::-1]                
        
        return add(a, b)
