/**
 * @return {Generator<number>}
 */

var fibGenerator = function*() {
    yield 0;
    yield 1;
    let prev1=0,prev2=1,cnt=1; 
    while(true){
        let ans=prev1+prev2;
        prev1=prev2;
        prev2=ans;
        yield ans;
    }
};

/**
 * const gen = fibGenerator();
 * gen.next().value; // 0
 * gen.next().value; // 1
 */
