function numberPrime (i) {
    for (let div = 2; div < i; div++) 
        if (i % div == 0) { 
            return false;
        }
        return true;
}

for (let i = 2; i < 1000; i++) 
    if (numberPrime (i)) {
        console.log (i)
    }