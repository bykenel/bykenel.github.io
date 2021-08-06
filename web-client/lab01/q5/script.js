function numPrime(i) {
    for (var div = 2; div < i; div++) 
        if (i % div == 0) { 
            return false;
        }
        return true;
}

for (var i = 2; i < 1000; i++) 
    if (numPrime(i)) {
        console.log(i)
    }