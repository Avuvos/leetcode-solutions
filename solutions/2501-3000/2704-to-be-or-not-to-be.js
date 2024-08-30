/**
 * @param {string} val
 * @return {Object}
 */
var expect = function(val) {
    ans = {
        toBe: (value) => {
            if (value === val) {
                return true;
            }
            throw new Error ("Not Equal");
        },
        
        notToBe: (value) => {
            if (value !== val) {
                return true;
            }
            throw new Error ("Equal");
        }
        
    }
    return ans;
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */
