/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let v = init;
    return {
        increment: function() {
            return ++v;
        },
        decrement: function() {
            return --v;
        },
        reset: function() {
            return v = init;
        },
    }
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */
