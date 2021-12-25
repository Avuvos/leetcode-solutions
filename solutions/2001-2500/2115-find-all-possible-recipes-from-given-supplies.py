class Solution:
    def findAllRecipes(self, recipes: List[str], ingredients: List[List[str]], supplies: List[str]) -> List[str]:
        res = set()
        supplies = set(supplies)
        found = True
        while found:
            found = False
            for i, recp in enumerate(recipes):
                if recp in res:
                    continue
                need = ingredients[i]
                foundThis = True
                for ing in need:
                    if ing not in supplies:
                        foundThis = False
                        break
                if not foundThis:
                    continue
                found = True
                res.add(recp)
                supplies.add(recp)
        return list(res)
            
        #LOL THIS ALGO WORKS 112/112 BUT SAYS IT TOOK TOO LONG XDXD
            
        
