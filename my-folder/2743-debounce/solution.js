/**
 * @param {Function} fn
 * @param {number} t milliseconds
 * @return {Function}
 */
var debounce = function(fn, t) {
    let timeoutId; // to store the current timeout
    return function(...args) {
        clearTimeout(timeoutId); // cancel previous call if it exists
        timeoutId = setTimeout(() => {
            fn(...args); // call the function with the arguments after delay
        }, t);
    };
};

